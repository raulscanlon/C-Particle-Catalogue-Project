// main.cpp - Main function to demonstrate the functionalities of the Particle Catalogue.
// Author: Raul Scanlon, Date: 27/05/2024
#include <iostream>
#include <memory>
#include "ParticleCatalogue.h"
#include "lepton.h"
#include "quark.h"
#include "boson.h"
#include "FourMomentum.h"
#include "muon.h"
#include "tau.h"
#include "WBoson.h"
#include "ZBoson.h"
#include "photon.h"
#include "neutrino.h"
#include "HiggsBoson.h"
#include "gluon.h"
#include "electron.h"

void handleDecay(const std::shared_ptr<Particle>& particle, ParticleCatalogue& catalogue);

int main() {
  ParticleCatalogue catalogue;

  // FourMomentum instances
  FourMomentum electronMomentum(0.511, 0.0, 0.0, 0.0);
  FourMomentum muonMomentum(105.7, 0.0, 0.0, 0.0);
  FourMomentum tauMomentum(1777.0, 0.0, 0.0, 0.0);
  FourMomentum upQuarkMomentum(2.3, 0.0, 0.0, 0.0);
  FourMomentum downQuarkMomentum(4.8, 0.0, 0.0, 0.0);
  FourMomentum strangeQuarkMomentum(95.0, 0.0, 0.0, 0.0);
  FourMomentum charmQuarkMomentum(1275.0, 0.0, 0.0, 0.0);
  FourMomentum bottomQuarkMomentum(4180.0, 0.0, 0.0, 0.0);
  FourMomentum topQuarkMomentum(173070.0, 0.0, 0.0, 0.0);
  FourMomentum zBosonMomentum(91200.0, 0.0, 0.0, 0.0);
  FourMomentum wBosonMomentum(80400.0, 0.0, 0.0, 0.0);
  FourMomentum higgsMomentum(126000.0, 0.0, 0.0, 0.0);
  FourMomentum photonMomentum(62.55, 0.0, 0.0, 0.0);
  FourMomentum gluonMomentum(0.0, 0.0, 0.0, 0.0);
  FourMomentum neutrinoMomentum(0.0, 0.0, 0.0, 0.0);

  // Add particles to the catalogue
  auto electron = std::make_shared<Electron>(-1.0, 0.5, 1, electronMomentum, 0.511);
  auto positron = std::make_shared<Electron>(-1.0, 0.5, -1, electronMomentum, 0.511, true);
  auto muon = std::make_shared<Muon>(-1.0, 0.5, 1, muonMomentum, 105.7, true);
  auto antiMuon = std::make_shared<Muon>(-1.0, 0.5, -1, muonMomentum, 105.7, true, true);
  auto tau = std::make_shared<Tau>(-1.0, 0.5, 1, tauMomentum, 1777.0);
  auto antiTau = std::make_shared<Tau>(-1.0, 0.5, -1, tauMomentum, 1777.0, true);
  auto higgs = std::make_shared<HiggsBoson>(0.0, 0.0, higgsMomentum, 126000.0);
  auto wboson = std::make_shared<WBoson>(1.0, 1.0, wBosonMomentum, 80400.0);
  auto antiwboson = std::make_shared<WBoson>(1.0, 1.0, wBosonMomentum, 80400.0, true);
  auto zboson = std::make_shared<ZBoson>(0.0, 1.0, zBosonMomentum, 91200.0);
  auto photon = std::make_shared<Photon>(photonMomentum);
  auto gluon = std::make_shared<Gluon>(1, gluonMomentum, "red", "blue");

  auto neutrinoE = std::make_shared<Neutrino>(0.0, 0.5, 1, neutrinoMomentum, 0.0, "Electron Neutrino", false, false);
  auto antineutrinoE = std::make_shared<Neutrino>(0.0, 0.5, -1, neutrinoMomentum, 0.0, "Electron Anti-Neutrino", false, true);
  auto neutrinoMu = std::make_shared<Neutrino>(0.0, 0.5, 1, neutrinoMomentum, 0.0, "Muon Neutrino", false, false);
  auto antineutrinoMu = std::make_shared<Neutrino>(0.0, 0.5, -1, neutrinoMomentum, 0.0, "Muon Anti-Neutrino", true, true);
  auto neutrinoTau = std::make_shared<Neutrino>(0.0, 0.5, 1, neutrinoMomentum, 0.0, "Tau Neutrino", false, false);
  auto antineutrinoTau = std::make_shared<Neutrino>(0.0, 0.5, -1, neutrinoMomentum, 0.0, "Tau Anti-Neutrino", false, true);

  auto quarkUp = std::make_shared<Quark>(2.0 / 3.0, 0.5, 1.0 / 3.0, "red", upQuarkMomentum, 2.3, "Up Quark", false);
  auto antiquarkUp = std::make_shared<Quark>(2.0 / 3.0, 0.5, -1.0 / 3.0, "anti-red", upQuarkMomentum, 2.3, "Anti-Up Quark", true);
  auto quarkDown = std::make_shared<Quark>(-1.0 / 3.0, 0.5, 1.0 / 3.0, "blue", downQuarkMomentum, 4.8, "Down Quark", false);
  auto antiquarkDown = std::make_shared<Quark>(-1.0 / 3.0, 0.5, -1.0 / 3.0,  "anti-blue", downQuarkMomentum, 4.8, "Anti-Down Quark", true);
  auto quarkCharm = std::make_shared<Quark>(2.0 / 3.0, 0.5, 1.0 / 3.0, "green", charmQuarkMomentum, 1275.0, "Charm Quark", false);
  auto antiquarkCharm = std::make_shared<Quark>(2.0 / 3.0, 0.5, -1.0 / 3.0, "anti-green", charmQuarkMomentum, 1275.0, "Anti-Charm Quark", true);
  auto quarkStrange = std::make_shared<Quark>(-1.0 / 3.0, 0.5, 1.0 / 3.0, "red", strangeQuarkMomentum, 95.0, "Strange Quark", false);
  auto antiquarkStrange = std::make_shared<Quark>(-1.0 / 3.0, 0.5, -1.0 / 3.0,  ("anti-red"), strangeQuarkMomentum, 95.0, "Anti-Strange Quark", true);
  auto quarkTop = std::make_shared<Quark>(2.0 / 3.0, 0.5, 1.0 / 3.0, "blue", topQuarkMomentum, 173070.0, "Top Quark", false);
  auto antiquarkTop = std::make_shared<Quark>(2.0 / 3.0, 0.5, -1.0 / 3.0, "anti-blue", topQuarkMomentum, 173070.0, "Anti-Top Quark", true);
  auto quarkBottom = std::make_shared<Quark>(-1.0 / 3.0, 0.5, 1.0 / 3.0, "green", bottomQuarkMomentum, 4180.0, "Bottom Quark", false);
  auto antiquarkBottom = std::make_shared<Quark>(-1.0 / 3.0, 0.5, -1.0 / 3.0, "anti-green", bottomQuarkMomentum, 4180.0, "Anti-Bottom Quark", true);

  // Handle decays
  handleDecay(tau, catalogue);
  handleDecay(higgs, catalogue);
  handleDecay(wboson, catalogue);
  handleDecay(antiwboson, catalogue);
  handleDecay(zboson, catalogue);

  // Add particles to catalogue
  catalogue.addParticle(electron);
  catalogue.addParticle(positron);
  catalogue.addParticle(muon);
  catalogue.addParticle(antiMuon);
  catalogue.addParticle(tau);
  catalogue.addParticle(antiTau);
  catalogue.addParticle(higgs);
  catalogue.addParticle(wboson);
  catalogue.addParticle(antiwboson);
  catalogue.addParticle(zboson);
  catalogue.addParticle(photon);
  catalogue.addParticle(gluon);
  catalogue.addParticle(neutrinoE);
  catalogue.addParticle(antineutrinoE);
  catalogue.addParticle(neutrinoMu);
  catalogue.addParticle(antineutrinoMu);
  catalogue.addParticle(neutrinoTau);
  catalogue.addParticle(antineutrinoTau);
  catalogue.addParticle(quarkUp);
  catalogue.addParticle(antiquarkUp);
  catalogue.addParticle(quarkDown);
  catalogue.addParticle(antiquarkDown);
  catalogue.addParticle(quarkCharm);
  catalogue.addParticle(antiquarkCharm);
  catalogue.addParticle(quarkStrange);
  catalogue.addParticle(antiquarkStrange);
  catalogue.addParticle(quarkTop);
  catalogue.addParticle(antiquarkTop);
  catalogue.addParticle(quarkBottom);
  catalogue.addParticle(antiquarkBottom);

  // Print particles based on user input
  catalogue.handleUserInput();

  return 0;
}

