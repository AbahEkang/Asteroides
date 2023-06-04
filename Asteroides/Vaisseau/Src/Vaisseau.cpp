#include "Vaisseau.h"
#include <iostream>

namespace AstroVaisseau {
	Vaisseau::Vaisseau()
	{
		if (!texture.loadFromFile("../Vaisseau/Resource/vaisseau.png"))
		{
			std::cerr;
		}

		sprite.setTexture(texture);
		sprite.setColor(color);
	}
	Vaisseau::Vaisseau(sf::Color couleur)
		: color(couleur)
	{
		
		if (!texture.loadFromFile("../Vaisseau/Resource/vaisseau.png"))
		{
			std::cerr;
		}

		sprite.setTexture(texture);
		sprite.setColor(color);

	}
	

	void Vaisseau::Afficher(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	void Vaisseau::ActualiserEtat(sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
			accelerationEnCours = true;
		}
		else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
		{
			accelerationEnCours = false;
		}

	}

	//Update the distance move by the vessel on screen
	void Vaisseau::MettreAJour(float temps)
	{

		if (accelerationEnCours) {

			//Velocity is Acceleration x time
			vitesse += 7000.f * temps;
		}

		//Distance is Velocity x time
		sprite.move(vitesse * temps, 0);
	}
}