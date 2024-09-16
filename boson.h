// Boson.h - Defines the Boson class derived from Particle.
// Author: Raul Scanlon, Date: 27/05/2024

#ifndef BOSON_H
#define BOSON_H

#include "Particle.h"

// Derived class for Bosons
class Boson : public Particle {
public:
  Boson(double charge, double spin, const FourMomentum& momentum, double restMass, bool isAntiparticle = false)
    : Particle(charge, spin, momentum, restMass, isAntiparticle) {}

  // Copy constructor
  Boson(const Boson& other)
    : Particle(other) {}

  // Move constructor
  Boson(Boson&& other) noexcept
    : Particle(std::move(other)) {}

  // Copy assignment operator
  Boson& operator=(const Boson& other) {
    if (this != &other) {
      Particle::operator=(other);
    }
    return *this;
  }

  // Move assignment operator
  Boson& operator=(Boson&& other) noexcept {
    if (this != &other) {
      Particle::operator=(std::move(other));
    }
    return *this;
  }

  // Destructor
  ~Boson() override = default;

  // Override print method to display Boson properties
  virtual void print() const override {
    std::cout << "Boson: Charge = " << getCharge() << ", Spin = " << getSpin()
              << ", Rest Mass = " << getRestMass() << ", Momentum = " << getFourMomentum() << std::endl;
  }

  // Pure virtual functions to be implemented by derived classes
  virtual std::string getTypeName() const override = 0;
};

#endif // BOSON_H
