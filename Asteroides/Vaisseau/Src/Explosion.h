#pragma once
#include "ElementEspace.h"
#include "Coordonnees.h"


namespace ElementEspace {
	class Explosion : public ElementEspace
	{
	public:
		Explosion();
		void Demarrer(Coordonnees const& p_position);
		virtual void Afficher(sf::RenderWindow& window) const;
		virtual void ReagirCollision() override;
	
	protected:
		virtual void MettreAJour(const float temps) override;


	private:
		bool demaree{ false };
		float age{};
		static constexpr float DUREE_VIE{ 0.1f };
	};


}
