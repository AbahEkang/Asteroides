#pragma once
#include "Vecteur.h"
#include "Coordonnees.h"
#include "SFML/Graphics.hpp"

namespace AstroVaisseau {

	class Vaisseau {


	public: 
		Vaisseau();
		Vaisseau(sf::Color const& couleur);
		void Afficher(sf::RenderWindow& window) const;
		void ActualiserEtat();

		//Update the distance move by the vessel on screen
		void MettreAJour(const float temps);

	private:
		sf::Texture texture{};
		sf::Sprite sprite{};
		sf::Color color{sf::Color::Red};
		Vecteur vitesse{0.f, 0.f };
		bool accelerationEnCours{false};

		//Coordinates
		Coordonnees Position{};

		//Directions
		bool TourneAGauche{ false };
		bool TourneADroite{ false };

		//Static constants
		static constexpr float ACCELERATION{ 7000.f };
		static constexpr float COEFF_FROTTEMENT{2.f}; //Coefficient of Friction
		static constexpr float VITESSE_ANGULAIRE{50.f};
	};
}
