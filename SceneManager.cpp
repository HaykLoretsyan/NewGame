#include "SceneManager.h"

SceneManager::SceneManager()
{

}

void SceneManager::addScene(QString name, QGraphicsScene *scene)
{
    m_scenes.insert(name, scene);
}

void SceneManager::changeToScene(QString sceneName)
{
    emit sceneChanged(m_scenes[sceneName]);
}
