#pragma once
#include "ElementEspace.h"

namespace ElementEspace {
    class Missile : public ElementEspace
    {
    public:
        Missile(Coordonnees const& p_position, float rotation);
        virtual void ReagirCollision(ElementEspaceType typeAutre) override;

    private:

        static constexpr float VITESSE{ 2000.f };
    };

}

