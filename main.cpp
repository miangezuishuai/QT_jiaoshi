#include <QApplication>
#include "jiaoshi.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    jiaoshi *jiao = new jiaoshi;

    jiao->show();

    return app.exec();
}
