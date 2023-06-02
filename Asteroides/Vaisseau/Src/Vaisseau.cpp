#include "Vaisseau.h"

namespace AstroVaisseau {

	void Vaisseau::avancer() {
		triangle.move(10, 0);

	}

	void Vaisseau::afficher(sf::RenderWindow& window) {
		triangle.setFillColor( color );
		window.draw(triangle);
	}
}