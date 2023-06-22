#include "Explosion.h"


namespace ElementEspace {

	Explosion::Explosion()
		:ElementEspace("../Vaisseau/Resource/explosion.png")
	{
	}

	void Explosion::Demarrer(Coordonnees const& p_position)
	{
		Position = p_position;
		demaree = true;
	}

	void Explosion::MettreAJour(float temps)
	{
		if (demaree) {
			age += temps;
		}

		if (age < DUREE_VIE) 
		{
			sprite.setScale(age / DUREE_VIE, age / DUREE_VIE);
		}

		//ElementEspace::MettreAJour(temps);
	}

	void Explosion::Afficher(sf::RenderWindow& window) const
	{
		if (age < DUREE_VIE) {

			ElementEspace::Afficher(window);
		}
	}


	void Explosion::ReagirCollision()
	{
	}

}

