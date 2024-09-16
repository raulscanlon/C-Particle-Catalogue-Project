// Photon.h - Defines the Photon class derived from Boson.
// Author: Raul Scanlon, Date: 26/05/2024

#ifndef PHOTON_H
#define PHOTON_H

#include "Boson.h"

// Derived class for Photons
class Photon : public Boson {
public:
  Photon(const FourMomentum& momentum)
    : Boson(0, 1, momentum, 0) {}

  // Copy constructor
  Photon(const Photon& other)
    : Boson(other) {}

  // Override print method to display Photon properties
  void print() const override {
    std::cout << "Photon: Charge = " << getCharge() << ", Spin = " << getSpin()
              << ", Rest Mass = " << getRestMass() << ", Momentum = " << getFourMomentum() << std::endl;
  }

  std::string getTypeName() const override { return "Photon"; }

  double getCharge() const override { return charge; }
  double getSpin() const override { return spin; }
  FourMomentum getFourMomentum() const override { return momentum; }
  double getRestMass() const override { return restMass; }
};

#endif // PHOTON_H
