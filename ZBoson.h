// ZBoson.h - Defines the ZBoson class derived from Boson.
// Author: Raul Scanlon, Date: 27/05/2024

#ifndef ZBOSON_H
#define ZBOSON_H

#include "Boson.h"
#include <vector>
#include <memory>
#include <cmath>

// Derived class for Z Bosons
class ZBoson : public Boson {
public:
  ZBoson(double charge, double spin, const FourMomentum& momentum, double restMass, bool isAntiparticle = false)
    : Boson(charge, spin, momentum, restMass, isAntiparticle), isAntiparticle(isAntiparticle) {}

  // Copy constructor
  ZBoson(const ZBoson& other)
    : Boson(other), isAntiparticle(other.isAntiparticle), decayProducts(other.decayProducts) {}

  // Move constructor
  ZBoson(ZBoson&& other) noexcept
    : Boson(std::move(other)), isAntiparticle(other.isAntiparticle), decayProducts(std::move(other.decayProducts)) {}

  // Copy assignment operator
  ZBoson& operator=(const ZBoson& other) {
    if (this != &other) {
      Boson::operator=(other);
      isAntiparticle = other.isAntiparticle;
      decayProducts = other.decayProducts;
    }
    return *this;
  }

  // Move assignment operator
  ZBoson& operator=(ZBoson&& other) noexcept {
    if (this != &other) {
      Boson::operator=(std::move(other));
      isAntiparticle = other.isAntiparticle;
      decayProducts = std::move(other.decayProducts);
    }
    return *this;
  }

  // Destructor
  ~ZBoson() override = default;

  // Override print method to display Z Boson properties
  void print() const override {
    std::cout << "ZBoson: Charge = " << getCharge() << ", Spin = " << getSpin()
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
      throw std::runtime_error("Decay products' charges do not sum up to the original Z Boson's charge");
    }
  }

  std::string getTypeName() const override { return "ZBoson"; }

  double getCharge() const override { return charge; }
  double getSpin() const override { return spin; }
  FourMomentum getFourMomentum() const override { return momentum; }
  double getRestMass() const override { return restMass; }

private:
  bool isAntiparticle;
  std::vector<std::shared_ptr<Particle>> decayProducts;
};

#endif // ZBOSON_H
