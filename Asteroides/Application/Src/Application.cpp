#include <iostream>
#include "Vaisseau.h"




int main(int argc, char* argv[])
{

	std::cout << R"(Bienvenu sur "Asteroides"!)" << std::endl;

	const auto DIM_FENETRE = sf::VideoMode{ 800, 600 };
	const auto TITRE = "ASTEROIDES";

	sf::RenderWindow fenetre{ DIM_FENETRE,  TITRE };


	auto vaisseau = AstroVaisseau::Vaisseau(sf::Color{235, 56, 0});

	while (fenetre.isOpen())
	{
		auto event = sf::Event();

		while (fenetre.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				fenetre.close();
			}

			if (event.type == sf::Event::KeyPressed) {
				vaisseau.avancer();
			}
		}

		fenetre.clear();
		vaisseau.afficher(fenetre);
		fenetre.display();

	}


	return 0;
}