#pragma once
#include "Coordonnees.h"
#include "Vecteur.h"
#include<SFML/Graphics.hpp>


namespace ElementEspace {


	enum class ElementEspaceType{VAISSEAU, MISSILE, ASTEROIDE, AUTRE};

	class ElementEspace
	{

	public:
		virtual ~ElementEspace() = default;
		explicit ElementEspace(std::string_view const& path_to_image);
		ElementEspace(ElementEspace const&) = delete;

		//Delete operator to be sure to not create copies
		void operator=(ElementEspace const&) = delete;

		virtual void Afficher(sf::RenderWindow& window) const;

		float getRayon() const;

		//If collision, change sprite color to red
		void TesterCollision(ElementEspace& autre);

		virtual void ReagirCollision(ElementEspaceType type) = 0;

		void Actualiser(float temps);
		
		static inline bool IsDestroyed(std::unique_ptr<ElementEspace>& element) { return element->detruit; }

	protected:

		//Update the distance moved by the vessel on screen
		virtual void MettreAJour(const float temps);
		ElementEspaceType type{ ElementEspaceType::AUTRE };

		sf::Texture texture{};
		sf::Sprite sprite{};
		Vecteur vitesse{ 0.f, 0.f };
		std::string_view const& path_to_image{};

		//Coordinates
		Coordonnees Position{};

		float angularVelocity{};

		bool detruit{ false };


	};

}
