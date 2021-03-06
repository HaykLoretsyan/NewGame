#include "Game.h"

Game::Game()
{
    if(!ResourceManager::instance().hasAnyRegisteredAccount()) {
        ResourceManager::instance().registerAnAccount(QHostInfo::localHostName(), "");
    }

    m_player = ResourceManager::instance().player();
}

Game::~Game()
{
    ResourceManager::instance().updateAccountData(m_player);
}

Scene *Game::init()
{
    addScene("Intro", new Intro());
    m_scenes["Intro"]->activateScene();

    return m_scenes["Intro"];
}

void Game::addScene(QString name, Scene *scene)
{
    connect(scene, &Scene::changeScene,
            this, &Game::changeToScene);
    connect(scene, &Scene::addScene,
            this, &Game::addTheScene);

    m_scenes.insert(name, scene);
}

Scene *Game::createScene(QString name)
{
    if(name == "City") {
        return new City(m_player);
    }

    return nullptr;
}

void Game::changeToScene(QString sceneName)
{
    if(!m_scenes.contains(sceneName)) {

        Scene* newScene = createScene(sceneName);

        if(newScene != nullptr) {
            m_scenes.insert(sceneName, newScene);
        }
        else {

            // Something went wrong
            return;
        }
    }

    emit sceneChanged(m_scenes[sceneName]);
}

void Game::addTheScene(QString sceneName, Scene *scene)
{
    m_scenes.insert(sceneName, scene);
}
