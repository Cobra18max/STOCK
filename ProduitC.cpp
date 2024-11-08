#include "ProduitC.h"
#include "Compteur.h"

ProduitC::ProduitC() : Produit("ProduitC") {
    Compteur::ajouterConstructeur();
}

ProduitC::ProduitC(const ProduitC& produitC) : Produit(produitC) {
    Compteur::ajouterConstructeurCopie();
}

ProduitC::~ProduitC() {
    Compteur::ajouterDestructeur();
}

string ProduitC::getDescription() const {
    return "Description d'un produit C";
}