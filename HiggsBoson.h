// HiggsBoson.h - Defines the HiggsBoson class derived from Boson.
// Author: Raul Scanlon, Date: 26/05/2024

#ifndef HIGGSBOSON_H
#define HIGGSBOSON_H

#include "Boson.h"
#include <vector>
#include <memory>
#include <cmath>

// Derived class for Higgs Bosons
class HiggsBoson : public Boson {
public:
  HiggsBoson(double charge, double spin, const FourMomentum& momentum, double restMass, bool isAntiparticle = false)
    : Boson(charge, spin, momentum, restMass, isAntiparticle), isAntiparticle(isAntiparticle) {}

  // Copy constructor
  HiggsBoson(const HiggsBoson& other)
    : Boson(other), isAntiparticle(other.isAntiparticle), decayProducts(other.decayProducts) {}

  // Move constructor
  HiggsBoson(HiggsBoson&& other) noexcept
    : Boson(std::move(other)), isAntiparticle(other.isAntiparticle), decayProducts(std::move(other.decayProducts)) {}

  // Copy assignment operator
  HiggsBoson& operator=(const HiggsBoson& other) {
    if (this != &other) {
      Boson::operator=(other);
      isAntiparticle = other.isAntiparticle;
      decayProducts = other.decayProducts;
    }
    return *this;
  }

  // Move assignment operator
  HiggsBoson& operator=(HiggsBoson&& other) noexcept {
    if (this != &other) {
      Boson::operator=(std::move(other));
      isAntiparticle = other.isAntiparticle;
      decayProducts = std::move(other.decayProducts);
    }
    return *this;
  }

  // Destructor
  ~HiggsBoson() override = default;

  // Override print method to display Higgs Boson properties
  void print() const override {
    std::cout << "HiggsBoson: Charge = " << getCharge() << ", Spin = " << getSpin()
              << ", Rest Mass = " << getRestMass() << ", Momentum = " << getFourMomentum()
              << ", Is Antiparticle = " << (isAntiparticle ? "true" : "false") << std::endl;
    if (!decayProducts.empty()) {
      std::cout << " Decay Products: ";
      for (const auto& product : decayProducts) {
        product->print();
      }
    }
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
      throw std::runtime_error("Decay products' charges do not sum up to the original Higgs Boson's charge");
    }
  }

  std::string getTypeName() const override { return "HiggsBoson"; }

  double getCharge() const override { return charge; }
  double getSpin() const override { return spin; }
  FourMomentum getFourMomentum() const override { return momentum; }
  double getRestMass() const override { return restMass; }

private:
  bool isAntiparticle;
  std::vector<std::shared_ptr<Particle>> decayProducts;
};

#endif // HIGGSBOSON_H
