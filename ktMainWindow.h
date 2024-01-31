#pragma once
#include "fraction.h"
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QFont>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>


class kt_window : public QMainWindow {
    Q_OBJECT
private:
    QWidget *back;
    QLineEdit *in_num;
    QLineEdit *in_sis;
    QLineEdit *to_sis;
    QLineEdit *to_ans;
    QPushButton *button_to_convert;
    QPushButton *button_to_chenge_file;
    bool isNormNum(QString num, bigInt sis);
public slots:
    void Convert();
    void ChengeFile();
public:
    void build();
};
