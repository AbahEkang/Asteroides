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

float ElementEspace::ElementEspace::getRayon() const
{
	return sprite.getLocalBounds().height / 2.f;
}

void ElementEspace::ElementEspace::TesterCollision(ElementEspace& autre)
{
	//Distance within center of the two objects
	auto distance = Position.CalculerDistance(autre.Position);

		if (distance < this->getRayon() + autre.getRayon()) 
		{
			/*sprite.setColor(sf::Color::Red);
			autre.sprite.setColor(sf::Color::Red);*/
			ReagirCollision();

		}
}



void ElementEspace::ElementEspace::Actualiser(const float temps)
{
	MettreAJour(temps);

	auto deplacement = vitesse * temps;
	Position += deplacement;


	//Distance is Velocity x time
	//Where is the object located on the x - y axis


	sprite.setPosition(Position.getX(), Position.getY());

	sprite.rotate(angularVelocity * temps);


}

void ElementEspace::ElementEspace::MettreAJour(float temps)
{}
