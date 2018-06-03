#include "Intro.h"

Intro::Intro()
{
    // Load animated GIF
    introMovie = new QMovie(ResourceManager::instance().introMovie());

    // Make sure the GIF was loaded correctly
    if (!introMovie->isValid())
    {
        // Something went wrong :(
    }

    // Screen desktop widget
    QRect screen = QApplication::desktop()->screenGeometry();

    // Play GIF
    QLabel* label = new QLabel();
    label->setWindowFlags(Qt::FramelessWindowHint);
    label->setGeometry(0, 0, screen.width(), screen.height());
    label->setMovie(introMovie);

    addWidget(label);
}

void Intro::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    Q_UNUSED(mouseEvent)

    deactivateScene();

    emit changeScene("City");
}

void Intro::activateScene()
{
    introMovie->start();
}

void Intro::deactivateScene()
{
    introMovie->stop();
}
