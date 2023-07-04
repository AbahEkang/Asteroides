#include "Missile.h"

namespace ElementEspace {

	Missile::Missile(Coordonnees const& p_position, float rotation): ElementEspace("../Vaisseau/Resource/missile.png")
	{
		type = ElementEspaceType::MISSILE;
		Position = p_position;
		sprite.setRotation(rotation);
		vitesse = Vecteur::CreerDepuisAngle(VITESSE, rotation);
	}

	void Missile::ReagirCollision(ElementEspaceType typeAutre)
	{
		if (typeAutre != ElementEspaceType::VAISSEAU) {
			detruit = true;
		}
	}

}
