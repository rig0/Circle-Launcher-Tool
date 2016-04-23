#include "launchertool.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LauncherTool w;
    w.show();

    return a.exec();
}
