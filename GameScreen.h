#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "Game.h"


class GameScreen : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = 0);
    ~GameScreen();

protected:
    /**
     * @brief closeEvent save any progress on close
     * @param event
     */
    void closeEvent(QCloseEvent* event) override;

public slots:
    void On_sceneChanged(QGraphicsScene *scene);

};

#endif // GAMESCREEN_H
