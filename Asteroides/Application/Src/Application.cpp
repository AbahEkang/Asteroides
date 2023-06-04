#include <iostream>
#include "Vaisseau.h"




int main(int argc, char* argv[])
{

	std::cout << R"(Bienvenu sur "Asteroides"!)" << std::endl;

	const auto DIM_FENETRE = sf::VideoMode{ 800, 600 };
	const auto TITRE = "ASTEROIDES";

	sf::RenderWindow fenetre{ DIM_FENETRE,  TITRE };


	auto vaisseau = AstroVaisseau::Vaisseau(sf::Color{235, 56, 0});

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
		vaisseau.MettreAJour(chrono.restart().asSeconds());

		fenetre.clear();
		vaisseau.Afficher(fenetre);
		fenetre.display();

	}


	return 0;
}