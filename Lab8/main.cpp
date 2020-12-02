#include "login_db.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login_DB w;
    w.show();
    return a.exec();
}
