// Reception.cpp

#include "Reception.h"
#include "Compteur.h"
#include "Produit.h"
#include "BonCommande.h"
#include <iostream>
#include <list> 



Reception::Reception(BonCommande* bonCommande) : bonCommande(bonCommande) {
    Compteur::ajouterConstructeur();
}

Reception::~Reception() {
    for (int i = 0; i < 5; ++i) {
        for (Produit* produit : produits[i]) {
            delete produit;
        }
    }
    delete bonCommande;
    Compteur::ajouterDestructeur();
}
Reception::Reception(const Reception& reception) {
	for (int i = 0; i < 5; ++i) {
		for (Produit* produit : reception.produits[i]) {
			produits[i].push_back(produit->clone());
		}
	}
	bonCommande = reception.bonCommande->clone();
	Compteur::ajouterConstructeurCopie();
}
void Reception::ajouterProduit(Produit* produit, int id) {
    if (id >= 0 && id < 5) {
        produits[id].push_back(produit);
    }
}

BonCommande* Reception::getBonCommande() const {
    return bonCommande;
}

int Reception::getQuantiteProduitsRecus(int id) const {
    if (id >= 0 && id < 5) {
        return produits[id].size();
    }
    return 0;
}

const list<Produit*>& Reception::getProduits(int idProduits) const{
    if (idProduits >= 0 && idProduits < 5) {
        return produits[idProduits];
    }
    return list<Produit*>();
}


std::ostream& operator<<(std::ostream& out, const Reception& reception) {
out << "Reception" << endl;
	out << *reception.bonCommande;
	return out;

}

Reception::~Reception() {
    Compteur::ajouterDestructeur();

  };











