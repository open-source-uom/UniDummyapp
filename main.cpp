#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("UniDummyapp");
    app.setApplicationDisplayName("UniDummyapp");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Workshop");

    // Keep app running when window is closed (lives in tray)
    app.setQuitOnLastWindowClosed(false);

    MainWindow window;
    window.show();

    return app.exec();
}
