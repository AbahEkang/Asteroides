#include "Vecteur.h"


void ElementEspace::Vecteur::operator+=(Vecteur const& autre)
{
	x += autre.x;
	y += autre.y;
}

void ElementEspace::Vecteur::operator-=(Vecteur const& autre)
{
	x -= autre.x;
	y -= autre.y;
}

ElementEspace::Vecteur ElementEspace::Vecteur::operator*(float coefficient) const
{
	

	return Vecteur{ x*coefficient, y*coefficient };
}

//taille comes from acceleration * time which gives the distance
ElementEspace::Vecteur ElementEspace::Vecteur::CreerDepuisAngle(float taille, float angleEnDegree)
{
	return { taille * (float)cos((angleEnDegree/180.f) * M_PI), taille * (float)sin((angleEnDegree/180.f)* M_PI) };
}
