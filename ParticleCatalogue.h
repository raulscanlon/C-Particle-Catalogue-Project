// ParticleCatalogue.h - Defines the ParticleCatalogue class, a container for managing a collection of particles.
// Author: Raul Scanlon, Date: 26/05/2024

#ifndef PARTICLECATALOGUE_H
#define PARTICLECATALOGUE_H

#include <vector>
#include <memory>
#include <map>
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <cctype> // for std::tolower
#include "Particle.h"

// Class representing a catalogue of particles
class ParticleCatalogue {
public:
  // Add a particle to the catalogue
  void addParticle(const std::shared_ptr<Particle>& particle) {
    particles.push_back(particle);
  }

  // Print all particles in the catalogue
  void printAllParticles() const {
    for (const auto& particle : particles) {
      particle->print();
    }
  }

  // Print particles by type
  void printParticlesByType(const std::string& type) const {
    std::string lowerType = toLowerCase(type); // Convert type to lowercase
    std::for_each(particles.begin(), particles.end(), [&lowerType](const auto& particle) {
      if (toLowerCase(particle->getTypeName()) == lowerType) { // Compare lowercase strings
        particle->print();
      }
    });
  }
  
  // Get the total number of particles
  size_t getTotalCount() const {
    return particles.size();
  }

  // Template function to get the count of a specific particle type
  template <typename T>
  int getParticleCount() const {
    int count = 0;
    for (const auto& particle : particles) {
      if (std::dynamic_pointer_cast<T>(particle)) {
        count++;
      }
    }
    return count;
  }

  // Get the counts of particles by type
  std::map<std::string, int> getParticleCounts() const {
    std::map<std::string, int> counts;
    for (const auto& particle : particles) {
      std::string type = toLowerCase(particle->getTypeName()); // Convert type to lowercase
      counts[type]++;
    }
    return counts;
  }

  // Get the total four-momentum of all particles
  FourMomentum getTotalFourMomentum() const {
    FourMomentum totalMomentum;
    for (const auto& particle : particles) {
      totalMomentum = totalMomentum + particle->getFourMomentum();
    }
    return totalMomentum;
  }

  // Get particles of a specific type
  std::vector<std::shared_ptr<Particle>> getParticlesOfType(const std::string& type) const {
    std::vector<std::shared_ptr<Particle>> particlesOfType;
    std::string lowerType = toLowerCase(type); // Convert type to lowercase
    for (const auto& particle : particles) {
      if (toLowerCase(particle->getTypeName()) == lowerType) { // Compare lowercase strings
        particlesOfType.push_back(particle);
      }
    }
    return particlesOfType;
  }

  // Function to sort particles by charge using a lambda function
  void sortParticlesByCharge() {
    std::sort(particles.begin(), particles.end(), [](const std::shared_ptr<Particle>& a, const std::shared_ptr<Particle>& b) {
      return a->getCharge() < b->getCharge();
    });
  }

  // User input and printing particles
  void handleUserInput() const {
    int choice;
    while (true) {
      std::cout << "Select an option:\n";
      std::cout << "1. Print all particles\n";
      std::cout << "2. Print particles by type\n";
      std::cout << "3. Exit\n";
      std::cin >> choice;

      // Check if input is valid
      if (std::cin.fail()) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
        std::cerr << "Invalid input. Please enter a number.\n";
        continue; // Prompt the user again
      }

      // Handle valid choices
      switch (choice) {
      case 1:
        printAllParticles();
        break;
      case 2: {
        std::string type;
        std::cout << "Enter the particle type: ";
        std::cin >> type;
        printParticlesByType(type);
        break;
      }
      case 3:
        std::cout << "Exiting...\n";
        return; // Exit the function
      default:
        std::cerr << "Invalid choice. Please try again.\n";
      }
    }
  }

private:
  std::vector<std::shared_ptr<Particle>> particles;

  // Helper function to convert a string to lowercase
  static std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
  }
};

#endif // PARTICLECATALOGUE_H
