#include "Vecteur.h"


void AstroVaisseau::Vecteur::operator+=(Vecteur const& autre)
{
	x += autre.x;
	y += autre.y;
}

void AstroVaisseau::Vecteur::operator-=(Vecteur const& autre)
{
	x -= autre.x;
	y -= autre.y;
}

AstroVaisseau::Vecteur AstroVaisseau::Vecteur::operator*(float coefficient) const
{
	

	return Vecteur{ x*coefficient, y*coefficient };
}

//taille comes from acceleration * time which gives the distance
AstroVaisseau::Vecteur AstroVaisseau::Vecteur::CreerDepuisAngle(float taille, float angleEnDegree)
{
	return { taille * (float)cos((angleEnDegree/180.f) * M_PI), taille * (float)sin((angleEnDegree/180.f)* M_PI) };
}
