// particle.h - Defines the abstract base class Particle.
// Author: Raul Scanlon, Date: 26/05/2024

#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <memory>
#include <string>
#include "FourMomentum.h"
#include <stdexcept>
#include <cmath>

// Abstract base class for all particles
class Particle {
public:
  virtual ~Particle() = default;

  // Pure virtual functions to be overridden by derived classes
  virtual void print() const = 0;
  virtual double getCharge() const = 0;
  virtual double getSpin() const = 0;
  virtual FourMomentum getFourMomentum() const = 0;
  virtual std::string getTypeName() const = 0;
  virtual int getLeptonNumber() const { return 0; }
  virtual double getBaryonNumber() const { return 0.0; }
  virtual double getRestMass() const = 0;

  // Method to validate particle properties
  virtual void validate() const {
    // Allow valid charge values: -1, 0, 1, and valid fractional charges for quarks
    if (charge != -1 && charge != 0 && charge != 1 &&
        std::abs(charge - 2.0/3.0) > 1e-6 && std::abs(charge + 2.0/3.0) > 1e-6 &&
        std::abs(charge - 1.0/3.0) > 1e-6 && std::abs(charge + 1.0/3.0) > 1e-6) {
      throw std::invalid_argument("Invalid charge value");
    }
  }

  // Method to check if the invariant mass matches the particle's rest mass
  virtual void checkInvariantMass() const {
    double invariantMass = momentum.invariantMass();
    if (std::abs(invariantMass - restMass) > 1e-6) {
      std::cerr << "Invariant mass does not match particle rest mass. "
                << "Invariant Mass: " << invariantMass << ", Rest Mass: " << restMass << std::endl;
    }
  }

protected:
  Particle(double charge, double spin, const FourMomentum& momentum, double restMass, bool isAntiparticle = false)
    : charge(isAntiparticle ? -charge : charge), spin(spin), momentum(momentum), restMass(restMass) {
      validate();
      checkInvariantMass();
  }

  // Copy constructor
  Particle(const Particle& other)
    : charge(other.charge), spin(other.spin), momentum(other.momentum), restMass(other.restMass) {}

  // Move constructor
  Particle(Particle&& other) noexcept
    : charge(other.charge), spin(other.spin), momentum(std::move(other.momentum)), restMass(other.restMass) {}

  // Copy assignment operator
  Particle& operator=(const Particle& other) {
    if (this != &other) {
      charge = other.charge;
      spin = other.spin;
      momentum = other.momentum;
      restMass = other.restMass;
    }
    return *this;
  }

  // Move assignment operator
  Particle& operator=(Particle&& other) noexcept {
    if (this != &other) {
      charge = other.charge;
      spin = other.spin;
      momentum = std::move(other.momentum);
      restMass = other.restMass;
    }
    return *this;
  }

  double charge;
  double spin;
  FourMomentum momentum;
  double restMass;
};

#endif // PARTICLE_H
