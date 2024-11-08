#pragma once
#include<string>
#include"Produit.h"
#include"Composant.h"
#include"Composant.h"
#include"Entrepot.h"
#include "Commande.h"

using namespace std;

class BonCommande
{
public:

    BonCommande(int idBonCommande, Commande* commande);
    BonCommande(const Entrepot& bonCommande);
    void ajouterProduits(int quantite, int id);
    int getQuantiteProduits(int id)const;
    int getIdBonCommande() const;
    Commande* getCommande()const;
    virtual ~BonCommande();
    void initialiser();
    BonCommande* clone() const;
private:
    int idBonCommande;
    Commande* commande;
    int quantiteProduits[5];
};

ostream& operator<<(ostream& os, const BonCommande& bonCommande);