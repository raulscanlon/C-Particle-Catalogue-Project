// Neutrino.h - Defines the Neutrino class derived from Lepton.
// Author: Raul Scanlon, Date: 26/05/2024

#ifndef NEUTRINO_H
#define NEUTRINO_H

#include "Lepton.h"

// Derived class for Neutrinos
class Neutrino : public Lepton {
public:
  Neutrino(double charge, double spin, int leptonNumber, const FourMomentum& momentum, double restMass, const std::string& name, bool interaction = false, bool isAntiparticle = false)
    : Lepton(charge, spin, leptonNumber, momentum, restMass, name, isAntiparticle), interaction(interaction) {}

  // Copy constructor
  Neutrino(const Neutrino& other)
    : Lepton(other), interaction(other.interaction) {}

  // Move constructor
  Neutrino(Neutrino&& other) noexcept
    : Lepton(std::move(other)), interaction(other.interaction) {}

  // Copy assignment operator
  Neutrino& operator=(const Neutrino& other) {
    if (this != &other) {
      Lepton::operator=(other);
      interaction = other.interaction;
    }
    return *this;
  }

  // Move assignment operator
  Neutrino& operator=(Neutrino&& other) noexcept {
    if (this != &other) {
      Lepton::operator=(std::move(other));
      interaction = other.interaction;
    }
    return *this;
  }

  // Destructor
  ~Neutrino() override = default;

  // Override print method to display Neutrino properties
  void print() const override {
    Lepton::print();
    std::cout << "Neutrino: Interaction = " << (interaction ? "Yes" : "No") << std::endl;
  }

  bool getInteraction() const { return interaction; }

private:
  bool interaction;
};

#endif // NEUTRINO_H
