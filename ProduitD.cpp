#include "ProduitD.h"
#include "Compteur.h"

ProduitD::ProduitD() : Produit("ProduitD") {
    Compteur::ajouterConstructeur();
}

ProduitD::ProduitD(const ProduitD& produitD) : Produit(produitD) {
    Compteur::ajouterConstructeurCopie();
}

ProduitD::~ProduitD() {
    Compteur::ajouterDestructeur();
}

string ProduitD::getDescription() const {
    return "Description d'un produit D";
}