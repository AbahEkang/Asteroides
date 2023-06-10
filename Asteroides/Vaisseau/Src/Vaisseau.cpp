#include "Vaisseau.h"
#include <iostream>

namespace ElementEspace {
	
	
	Vaisseau::Vaisseau(sf::Color const& couleur)
		:ElementEspace::ElementEspace("../Vaisseau/Resource/vaisseau.png")
	{
		//color = couleur;
		sprite.setColor(sf::Color(couleur));
		
		
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
		//auto deplacement = vitesse * temps;
		//Position += deplacement;

		//
		////Distance is Velocity x time
		////Where is the object located on the x - y axis
		//sprite.setPosition(Position.getX(), Position.getY());

		//Don't Repeat yourself
		ElementEspace::MettreAJour(temps);

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