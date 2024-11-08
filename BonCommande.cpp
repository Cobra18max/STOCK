#include<string>
#include"Produit.h"
#include"Composant.h"
#include"Commande.h"

#include "BonCommande.h"


void BonCommande::initialiser() {
    for (int i = 0; i < 5; i++) {
        quantiteProduits[i] = 0;
    }
}

BonCommande::BonCommande(int idBonCommande, Commande* commande)
    : idBonCommande(idBonCommande), commande(commande) {
    initialiser();
    Compteur::ajouterConstructeur();
}

BonCommande::BonCommande(const BonCommande& bonCommande)
    : idBonCommande(bonCommande.idBonCommande), commande(bonCommande.commande) {
    initialiser();
    for (int i = 0; i < 5; ++i) {
        this->quantiteProduits[i] = bonCommande.quantiteProduits[i];
    }
    Compteur::ajouterConstructeurCopie();
}

BonCommande::~BonCommande() {
    Compteur::ajouterDestructeur();
}

void BonCommande::ajouterProduits(int quantite, int id) {
    if (id >= 0 && id < 5) {
        quantiteProduits[id] += quantite;
    }
}

int BonCommande::getQuantiteProduits(int id)const {
    if (id >= 0 && id < 5) {
        return quantiteProduits[id];
    }
    return 0;
}

Commande* BonCommande::getCommande()const {
    return commande;
}

int BonCommande::getIdBonCommande() const {
    return idBonCommande;
}

std::ostream& operator<<(std::ostream& os, const BonCommande& bonCommande) {
    os << "-------------------------------------" << std::endl;
    os << "BON DE COMMANDE" << std::endl;
    os << "Bon de commande : " << bonCommande.getIdBonCommande() << std::endl;

    Commande* commande = bonCommande.getCommande();
    if (commande != nullptr) {
        os << "No de commande : " << commande->getNoCommande() << std::endl;
    }

    for (int i = 0; i < 5; ++i) {
        int commandeQuantite = (commande != nullptr) ? commande->getQuantiteProduit(i) : 0;
        int recuQuantite = bonCommande.getQuantiteProduits(i);

        os << "- Produit {" << i << "} --> {commande:" << commandeQuantite
            << "/recu:" << recuQuantite << "}" << std::endl;
    }

    os << "-------------------------------------" << std::endl;
    return os;
}

BonCommande* BonCommande::clone() const {
    return new BonCommande(*this);
}