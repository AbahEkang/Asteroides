#pragma once

#include "ElementEspace.h"
#include<vector>


namespace Espace {

	class Espace
	{

	public:
		Espace();
		void Ajouter(std::unique_ptr<ElementEspace::ElementEspace>);
		void Actualiser();
		void GererCollision();
		void Afficher(sf::RenderWindow&) const;
		void CleanDestroyed();

	protected:

	private:

		std::vector<std::unique_ptr<ElementEspace::ElementEspace>> Elements{};
		std::vector<std::unique_ptr<ElementEspace::ElementEspace>> toBeAdded{};
		sf::Clock chrono{};
	};

}