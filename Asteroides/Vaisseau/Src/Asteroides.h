#pragma once
#include<SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"
#include "ElementEspace.h"
#include <random>



namespace ElementEspace {

	class Asteroides : public ElementEspace
	{

	public:
		using ElementEspace::ElementEspace;
		Asteroides();

	};

}


