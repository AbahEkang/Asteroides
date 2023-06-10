#include "ElementEspace.h"
#include<array>


ElementEspace::ElementEspace::ElementEspace(std::string_view const& image)
	:path_to_image(image)
{

	
	if (!texture.loadFromFile(path_to_image.data())) {
		std::cerr;
	}
	sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);

	sprite.setPosition(Position.getX(), Position.getY());
	sprite.setTexture(texture);

}



void ElementEspace::ElementEspace::Afficher(sf::RenderWindow& window) const
{

	auto affichages = std::array<Vecteur, 9>
	{
		Vecteur{ -1, -1 }, Vecteur{ 0, -1 }, Vecteur{ 1, -1 },
			Vecteur{ -1, 0 }, Vecteur{ 0, 0 }, Vecteur{ 1, 0 },
			Vecteur{ -1, 1 }, Vecteur{ 0, 1 }, Vecteur{ 1, 1 }
	};

	for (auto& affichage : affichages) {
		
		auto transformation = sf::Transform{};
		transformation.translate(affichage.x * Coordonnees::getLimitX(), affichage.y * Coordonnees::getLimitY());

		window.draw(sprite, transformation);

	}

}

void ElementEspace::ElementEspace::MettreAJour(const float temps)
{
	auto deplacement = vitesse * temps;
	Position += deplacement;


	//Distance is Velocity x time
	//Where is the object located on the x - y axis
	sprite.setPosition(Position.getX(), Position.getY());
}
