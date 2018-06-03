#ifndef INTRO_H
#define INTRO_H

#include <QApplication>
#include <QDesktopWidget>
#include <QMovie>
#include <QLabel>

#include "ResourceManager.h"
#include "Scene.h"


class Intro : public Scene
{
public:
    Intro();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    QMovie* introMovie;

    // Scene interface
public:
    void activateScene() override;
    void deactivateScene() override;
};

#endif // INTRO_H
