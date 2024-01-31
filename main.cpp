#pragma once
#include "bigInt.h"
#include "ktMainWindow.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    kt_window ktto;
    ktto.build();
    ktto.show();
    return a.exec();
}