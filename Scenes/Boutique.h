#ifndef BOUTIQUE_H
#define BOUTIQUE_H

#include "Scene.h"


class Boutique : public Scene
{
public:
    Boutique();

    // Scene interface
public:
    void activateScene() override;
    void deactivateScene() override;
};

#endif // BOUTIQUE_H
