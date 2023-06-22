#pragma once
#include "Vecteur.h"
#include "Coordonnees.h"
#include "SFML/Graphics.hpp"
#include "ElementEspace.h"
#include "Explosion.h"

namespace ElementEspace {

	class Vaisseau : public ElementEspace
	{


	public: 
		//Vaisseau() = delete;
		using ElementEspace::ElementEspace;
		explicit Vaisseau(sf::Color const& couleur);
		
		void ActualiserEtat();

		virtual void ReagirCollision() override;
		virtual void Afficher(sf::RenderWindow& window) const override;
	
	protected:
		virtual void MettreAJour(const float temps) override;


	private:
	
		sf::Color color{sf::Color::Red};
		bool accelerationEnCours{false};

		//Directions
		bool TourneAGauche{ false };
		bool TourneADroite{ false };

		//Static constants
		static constexpr float ACCELERATION{ 7000.f };
		static constexpr float COEFF_FROTTEMENT{2.f}; //Coefficient of Friction
		static constexpr float VITESSE_ANGULAIRE{50.f};

		//React to collision
		bool detruit{ false };

		Explosion explosion{};

	};
}
