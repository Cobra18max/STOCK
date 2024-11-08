#ifndef RECEPTION_H
#define RECEPTION_H



#pragma once
#include "BonCommande.h"
#include "Composant.h"
#include <string>

class Reception
{
	private:
		list<Produit*> produits[5];
		BonCommande* bonCommande;

	public:
		~Reception();
		Reception(BonCommande* bonCommande);
		void ajouterProduit(Produit* produit, int id);
		Reception(const Reception& Reception) = delete;
		friend ostream& operator<<(ostream& out, const Reception& reception);
		BonCommande* getBonCommande() const;
		int getQuantiteProduitsRecus(int id) const;
		const list<Produit*>& getProduits(int idProduit) const;

};

#endif // !