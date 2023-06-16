#include <iostream>
#include "Vaisseau.h"
#include "Coordonnees.h"
#include "Asteroides.h"
#include<array>

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


	
	auto vaisseau = ElementEspace::Vaisseau(sf::Color{0, 56, 235});

	auto Elements = std::array<ElementEspace::ElementEspace*, 4>{&asteroide1,&asteroide2, &asteroide3, &vaisseau};


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

		for (auto* element : Elements) {
			element->MettreAJour(tempsBoucle);
		}
		
		for (auto* element : Elements) {
			if (element != &vaisseau) {
				element->TesterCollision(vaisseau);
			}
		}


		fenetre.clear();
		
		for (auto* element : Elements) {

			//(*element).Afficher(fenetre);
			element->Afficher(fenetre);
		}

		

		fenetre.display();
	}


	return 0;
}