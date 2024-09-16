// Electron.h - Defines the Electron class derived from Lepton.
// Author: Raul Scanlon, Date: 27/05/2024

#ifndef ELECTRON_H
#define ELECTRON_H

#include "Lepton.h"
#include <array>
#include <stdexcept>
#include <iostream>

// Derived class for Electrons
class Electron : public Lepton {
public:
  Electron(double charge, double spin, int leptonNumber, const FourMomentum& momentum, double restMass, bool isAntiparticle = false)
    : Lepton(charge, spin, leptonNumber, momentum, restMass, "Electron", isAntiparticle), calorimeterEnergies({0, 0, 0, 0}) {}

  // Copy constructor
  Electron(const Electron& other)
    : Lepton(other), calorimeterEnergies(other.calorimeterEnergies) {}

  // Move constructor
  Electron(Electron&& other) noexcept
    : Lepton(std::move(other)), calorimeterEnergies(std::move(other.calorimeterEnergies)) {}

  // Copy assignment operator
  Electron& operator=(const Electron& other) {
    if (this != &other) {
      Lepton::operator=(other);
      calorimeterEnergies = other.calorimeterEnergies;
    }
    return *this;
  }

  // Move assignment operator
  Electron& operator=(Electron&& other) noexcept {
    if (this != &other) {
      Lepton::operator=(std::move(other));
      calorimeterEnergies = std::move(other.calorimeterEnergies);
    }
    return *this;
  }

  // Destructor
  ~Electron() override = default;

  // Override print method to display Electron properties
  void print() const override {
    Lepton::print();
    std::cout << "Electron: Energy deposited in calorimeter layers: " 
              << "Layer 1: " << calorimeterEnergies[0] << " "
              << "Layer 2: " << calorimeterEnergies[1] << " "
              << "Layer 3: " << calorimeterEnergies[2] << " "
              << "Layer 4: " << calorimeterEnergies[3] << std::endl;
  }

  // Set energy deposited in a specific calorimeter layer
  void setCalorimeterEnergy(size_t layer, double energy) {
    if (layer < calorimeterEnergies.size()) {
      calorimeterEnergies[layer] = energy;
    } else {
      throw std::out_of_range("Invalid calorimeter layer index");
    }
  }

  // Get energy deposited in a specific calorimeter layer
  double getCalorimeterEnergy(size_t layer) const {
    if (layer < calorimeterEnergies.size()) {
      return calorimeterEnergies[layer];
    } else {
      throw std::out_of_range("Invalid calorimeter layer index");
    }
  }

private:
  std::array<double, 4> calorimeterEnergies;
};

#endif // ELECTRON_H
