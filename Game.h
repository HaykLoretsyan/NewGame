#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QMap>
#include <QString>
#include <QHostInfo>

#include "Scenes/Scene.h"
#include "Scenes/Intro.h"
#include "Scenes/City.h"

#include "PlayerAttributes/Player.h"


class Game : public QObject
{
    Q_OBJECT

private:
    Game();
    ~Game();

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

    /**
     * @brief addTheScene adding scene with sceneName to scenes' list
     * @param sceneName
     * @param scene
     */
    void addTheScene(QString sceneName, Scene *scene);

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

private:
    Player* m_player;
};

#endif // SCENEMANAGER_H
