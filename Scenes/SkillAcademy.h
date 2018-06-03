#ifndef SKILLACADEMY_H
#define SKILLACADEMY_H

#include "Scene.h"


class SkillAcademy : public Scene
{
public:
    SkillAcademy();

    // Scene interface
public:
    void activateScene() override;
    void deactivateScene() override;
};

#endif // SKILLACADEMY_H
