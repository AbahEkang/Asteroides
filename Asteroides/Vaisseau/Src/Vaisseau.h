#pragma once

#include "SFML/Graphics.hpp"

namespace AstroVaisseau {

	class Vaisseau {


	public: 
		Vaisseau();
		Vaisseau(sf::Color couleur);
		void Afficher(sf::RenderWindow& window);
		void ActualiserEtat(sf::Event& event);

		//Update the distance move by the vessel on screen
		void MettreAJour(float temps);

	private:
		sf::Texture texture{};
		sf::Sprite sprite{};
		sf::Color color{sf::Color::Red};
		float vitesse{ 0.f };
		bool accelerationEnCours{false};
	};
}
