#include "GameScreen.h"
#include "ui_mainwindow.h"

GameScreen::GameScreen(QWidget *parent) :
    QGraphicsView(parent)
{
    setWindowState(Qt::WindowFullScreen);
    setStyleSheet("border: 0px;");
    setWindowFlags(Qt::FramelessWindowHint);


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(&Game::instance(), &Game::sceneChanged,
            this, &GameScreen::On_sceneChanged);

    setScene(Game::instance().init());
}

GameScreen::~GameScreen()
{
}

void GameScreen::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
}

void GameScreen::On_sceneChanged(QGraphicsScene* scene)
{
    setScene(scene);
}
