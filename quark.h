// quark.h - Defines the Quark class, derived from Particle.

#ifndef QUARK_H
#define QUARK_H

#include "Particle.h"
#include <string>
#include <iostream>

// Derived class for Quarks
class Quark : public Particle {
public:
  Quark(double charge, double spin, double baryonNumber, const std::string& colour, const FourMomentum& momentum, double restMass, const std::string& name, bool isAntiparticle = false)
      : Particle(charge, spin, momentum, restMass, isAntiparticle), baryonNumber(baryonNumber), colourCharge(colourCharge), name(name) {}

  // Copy constructor
  Quark(const Quark& other)
    : Particle(other), baryonNumber(other.baryonNumber), colourCharge(other.colourCharge), name(other.name) {}

  // Move constructor
  Quark(Quark&& other) noexcept
    : Particle(std::move(other)), baryonNumber(other.baryonNumber), colourCharge(std::move(other.colourCharge)), name(std::move(other.name)) {}

  // Copy assignment operator
  Quark& operator=(const Quark& other) {
    if (this != &other) {
      Particle::operator=(other);
      baryonNumber = other.baryonNumber;
      colourCharge = other.colourCharge;
      name = other.name;
    }
    return *this;
  }

  // Move assignment operator
  Quark& operator=(Quark&& other) noexcept {
    if (this != &other) {
      Particle::operator=(std::move(other));
      colourCharge = std::move(other.colourCharge);
      name = std::move(other.name);
    }
    return *this;
  }

  // Destructor
  ~Quark() override = default;

  // Override print method to display Quark properties
  void print() const override {
    std::cout << "Quark: Name = " << name << ", Charge = " << charge << ", Spin = " << spin
              << ", Baryon Number = " << baryonNumber << ", colour Charge = " << colourCharge
              << ", Rest Mass = " << restMass << ", Momentum = "
              << "E: " << momentum.getEnergy() << ", px: " << momentum.getPx()
              << ", py: " << momentum.getPy() << ", pz: " << momentum.getPz()
              << std::endl;
  }

  double getCharge() const override { return charge; }
  double getSpin() const override { return spin; }
  FourMomentum getFourMomentum() const override { return momentum; }
  std::string getTypeName() const override { return "Quark"; }
  double getBaryonNumber() const override { return baryonNumber; }
  std::string getcolourCharge() const { return colourCharge; }
  double getRestMass() const override { return restMass; }

private:
  double baryonNumber;
  std::string colourCharge;
  std::string name;
};

#endif // QUARK_H
