#include "Vaisseau.h"
#include <iostream>

namespace AstroVaisseau {

	const float ACCELERATION{ 7000.f };
	const float COEFF_FROTTEMENT{ 2.f };

	Vaisseau::Vaisseau()
	{
		if (!texture.loadFromFile("../Vaisseau/Resource/vaisseau.png"))
		{
			std::cerr;
		}

		sprite.setTexture(texture);
		sprite.setColor(color);
	}
	Vaisseau::Vaisseau(sf::Color const& couleur)
		: color(couleur)
	{
		
		if (!texture.loadFromFile("../Vaisseau/Resource/vaisseau.png"))
		{
			std::cerr;
		}

		sprite.setTexture(texture);
		sprite.setColor(color);

	}
	

	void Vaisseau::Afficher(sf::RenderWindow& window) const {
		window.draw(sprite);
	}
	void Vaisseau::ActualiserEtat(sf::Event const& event)
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
	void Vaisseau::MettreAJour(const float temps)
	{

		if (accelerationEnCours) {

			//Velocity is Acceleration x time
			vitesse += 7000.f * temps;
		}

		//Deceleration is velocity x friction x time
		vitesse -= vitesse * 2.f * temps;



		//Distance is Velocity x time
		sprite.move(vitesse * temps, 0);
	}
}