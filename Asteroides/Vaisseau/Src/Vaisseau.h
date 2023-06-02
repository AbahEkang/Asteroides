#pragma once

#include "SFML/Graphics.hpp"

namespace AstroVaisseau {

	class Vaisseau {


	public: 
		void avancer();
		void afficher(sf::RenderWindow& window);

	private:
		sf::CircleShape triangle{ 45, 4 };
		sf::Color color{ 23, 45, 213 };
	};
}
