#ifndef WEAPONRY_H
#define WEAPONRY_H

#include "Scene.h"


class Weaponry : public Scene
{
public:
    Weaponry();

    // Scene interface
public:
    void activateScene() override;
    void deactivateScene() override;
};

#endif // WEAPONRY_H
