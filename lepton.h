// lepton.h - Defines the Lepton class, derived from Particle.

#ifndef LEPTON_H
#define LEPTON_H

#include "Particle.h"
#include <string>
#include <iostream>

// Derived class for Leptons
class Lepton : public Particle {
public:
  Lepton(double charge, double spin, int leptonNumber, const FourMomentum& momentum, double restMass, const std::string& name, bool isAntiparticle = false)
    : Particle(charge, spin, momentum, restMass, isAntiparticle), leptonNumber(leptonNumber), name(name) {}

  // Copy constructor
  Lepton(const Lepton& other)
    : Particle(other), leptonNumber(other.leptonNumber), name(other.name) {}

  // Move constructor
  Lepton(Lepton&& other) noexcept
    : Particle(std::move(other)), leptonNumber(other.leptonNumber), name(std::move(other.name)) {}

  // Copy assignment operator
  Lepton& operator=(const Lepton& other) {
    if (this != &other) {
      Particle::operator=(other);
      leptonNumber = other.leptonNumber;
      name = other.name;
    }
    return *this;
  }

  // Move assignment operator
  Lepton& operator=(Lepton&& other) noexcept {
    if (this != &other) {
      Particle::operator=(std::move(other));
      leptonNumber = other.leptonNumber;
      name = std::move(other.name);
    }
    return *this;
  }

  // Destructor
  ~Lepton() override = default;

  // Override print method to display Lepton properties
  void print() const override {
    std::cout << "Lepton: Name = " << name << ", Charge = " << charge
              << ", Spin = " << spin << ", Lepton Number = " << leptonNumber
              << ", Rest Mass = " << restMass << ", Momentum = "
              << "E: " << momentum.getEnergy() << ", px: " << momentum.getPx()
              << ", py: " << momentum.getPy() << ", pz: " << momentum.getPz()
              << std::endl;
  }

  double getCharge() const override { return charge; }
  double getSpin() const override { return spin; }
  FourMomentum getFourMomentum() const override { return momentum; }
  double getRestMass() const override { return restMass; }
  std::string getTypeName() const override { return name; }

protected:
  int leptonNumber;
  std::string name;
};

#endif // LEPTON_H
