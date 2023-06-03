#pragma once

#include "SFML/Graphics.hpp"

namespace AstroVaisseau {

	class Vaisseau {


	public: 
		Vaisseau();
		Vaisseau(sf::Color couleur);
		void avancer();
		void afficher(sf::RenderWindow& window);

	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Color color;
	};
}
