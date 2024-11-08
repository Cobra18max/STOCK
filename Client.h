#include"Reception.h"
#include"BonCommande.h"
#include"Commande.h"
#include"Produit.h"


#pragma once
class Client
{
public:
	Client(string nom,int seuilQualite);
	Client(const Client& client);
	~Client();
	Commande getCommande(int id)const;
	Reception*getReception() const;
	int getSeuilQualite()const;
	string getNom() const;
	void recevoirCommande(Reception* reception);
	void consommerProduits();
	int getSatisfactionProduits(int idProduit)const;
	friend ostream& operator<<(ostream& out, const Client& client);
private:
	string nom;
	int seuilQualite;
	Reception* reception;
	Commande* commandesA2024[4];
	void preparerCommande2024();

};

