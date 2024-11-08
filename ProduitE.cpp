#include "ProduitE.h"
#include "Compteur.h"

ProduitE::ProduitE() : Produit("ProduitE") {
    Compteur::ajouterConstructeur();
}

ProduitE::ProduitE(const ProduitE& produitE ) : Produit(produitE) {
    Compteur::ajouterConstructeurCopie();
}

ProduitE::~ProduitE() {
    Compteur::ajouterDestructeur();
}

string ProduitE::getDescription() const {
    return "Description d'un produit E";
}