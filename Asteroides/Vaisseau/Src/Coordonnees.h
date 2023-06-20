#pragma once
#include<iostream>
#include "Vecteur.h"
#include <cmath>

namespace ElementEspace {

	class Coordonnees
	{
	public:

		explicit Coordonnees();
		explicit Coordonnees(float, float);

		float getX() const;

		float getY() const;

		static float getLimitX();

		static float getLimitY();

		static void InitialiserEspace(const float longueur, const float hauteur);

		float CalculerDistance(Coordonnees const& autre) const;

		Vecteur operator +=(const Vecteur vector);

	private:
		float x{0.f};
		float y{0.f};

		static float LimitX;
		static float LimitY;
	};


}

