#include "ktMainWindow.h"

bool kt_window::isNormNum(QString num, bigInt sis) {
    std::string now = num.toStdString();
    bool open = false;
    bigInt ch = 0;
    int si = sis.to_int();
    for (char to : now) {
        if (to >= '0' && to <= '9') {
            if (to >= '0' + si) {
                return false;
            }
            ch = ch * 10;
            ch = ch + (to - '0');
            continue;
        }
        if (open && to == ']') {
            if (ch > sis - 1) {
                return false;
            }
            open = false;
            continue;
        }
        if (!open && to == '[') {
            ch = 0;
            open = true;
            continue;
        }
        return false;
    }
    return true;
}

void kt_window::Convert() {
    QString num = in_num->text();
    QString sis = in_sis->text();
    QString to = to_sis->text();
    if (num.size() == 0 || sis.size() == 0 || to.size() == 0) {
        QMessageBox::information(nullptr, "Не корректный ввод", "Все поля должны быть заполнены");
        return;
    }
    if (!isNormNum(sis, 10)) {
        QMessageBox::information(nullptr, "Не корректный ввод", "Начальная система - десятичное число");
        return;
    }
    if (!isNormNum(to, 10)) {
        QMessageBox::information(nullptr, "Не корректный ввод", "Конечная система - десятичное число");
        return;
    }
    std::string si = sis.toStdString();
    if (!isNormNum(num, si)) {
        QMessageBox::information(nullptr, "Не корректный ввод", "Вы не правельное что-то ввели в поле числа");
        return;
    }


    bigInt inum(num.toStdString());
    inum.set_sis(bigInt(sis.toStdString()).to_int());
    inum.cross(to.toStdString());
    std::string ans = inum.to_str();
    QString br = QString::fromStdString(ans);
    to_ans->setText(br);


}

void kt_window::ChengeFile() {

}