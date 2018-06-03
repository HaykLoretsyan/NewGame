#include "Mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QGraphicsView(parent)
{
    setWindowState(Qt::WindowFullScreen);
    setStyleSheet("border: 0px;");
    setWindowFlags(Qt::FramelessWindowHint);


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(&Game::instance(), &Game::sceneChanged,
            this, &MainWindow::On_sceneChanged);

    setScene(Game::instance().init());
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
}

void MainWindow::On_sceneChanged(QGraphicsScene* scene)
{
    setScene(scene);
}
