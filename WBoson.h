// WBoson.h - Defines the WBoson class derived from Boson.
// Author: Raul Scanlon, Date: 27/05/2024

#ifndef WBOSON_H
#define WBOSON_H

#include "Boson.h"
#include <vector>
#include <memory>
#include <cmath>

// Derived class for W Bosons
class WBoson : public Boson {
public:
  WBoson(double charge, double spin, const FourMomentum& momentum, double restMass, bool isAntiparticle = false)
    : Boson(charge, spin, momentum, restMass, isAntiparticle){}

  // Copy constructor
  WBoson(const WBoson& other)
    : Boson(other), isAntiparticle(other.isAntiparticle), decayProducts(other.decayProducts) {}

  // Move constructor
  WBoson(WBoson&& other) noexcept
    : Boson(std::move(other)), isAntiparticle(other.isAntiparticle), decayProducts(std::move(other.decayProducts)) {}

  // Copy assignment operator
  WBoson& operator=(const WBoson& other) {
    if (this != &other) {
      Boson::operator=(other);
      isAntiparticle = other.isAntiparticle;
      decayProducts = other.decayProducts;
    }
    return *this;
  }

  // Move assignment operator
  WBoson& operator=(WBoson&& other) noexcept {
    if (this != &other) {
      Boson::operator=(std::move(other));
      isAntiparticle = other.isAntiparticle;
      decayProducts = std::move(other.decayProducts);
    }
    return *this;
  }

  // Destructor
  ~WBoson() override = default;

  // Override print method to display W Boson properties
  void print() const override {
    std::cout << "WBoson: Charge = " << getCharge() << ", Spin = " << getSpin()
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
      throw std::runtime_error("Decay products' charges do not sum up to the original W Boson's charge");
    }
  }

  std::string getTypeName() const override { return "WBoson"; }

  double getCharge() const override { return charge; }
  double getSpin() const override { return spin; }
  FourMomentum getFourMomentum() const override { return momentum; }
  double getRestMass() const override { return restMass; }

private:
  bool isAntiparticle;
  std::vector<std::shared_ptr<Particle>> decayProducts;
};

#endif // WBOSON_H
