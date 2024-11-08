#ifndef PRODUITC_H
#define PRODUITC_H

#include <string>
#include"Produit.h"
#include "Compteur.h"


class ProduitC : public Produit {
public:
    ProduitC() : Produit("ProduitC") {
        Compteur::ajouterConstructeur();
    }
    ProduitC(const ProduitC& produitC) : Produit(produitC) {
        Compteur::ajouterConstructeurCopie();
    }
    ~ProduitC() {
        Compteur::ajouterDestructeur();
    }
    string getDescription() const override {
        return "Description d'un produit C";
    }
};

#endif