#include "Vaisseau.h"
#include <iostream>

namespace ElementEspace {
	
	
	Vaisseau::Vaisseau(Espace::Espace& p_espace, sf::Color const& couleur)
		:ElementEspace::ElementEspace("../Vaisseau/Resource/vaisseau.png"),
		espace(p_espace)
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

	void Vaisseau::ReagirCollision()
	{
		if (!detruit) {
			detruit = true;
			explosion.Demarrer(Position);
			espace.Ajouter(explosion);
		}
		
	}

	//void Vaisseau::Afficher(sf::RenderWindow& window) const 
	//{
	//	if (!detruit) {
	//		ElementEspace::Afficher(window);
	//	}
	//	else {
	//		explosion.Afficher(window);
	//	}

	//}


	//Update the distance move by the vessel on screen
	void Vaisseau::MettreAJour(const float temps)
	{
		ActualiserEtat();


		if (!detruit)
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

			//Turn left or right
			if (TourneADroite) {

				//To the right, turns clockwise => positive angle
				angularVelocity = VITESSE_ANGULAIRE;
			}
			else if (TourneAGauche) {
				//To the left, turns anti-clockwise => negative angle
				//Gives position of the sprite according to angular velocity and time employed to rotate 
				angularVelocity -= VITESSE_ANGULAIRE;
				
			}
			else {
				angularVelocity = 0;
			}

		}
		

		


	}
}