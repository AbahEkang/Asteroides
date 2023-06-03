#include "Vaisseau.h"
#include <iostream>

namespace AstroVaisseau {
	Vaisseau::Vaisseau()
	{
		texture.loadFromFile("../Vaisseau/Resource/vaisseau.png");

		sprite.setTexture(texture);
	}
	Vaisseau::Vaisseau(sf::Color couleur)
		: color(couleur)
	{
		
		texture.loadFromFile("../Vaisseau/Resource/vaisseau.png");
		sprite.setTexture(texture);

	}
	void Vaisseau::avancer() {
		sprite.move(10, 0);

	}

	void Vaisseau::afficher(sf::RenderWindow& window) {
		window.draw(sprite);
	}
}