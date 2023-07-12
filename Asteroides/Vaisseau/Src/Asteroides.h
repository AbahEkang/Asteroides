#pragma once
#include<SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"
#include "ElementEspace.h"
#include "Espace.h"
#include <random>



namespace ElementEspace {

	class Asteroides : public ElementEspace
	{

	public:
		using ElementEspace::ElementEspace;
		explicit Asteroides(Espace::Espace& p_espace, Asteroides* parent = nullptr );
		virtual void ReagirCollision(ElementEspaceType typeAutre) override;

	private:
		Espace::Espace& espace;

	};

}


