#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
namespace AstroVaisseau {


	struct Vecteur {

		void operator +=(Vecteur const& autre);
		void operator -=(Vecteur const& autre);
		Vecteur operator *(float coefficient) const;

		//taille comes from acceleration * time which gives the distance
		static Vecteur CreerDepuisAngle(float taille, float angleEnDegree); 

		float x{ 0.f };
		float y{ 0.f };


	};
}
