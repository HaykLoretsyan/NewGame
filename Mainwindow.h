#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "SceneManager.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    

public slots:
    void On_sceneChanged(QGraphicsScene *scene);

private:
    QGraphicsView* view;

};

#endif // MAINWINDOW_H
