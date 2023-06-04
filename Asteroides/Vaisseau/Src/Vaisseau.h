#pragma once

#include "SFML/Graphics.hpp"

namespace AstroVaisseau {

	class Vaisseau {


	public: 
		Vaisseau();
		Vaisseau(sf::Color const& couleur);
		void Afficher(sf::RenderWindow& window) const;
		void ActualiserEtat(sf::Event const& event);

		//Update the distance move by the vessel on screen
		void MettreAJour(const float temps);

	private:
		sf::Texture texture{};
		sf::Sprite sprite{};
		sf::Color color{sf::Color::Red};
		float vitesse{ 0.f };
		bool accelerationEnCours{false};
		static const float ACCELERATION;
		static const float COEFF_FROTTEMENT; //Coefficient of Friction
	};
}
