#include "GameScreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("LoretsyanHayk");
    a.setApplicationName("NinjaTime");

    GameScreen w;
    w.show();

    return a.exec();
}
