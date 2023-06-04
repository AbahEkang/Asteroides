#include "Vaisseau.h"
#include <iostream>

namespace AstroVaisseau {


	Vaisseau::Vaisseau()
	{
		if (!texture.loadFromFile("../Vaisseau/Resource/vaisseau.png"))
		{
			std::cerr;
		}

		sprite.setTexture(texture);
		sprite.setColor(color);
		sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		sprite.setPosition(50, 50);

	}
	Vaisseau::Vaisseau(sf::Color const& couleur)
		: Vaisseau()
	{
		color = couleur;
		
		//if (!texture.loadFromFile("../Vaisseau/Resource/vaisseau.png"))
		//{
		//	std::cerr;
		//}

		//sprite.setTexture(texture);
		//sprite.setColor(color);

		////Setting center of rotation
		//sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		//sprite.setPosition( 50, 50 );
	}
	

	void Vaisseau::Afficher(sf::RenderWindow& window) const {
		window.draw(sprite);
	}
	void Vaisseau::ActualiserEtat()
	{
		accelerationEnCours = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);

		TourneAGauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		TourneADroite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

	}

	//Update the distance move by the vessel on screen
	void Vaisseau::MettreAJour(const float temps)
	{

		if (accelerationEnCours) {

			//Velocity is Acceleration x time
			//Move according to the angle of rotation
			vitesse += Vecteur::CreerDepuisAngle(ACCELERATION * temps, sprite.getRotation());
		}

		//Deceleration is velocity x friction x time
		vitesse -= vitesse * COEFF_FROTTEMENT * temps;

		//Movement in the axis measure of the distance covered in certain time at given velocity
		auto deplacement = vitesse * temps;



		//Distance is Velocity x time
		//Where is the object located on the x - y axis
		sprite.move( deplacement.x, deplacement.y );

		//Turn left or right
		if (TourneADroite) {

			//To the right, turns clockwise => positive angle
			sprite.rotate(VITESSE_ANGULAIRE * temps);
		}

		if (TourneAGauche) {
			//To the left, turns anti-clockwise => negative angle
			//Gives position of the sprite according to angular velocity and time employed to rotate 
			sprite.rotate(-VITESSE_ANGULAIRE * temps);
		}
	}
}