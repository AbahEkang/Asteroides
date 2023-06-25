#pragma once

#include "ElementEspace.h"
#include<vector>


namespace Espace {

	class Espace
	{

	public:
		Espace();
		void Ajouter(ElementEspace::ElementEspace&);
		void Actualiser();
		void GererCollision();
		void Afficher(sf::RenderWindow&) const;
		void CleanDestroyed();

	protected:

	private:

		std::vector<ElementEspace::ElementEspace*> Elements{};
		sf::Clock chrono{};
	};

}