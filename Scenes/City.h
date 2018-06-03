#ifndef CITY_H
#define CITY_H

#include "Scene.h"


class City : public Scene
{
public:
    City();

    // Scene interface
public:
    void activateScene() override;
    void deactivateScene() override;
};

#endif // CITY_H
