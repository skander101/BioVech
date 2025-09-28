#include "credentials.h"
#include "personnel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    credentials w;
    personnel appointment_page;
    w.show();
    //appointment_page.show();

    return a.exec();
}
