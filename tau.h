// Tau.h - Defines the Tau class derived from Lepton.
// Author: Raul Scanlon, Date: 27/05/2024

#ifndef TAU_H
#define TAU_H

#include "Lepton.h"
#include <vector>
#include <memory>
#include <cmath>

// Derived class for Taus
class Tau : public Lepton {
public:
  Tau(double charge, double spin, int leptonNumber, const FourMomentum& momentum, double restMass, bool isAntiparticle = false)
    : Lepton(charge, spin, leptonNumber, momentum, restMass, "Tau", isAntiparticle) {}

  // Copy constructor
  Tau(const Tau& other)
    : Lepton(other), decayProducts(other.decayProducts) {}

  // Override print method to display Tau properties
  void print() const override {
    Lepton::print();
    std::cout << "Tau: ";
    if (!decayProducts.empty()) {
      std::cout << " Decay Products: ";
      for (const auto& product : decayProducts) {
        product->print();
      }
    }
    std::cout << std::endl;
  }

  // Add a decay product
  void addDecayProduct(const std::shared_ptr<Particle>& particle) {
    decayProducts.push_back(particle);
  }

  const std::vector<std::shared_ptr<Particle>>& getDecayProducts() const {
    return decayProducts;
  }

  // Consistency check for decay products
  void checkDecayConsistency() const {
    double totalCharge = 0;
    for (const auto& product : decayProducts) {
      totalCharge += product->getCharge();
    }
    if (std::abs(totalCharge - getCharge()) > 1e-2) {
      throw std::runtime_error("Decay products' charges do not sum up to the original Z Boson's charge");
    }
  }

private:
  std::vector<std::shared_ptr<Particle>> decayProducts;
};

#endif // TAU_H
