#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "Game.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    /**
     * @brief closeEvent save any progress on close
     * @param event
     */
    void closeEvent(QCloseEvent* event) override;

public slots:
    void On_sceneChanged(QGraphicsScene *scene);

};

#endif // MAINWINDOW_H
