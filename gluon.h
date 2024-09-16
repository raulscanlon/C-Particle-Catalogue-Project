// Gluon.h - Defines the Gluon class derived from Boson.
// Author: Raul Scanlon, Date: 27/05/2024

#ifndef GLUON_H
#define GLUON_H

#include "Boson.h"

// Derived class for Gluons
class Gluon : public Boson {
public:
  Gluon(double spin, const FourMomentum& momentum, const std::string& colour1, const std::string& colour2)
    : Boson(0, spin, momentum, 0), colourCharge1(colour1), colourCharge2(colour2) {}

  // Copy constructor
  Gluon(const Gluon& other)
    : Boson(other), colourCharge1(other.colourCharge1), colourCharge2(other.colourCharge2) {}

  // Move constructor
  Gluon(Gluon&& other) noexcept
    : Boson(std::move(other)), colourCharge1(std::move(other.colourCharge1)), colourCharge2(std::move(other.colourCharge2)) {}

  // Copy assignment operator
  Gluon& operator=(const Gluon& other) {
    if (this != &other) {
      Boson::operator=(other);
      colourCharge1 = other.colourCharge1;
      colourCharge2 = other.colourCharge2;
    }
    return *this;
  }

  // Move assignment operator
  Gluon& operator=(Gluon&& other) noexcept {
    if (this != &other) {
      Boson::operator=(std::move(other));
      colourCharge1 = std::move(other.colourCharge1);
      colourCharge2 = std::move(other.colourCharge2);
    }
    return *this;
  }

  // Destructor
  ~Gluon() override = default;

  // Override print method to display Gluon properties
  void print() const override {
    std::cout << "Gluon: Charge = " << getCharge() << ", Spin = " << getSpin()
              << ", Rest Mass = " << getRestMass() << ", Momentum = " << getFourMomentum()
              << ", colour Charges = (" << colourCharge1 << ", " << colourCharge2 << ")" << std::endl;
  }

  std::string getTypeName() const override { return "Gluon"; }

  double getCharge() const override { return charge; }
  double getSpin() const override { return spin; }
  FourMomentum getFourMomentum() const override { return momentum; }
  double getRestMass() const override { return restMass; }

  void setcolourCharges(const std::string& colour1, const std::string& colour2) {
    colourCharge1 = colour1;
    colourCharge2 = colour2;
  }

  std::pair<std::string, std::string> getcolourCharges() const {
    return {colourCharge1, colourCharge2};
  }

private:
  std::string colourCharge1;
  std::string colourCharge2;
};

#endif // GLUON_H
