#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QString>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();

    virtual void activateScene() = 0;
    virtual void deactivateScene() = 0;

signals:
    void changeScene(QString sceneName);
};

#endif // SCENE_H
