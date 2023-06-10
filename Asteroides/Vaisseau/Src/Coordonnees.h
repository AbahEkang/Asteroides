#pragma once
#include<iostream>
#include "Vecteur.h"


namespace ElementEspace {

	class Coordonnees
	{
	public:

		Coordonnees();
		float getX() const;
		float getY() const;
		static float getLimitX();
		static float getLimitY();
		static void InitialiserEspace(const float longueur, const float hauteur);

		Vecteur operator +=(const Vecteur vector);

	private:
		float x{0.f};
		float y{0.f};

		static float LimitX;
		static float LimitY;
	};


}

