#include "ProduitB.h"
#include "Compteur.h"

ProduitB::ProduitB() : Produit("ProduitB") {
    Compteur::ajouterConstructeur();
}

ProduitB::ProduitB(const ProduitB& produitB) : Produit(produitB) {
    Compteur::ajouterConstructeurCopie();
}

ProduitB::~ProduitB() {
    Compteur::ajouterDestructeur();
}

string ProduitB::getDescription() const {
    return "Description d'un produit B";
}