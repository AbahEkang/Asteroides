#include "Explosion.h"


namespace ElementEspace {

	Explosion::Explosion(Coordonnees const& p_position)
		:ElementEspace("../Vaisseau/Resource/explosion.png")
	{
		Position = p_position;
	}

	

	void Explosion::MettreAJour(float temps)
	{
		age += temps;

		if (age < DUREE_VIE) 
		{
			sprite.setScale(age / DUREE_VIE, age / DUREE_VIE);
		}
		else {
			detruit = true;  //intended for method IsDestroyed of class Espace
		}

		//ElementEspace::MettreAJour(temps);
	}


	void Explosion::ReagirCollision(ElementEspaceType typeAutre)
	{
	}

}

