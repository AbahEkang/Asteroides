#include <iostream>
#include "Vaisseau.h"
#include "Coordonnees.h"
#include "Asteroides.h"


constexpr float LONGUEUR_FENETRE{ 800.f };
constexpr float HAUTEUR_FENETRE{ 600.f };


int main(int argc, char* argv[])
{

	std::cout << R"(Bienvenu sur "Asteroides"!)" << std::endl;

	const auto DIM_FENETRE = sf::VideoMode{ 800, 600 };
	const auto TITRE = "ASTEROIDES";

	sf::RenderWindow fenetre{ DIM_FENETRE,  TITRE };

	ElementEspace::Coordonnees::InitialiserEspace(LONGUEUR_FENETRE, HAUTEUR_FENETRE);

	auto asteroide = ElementEspace::Asteroides{ };
	auto vaisseau = ElementEspace::Vaisseau(sf::Color{235, 56, 0});

	//Time to be used to calculate movement, and velocity
	auto chrono = sf::Clock{};

	while (fenetre.isOpen())
	{
		auto event = sf::Event();

		while (fenetre.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				fenetre.close();
			}

		}
		
		vaisseau.ActualiserEtat();


		//Restart the chrono at every new loop
		auto tempsBoucle = chrono.restart().asSeconds();

		asteroide.MettreAJour(tempsBoucle);
		vaisseau.MettreAJour(tempsBoucle);


		fenetre.clear();
		asteroide.Afficher(fenetre);

		vaisseau.Afficher(fenetre);

		fenetre.display();

	}


	return 0;
}