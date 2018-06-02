#include "Mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    view(new QGraphicsView(this))
{
    setWindowState(Qt::WindowFullScreen);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCentralWidget(view);

    connect(&SceneManager::instance(), &SceneManager::sceneChanged,
            this, &MainWindow::On_sceneChanged);
}

MainWindow::~MainWindow()
{
}

void MainWindow::On_sceneChanged(QGraphicsScene* scene)
{
    view->setScene(scene);
}
