#include <QtWidgets/QApplication>
#include <forms/MainWindow.hpp>

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);

    Lego::MainWindow mainWindow;

    mainWindow.show();

    return application.exec();
}
