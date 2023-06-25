#include <iostream>
#include "Vaisseau.h"
#include "Coordonnees.h"
#include "Asteroides.h"
#include "Espace.h"
#include<vector>

constexpr float LONGUEUR_FENETRE{ 800.f };
constexpr float HAUTEUR_FENETRE{ 600.f };


int main(int argc, char* argv[])
{

	std::cout << R"(Bienvenu sur "Asteroides"!)" << std::endl;

	const auto DIM_FENETRE = sf::VideoMode{ 800, 600 };
	const auto TITRE = "ASTEROIDES";

	sf::RenderWindow fenetre{ DIM_FENETRE,  TITRE };

	ElementEspace::Coordonnees::InitialiserEspace(LONGUEUR_FENETRE, HAUTEUR_FENETRE);

	auto asteroide1 = ElementEspace::Asteroides{ };
	auto asteroide2 = ElementEspace::Asteroides{ };
	auto asteroide3 = ElementEspace::Asteroides{ };

	auto espace = Espace::Espace{};

	
	auto vaisseau = ElementEspace::Vaisseau(espace, sf::Color{0, 56, 235});

	//auto Elements = std::vector<ElementEspace::ElementEspace*>{};


	auto partieDemarree{ false };

	//Time to be used to calculate movement, and velocity

	while (fenetre.isOpen())
	{
		auto event = sf::Event();

		while (fenetre.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				fenetre.close();
			}

			if (event.type == sf::Event::KeyPressed && !partieDemarree)
			{
				espace.Ajouter(vaisseau);
				espace.Ajouter(asteroide1);
				espace.Ajouter(asteroide2);
				espace.Ajouter(asteroide3);

				partieDemarree = true;
			}

		}
		
		espace.Actualiser();
		espace.GererCollision();
		espace.CleanDestroyed();

		fenetre.clear();
		
		espace.Afficher(fenetre);

		fenetre.display();
	}


	return 0;
}