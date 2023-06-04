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
		static constexpr float ACCELERATION{ 7000.f };
		static constexpr float COEFF_FROTTEMENT{2.f}; //Coefficient of Friction
	};
}
