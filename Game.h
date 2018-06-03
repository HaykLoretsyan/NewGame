#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QMap>
#include <QString>
#include <QSettings>
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>

#include "Scenes/Scene.h"
#include "Scenes/Intro.h"
#include "Scenes/City.h"


class Game : public QObject
{
    Q_OBJECT

private:
    Game();

public:
    static Game& instance() {
        static Game game;

        return game;
    }

    /**
     * @brief init initializing the game
     * @return
     */
    Scene* init();

public slots:
    /**
     * @brief changeToScene changes to requested scene
     * @param sceneName
     */
    void changeToScene(QString sceneName);

private:
    /**
     * @brief addScene adding new scene with name 'name'
     * @param name
     * @param scene
     */
    void addScene(QString name, Scene* scene);

    /**
     * @brief intro introduction gif
     * @return
     */
    QLabel* intro();

    /**
     * @brief createScene create scene according to name 'name'
     * @param name
     * @return
     */
    Scene* createScene(QString name);

signals:
    void sceneChanged(Scene* scene);

private:
    QMap<QString, Scene*> m_scenes;
};

#endif // SCENEMANAGER_H