void handleDecay(const std::shared_ptr<Particle>& particle, ParticleCatalogue& catalogue) {
  // Handle the decays of particles
  if (auto tau = std::dynamic_pointer_cast<Tau>(particle)) {
    // Tau decays
    std::shared_ptr<Particle> decayProduct1, decayProduct2, decayProduct3;
    std::cout << "Handling Tau decay" << std::endl;

    if (rand() % 2 == 0) {
      // Leptonic decay
      decayProduct1 = std::make_shared<Electron>(-1.0, 0.5, 1, tau->getFourMomentum(), 0.511);
      decayProduct2 = std::make_shared<Neutrino>(0.0, 0.5, 1, tau->getFourMomentum(), 0.0, "Neutrino", false, false);
      decayProduct3 = std::make_shared<Neutrino>(0.0, 0.5, -1, tau->getFourMomentum(), 0.0, "Anti-Neutrino", false, true);
    } else {
      // Hadronic decay
      decayProduct1 = std::make_shared<Quark>(2.0 / 3.0, 0.5, 1.0 / 3.0, "anti-red", tau->getFourMomentum(), 2.3, "Anti-Up Quark", true);
      decayProduct2 = std::make_shared<Quark>(-1.0 / 3.0, 0.5, 1.0 / 3.0, "blue", tau->getFourMomentum(), 4.8, "Down Quark", false);
      decayProduct3 = std::make_shared<Neutrino>(0.0, 0.5, -1, tau->getFourMomentum(), 0.0, "Anti-Neutrino", false, true);
    }

    std::cout << "Decay products created: " << std::endl;
    std::cout << "Decay product 1: " << decayProduct1->getTypeName() << " (Charge: " << decayProduct1->getCharge() << ")" << std::endl;
    std::cout << "Decay product 2: " << decayProduct2->getTypeName() << " (Charge: " << decayProduct2->getCharge() << ")" << std::endl;
    std::cout << "Decay product 3: " << decayProduct3->getTypeName() << " (Charge: " << decayProduct3->getCharge() << ")" << std::endl;

    tau->addDecayProduct(decayProduct1);
    tau->addDecayProduct(decayProduct2);
    tau->addDecayProduct(decayProduct3);

    tau->checkDecayConsistency();

  } else if (auto higgs = std::dynamic_pointer_cast<HiggsBoson>(particle)) {
    // Higgs decays
    std::shared_ptr<Particle> decayProduct1, decayProduct2;
    std::cout << "Handling Higgs decay" << std::endl;
    switch (rand() % 4) {
      case 0:
        decayProduct1 = std::make_shared<ZBoson>(0.0, 1.0, FourMomentum(45.6, 0.0, 0.0, 0.0), 91200.0);
        decayProduct2 = std::make_shared<ZBoson>(0.0, 1.0, FourMomentum(45.6, 0.0, 0.0, 0.0), 91200.0);
        break;
      case 1:
        decayProduct1 = std::make_shared<WBoson>(1.0, 1.0, FourMomentum(40.2, 0.0, 0.0, 0.0), 80400.0);
        decayProduct2 = std::make_shared<WBoson>(1.0, 1.0, FourMomentum(40.2, 0.0, 0.0, 0.0), 80400.0, true);
        break;
      case 2:
        decayProduct1 = std::make_shared<Photon>(FourMomentum(62.55, 0.0, 0.0, 0.0));
        decayProduct2 = std::make_shared<Photon>(FourMomentum(62.55, 0.0, 0.0, 0.0));
        break;
      case 3:
        decayProduct1 = std::make_shared<Quark>(-1.0 / 3.0, 0.5, 1.0 / 3.0, "red", FourMomentum(4180.0, 0.0, 0.0, 0.0), 4.18, "Bottom Quark", false);
        decayProduct2 = std::make_shared<Quark>(-1.0 / 3.0, 0.5, -1.0 / 3.0, "anti-red", FourMomentum(4180.0, 0.0, 0.0, 0.0), 4.18, "Anti-Bottom", true);
        break;
    }

    std::cout << "Decay products created: " << std::endl;
    std::cout << "Decay product 1: " << decayProduct1->getTypeName() << " (Charge: " << decayProduct1->getCharge() << ")" << std::endl;
    std::cout << "Decay product 2: " << decayProduct2->getTypeName() << " (Charge: " << decayProduct2->getCharge() << ")" << std::endl;
    
    higgs->addDecayProduct(decayProduct1);
    higgs->addDecayProduct(decayProduct2);
    higgs->checkDecayConsistency();

  } else if (auto wboson = std::dynamic_pointer_cast<WBoson>(particle)) {
    // W boson decays
    std::shared_ptr<Particle> decayProduct1, decayProduct2;
    if (wboson->getCharge() > 0) {
      std::cout << "Handling W+ Boson decay" << std::endl;

      if (rand() % 2 == 0) {
        // Leptonic decay
        decayProduct1 = std::make_shared<Electron>(-1.0, 0.5, 1, wboson->getFourMomentum(), 0.511, true); // Positron (anti-electron)
        decayProduct2 = std::make_shared<Neutrino>(0.0, 0.5, 1, wboson->getFourMomentum(), 0.0, "Neutrino", false, false);
      } else {
        // Hadronic decay
        decayProduct1 = std::make_shared<Quark>(2.0 / 3.0, 0.5, 1.0 / 3.0, "red", wboson->getFourMomentum(), 2.3, "up", false); // Up quark
        decayProduct2 = std::make_shared<Quark>(-1.0 / 3.0, 0.5, 1.0 / 3.0, "blue", wboson->getFourMomentum(), 4.8, "anti-down", true); // Anti-down quark
      }
    } else {
      std::cout << "Handling W- Boson decay" << std::endl;

      if (rand() % 2 == 0) {
        // Leptonic decay
        decayProduct1 = std::make_shared<Electron>(-1.0, 0.5, 1, wboson->getFourMomentum(), 0.511); // Electron
        decayProduct2 = std::make_shared<Neutrino>(0.0, 0.5, -1, wboson->getFourMomentum(), 0.0, "Anti-Neutrino", false, true); // Anti-neutrino
      } else {
        // Hadronic decay
        decayProduct1 = std::make_shared<Quark>(-1.0 / 3.0, 0.5, 1.0 / 3.0, "blue", wboson->getFourMomentum(), 4.8, "down", false); // Down quark
        decayProduct2 = std::make_shared<Quark>(2.0 / 3.0, 0.5, 1.0 / 3.0, "red", wboson->getFourMomentum(), 2.3, "anti-up", true); // Anti-up quark
      }
    }

    std::cout << "Decay products created: " << std::endl;
    std::cout << "Decay product 1: " << decayProduct1->getTypeName() << " (Charge: " << decayProduct1->getCharge() << ")" << std::endl;
    std::cout << "Decay product 2: " << decayProduct2->getTypeName() << " (Charge: " << decayProduct2->getCharge() << ")" << std::endl;

    wboson->addDecayProduct(decayProduct1);
    wboson->addDecayProduct(decayProduct2);
    wboson->checkDecayConsistency();

  } else if (auto zboson = std::dynamic_pointer_cast<ZBoson>(particle)) {
    // Z boson decays
    std::shared_ptr<Particle> decayProduct1, decayProduct2;
    std::cout << "Handling Z Boson decay" << std::endl;

    if (rand() % 2 == 0) {
      // Leptonic decay
      decayProduct1 = std::make_shared<Electron>(-1.0, 0.5, 1, zboson->getFourMomentum(), 0.511);
      decayProduct2 = std::make_shared<Electron>(-1.0, 0.5, -1, zboson->getFourMomentum(), 0.511, true);
    } else {
      // Hadronic decay
      decayProduct1 = std::make_shared<Quark>(2.0 / 3.0, 0.5, 1.0 / 3.0, "red", zboson->getFourMomentum(), 2.3, "Up Quark", false);
      decayProduct2 = std::make_shared<Quark>(2.0 / 3.0, 0.5, -1.0 / 3.0, "anti-red", zboson->getFourMomentum(), 2.3, "Anti-Up Quark", true);
    }

    std::cout << "Decay products created: " << std::endl;
    std::cout << "Decay product 1: " << decayProduct1->getTypeName() << " (Charge: " << decayProduct1->getCharge() << ")" << std::endl;
    std::cout << "Decay product 2: " << decayProduct2->getTypeName() << " (Charge: " << decayProduct2->getCharge() << ")" << std::endl;
    
    zboson->addDecayProduct(decayProduct1);
    zboson->addDecayProduct(decayProduct2);
    zboson->checkDecayConsistency();
  }
}
