#include "Coordonnees.h"
#include "Vaisseau.h"
#include<algorithm>



namespace ElementEspace {

    float Coordonnees::LimitX = 0.f;
    float Coordonnees::LimitY = 0.f;


    Coordonnees::Coordonnees()
        :x(Coordonnees::LimitX/2), y(Coordonnees::LimitY/2)
    {

    }
    Coordonnees::Coordonnees(float X, float Y)
        :x(X), y(Y)
    {
    }
    float Coordonnees::getX() const
    {
        return x;
    }

    float Coordonnees::getY() const
    {
        return y;
    }
    float Coordonnees::getLimitX()
    {
        return LimitX;
    }
    float Coordonnees::getLimitY()
    {
        return LimitY;
    }
    void Coordonnees::InitialiserEspace(const float longueur, const float hauteur)
    {
        /*if (longueur != 0 || hauteur != 0) {
            std::cerr << "Attention: l'espace est deja initialise\n";
        }*/
        if(longueur > 0.f ) {
            Coordonnees::LimitX = longueur;
        }
        else {
            std::cerr;
        }
        

        if (hauteur > 0.f) {
            Coordonnees::LimitY = hauteur;
        }
        else {
            std::cerr;
        }
        
    }
    float Coordonnees::CalculerDistance(Coordonnees const& autre) const
    {

        //We want to catter for screen limits(lower and upper)
        auto delta = Vecteur{
            std::min({abs(x - autre.x), abs(x - autre.x - LimitX), abs(x - autre.x + LimitX)}),
            std::min({abs(y - autre.y), abs(y - autre.y - LimitY), abs(y - autre.y + LimitY)})
        };

       

        return sqrt((delta.x * delta.x) + (delta.y * delta.y));
    }

    Vecteur Coordonnees::operator+=(const Vecteur vector)
    {


        x += vector.x;

        y += vector.y;

        if (x >= Coordonnees::LimitX) {
            x = x - Coordonnees::LimitX;
        }
        if (x <= 0) {
            x = Coordonnees::LimitX;
        }

        if (y >= Coordonnees::LimitY) {
            y = y - Coordonnees::LimitY;
        }
        else if (y <= 0) {
            y = Coordonnees::LimitY;
        }
        return { x, y };
    }   
}

