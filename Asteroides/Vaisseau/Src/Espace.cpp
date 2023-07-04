#include "Espace.h"


namespace Espace {
	Espace::Espace()
	{
	}

	void Espace::Ajouter(std::unique_ptr<ElementEspace::ElementEspace> element)
	{
		//Move (not copy) of the unique pointer
		Elements.push_back(std::move(element));
	}

	void Espace::Actualiser()
	{

		//Restart the chrono at every new loop
		auto tempsBoucle = chrono.restart().asSeconds();

		for (auto i{ 0u}; i < Elements.size(); i++) {
			Elements[i]->Actualiser(tempsBoucle);
		}
	}

	void Espace::GererCollision()
	{

		for (auto i = 0; i < Elements.size(); i++) {
			for (auto j = 0; j < Elements.size(); j++) {
				if (Elements[i] != Elements[j]) {
					Elements[i]->TesterCollision(*Elements[j]);
				}
			}

		}
	}

	void Espace::Afficher(sf::RenderWindow& fenetre) const
	{

		for (auto& element : Elements) {

			//(*element).Afficher(fenetre);
			element->Afficher(fenetre);
		}
	}
	void Espace::CleanDestroyed()
	{
		//Place all destroyed elements at the end of vector 
		auto end_of_vector = std::remove_if(std::begin(Elements), std::end(Elements), ElementEspace::ElementEspace::IsDestroyed);

		Elements.erase(end_of_vector, std::end(Elements));
	}
}