
#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString resourceImgIcon = ":/resources/ShoppingCartIcon.png";
    QString resourceImgSplash = ":/resources/WelcomeImage.png";

    //Application Icon
    QApplication::setWindowIcon(QIcon(resourceImgIcon));

    //Application SplashScreen
    QSplashScreen splash((QPixmap(resourceImgSplash)));
    splash.show();
    a.processEvents();

    MainWindow w;

    QTimer::singleShot(1500, &splash, [&](){splash.close(); w.show();});

    return a.exec();
}
