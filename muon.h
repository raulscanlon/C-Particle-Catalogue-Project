// Muon.h - Defines the Muon class derived from Lepton.
// Author: Raul Scanlon, Date: 26/05/2024

#ifndef MUON_H
#define MUON_H

#include "Lepton.h"

// Derived class for Muons
class Muon : public Lepton {
public:
  Muon(double charge, double spin, int leptonNumber, const FourMomentum& momentum, double restMass, bool isolation, bool isAntiparticle = false)
    : Lepton(charge, spin, leptonNumber, momentum, restMass, "Muon", isAntiparticle), isolation(isAntiparticle ? !isolation : isolation) {}

  // Copy constructor
  Muon(const Muon& other)
    : Lepton(other), isolation(other.isolation) {}

  // Override print method to display Muon properties
  void print() const override {
    Lepton::print();
    std::cout << "Muon: Isolation = " << (isolation ? "true" : "false") << std::endl;
  }

  bool getIsolation() const { return isolation; }

private:
  bool isolation;
};

#endif // MUON_H
