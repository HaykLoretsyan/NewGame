#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QMap>
#include <QString>


class SceneManager : public QObject
{
    Q_OBJECT

private:
    SceneManager();

public:
    static SceneManager& instance() {
        static SceneManager manager;

        return manager;
    }

    void addScene(QString name, QGraphicsScene* scene);
    void changeToScene(QString sceneName);

signals:
    void sceneChanged(QGraphicsScene* scene);

private:
    QMap<QString, QGraphicsScene*> m_scenes;
};

#endif // SCENEMANAGER_H
