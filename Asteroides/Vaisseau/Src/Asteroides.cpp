#include "Asteroides.h"



ElementEspace::Asteroides::Asteroides()
	:ElementEspace::ElementEspace("../Vaisseau/Resource/asteroide.png")
{
	auto generator = std::random_device{};
	auto distributionPosition = std::uniform_real_distribution<float>{ -150, 150 };
	auto distributionVelocity = std::uniform_real_distribution<float>{ 80, 120 };
	auto distributionAngle = std::uniform_real_distribution<float>{ 0, 360 };

	auto distributionAngularVelocity = std::uniform_real_distribution<float>{10, 30};
	
	Position = { distributionPosition(generator), distributionPosition(generator) };

	vitesse = Vecteur::CreerDepuisAngle( distributionVelocity(generator), distributionAngle(generator) );

	
	angularVelocity = distributionAngularVelocity(generator);
}

