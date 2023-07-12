#include "Asteroides.h"
#include "Explosion.h"


ElementEspace::Asteroides::Asteroides(Espace::Espace& p_espace, Asteroides* parent)
	:ElementEspace::ElementEspace("../Vaisseau/Resource/asteroide.png"), espace(p_espace)
{
	type = ElementEspaceType::ASTEROIDE;
	auto generator = std::random_device{};
	auto distributionPosition = std::uniform_real_distribution<float>{ -150, 150 };
	auto distributionVelocity = std::uniform_real_distribution<float>{ 80, 120 };
	auto distributionAngle = std::uniform_real_distribution<float>{ 0, 360 };

	auto distributionAngularVelocity = std::uniform_real_distribution<float>{10, 30};
	

	// If parent is not null we initialize 'Asteroid' position differently
	//Position = { distributionPosition(generator), distributionPosition(generator) };

	vitesse = Vecteur::CreerDepuisAngle( distributionVelocity(generator), distributionAngle(generator) );

	
	angularVelocity = distributionAngularVelocity(generator);

	if (parent)
	{

		sprite.setScale(parent->sprite.getScale().x / 1.4, parent->sprite.getScale().y / 1.4);

		Position = parent->Position;
	}
	else
	{
		Position = { distributionPosition(generator), distributionPosition(generator) };

	}
}

void ElementEspace::Asteroides::ReagirCollision(ElementEspaceType typeAutre)
{
	if (typeAutre == ElementEspaceType::MISSILE)
	{
		detruit = true;
		espace.Ajouter(std::make_unique<Explosion>(Position));

		//Divide the asteroide on impact with missile
		if (sprite.getScale().x > 0.1) {
			espace.Ajouter(std::make_unique<Asteroides>(espace, this));
			espace.Ajouter(std::make_unique<Asteroides>(espace, this));

		}
		
	}
}

