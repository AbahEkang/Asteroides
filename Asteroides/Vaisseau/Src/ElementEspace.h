#pragma once
#include "Coordonnees.h"
#include "Vecteur.h"
#include<SFML/Graphics.hpp>


namespace ElementEspace {

	class ElementEspace
	{

	public:
		virtual ~ElementEspace() = default;
		explicit ElementEspace(std::string_view const& path_to_image);
		ElementEspace(ElementEspace const&) = delete;

		//Delete operator to be sure to not create copies
		void operator=(ElementEspace const&) = delete;

		void Afficher(sf::RenderWindow& window) const;

		float getRayon() const;

		//If collision, change sprite color to red
		void TesterCollision(ElementEspace& autre);

		//Update the distance moved by the vessel on screen
		virtual void MettreAJour(const float temps);

	protected:
		sf::Texture texture{};
		sf::Sprite sprite{};
		Vecteur vitesse{ 0.f, 0.f };
		std::string_view const& path_to_image{};

		//Coordinates
		Coordonnees Position{};

		float angularVelocity{};

	};

}
