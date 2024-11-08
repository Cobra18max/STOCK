#pragma once
#include"Reception.h"
#include"RapportAssuranceQualite.h"
#include"Fournisseur.h"
#include"BonCommande.h"
#include"Entrepot.h"
#include"Client.h"
#include"Inventaire.h"
#include"Produit.h"
#include"ProduitA.h"
#include"ProduitB.h"
#include"ProduitC.h"
#include"ProduitD.h"
#include"ProduitE.h"
#include"Commande.h"
//#include"Reception.h"
//#include"RapportAssuranceQualite.h"

class Entreprise
{
private:
	Fournisseur fournisseur;
	static int numeroBonCommande;
	Entrepot entrepot;
	Inventaire inventaire;
	ProduitA* produireProduitA();
	ProduitB* produireProduitB();
	ProduitC* produireProduitC();
	ProduitD* produireProduitD();
	ProduitE* produireProduitE();
	void commanderComposantsFournisseur(int idComposant, int quantiteNecessaire);
	int genererNoBonCommande();

public:
	BonCommande* traiterCommande(Commande& commande);
	Reception* recupererCommande(BonCommande* bonCommande);
	void validerSatisfaction(RapportAssuranceQualite& aq, Client& client);

};

