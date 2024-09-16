// FourMomentum.h - Defines the FourMomentum class representing the four-momentum vector of particles.
// Author: Raul Scanlon, Date: 24/05/2024

#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include <cmath>
#include <iostream>

// Class representing the four-momentum of a particle
class FourMomentum {
public:
  FourMomentum(double E = 0, double px = 0, double py = 0, double pz = 0)
    : E(E), px(px), py(py), pz(pz) {}

  double getEnergy() const { return E; }
  double getPx() const { return px; }
  double getPy() const { return py; }
  double getPz() const { return pz; }

  void setEnergy(double E) { this->E = E; }
  void setPx(double px) { this->px = px; }
  void setPy(double py) { this->py = py; }
  void setPz(double pz) { this->pz = pz; }

  // Calculate the invariant mass
  double invariantMass() const {
    return std::sqrt(E * E - px * px - py * py - pz * pz);
  }

  // Overloaded operators for four-momentum operations
  FourMomentum operator+(const FourMomentum& other) const {
    return FourMomentum(E + other.E, px + other.px, py + other.py, pz + other.pz);
  }

  FourMomentum operator-(const FourMomentum& other) const {
    return FourMomentum(E - other.E, px - other.px, py - other.py, pz - other.pz);
  }

  double dot(const FourMomentum& other) const {
    return E * other.E - (px * other.px + py * other.py + pz * other.pz);
  }

  // Overloaded stream insertion operator for printing
  friend std::ostream& operator<<(std::ostream& os, const FourMomentum& momentum) {
    os << "E: " << momentum.E << ", px: " << momentum.px
       << ", py: " << momentum.py << ", pz: " << momentum.pz;
    return os;
  }

private:
  double E, px, py, pz;
};

#endif // FOURMOMENTUM_H
