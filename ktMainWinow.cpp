#include "ktMainWindow.h"

void kt_window::build() {
    resize(500, 800);
    QLinearGradient gradient(0, 0, 0, height());

    QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect();
    eff->setBlurRadius(10);
    eff->setColor(QColor(0, 0, 0, 50));


    QWidget* title = new QWidget(this);
    title->resize(width() * 0.6,
                  height() * 0.6);
    title->move(width() * 0.3,
                height() * 0.07);
    QLabel* name = new QLabel(title);
    name->setText("kto_tor");
    name->setStyleSheet("color: #EEEBD0;");
    name->setGraphicsEffect(eff);
    QFont stile("Courier", 48);
    name->setFont(stile);

    gradient.setColorAt(0, QColor(0x30011E));
    gradient.setColorAt(1, QColor(0x053225));

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(gradient));
    setPalette(palette);

    back = new QWidget(this);

    in_num = new QLineEdit(back);
    in_sis = new QLineEdit(back);
    to_sis = new QLineEdit(back);
    to_ans = new QLineEdit(back);
    to_ans->setReadOnly(true);

    stile.setPointSize(24);

    in_num->setFont(stile);
    in_sis->setFont(stile);
    to_ans->setFont(stile);
    to_sis->setFont(stile);

    QVBoxLayout *layout = new QVBoxLayout(back);
    back->resize(0.55 * height(), 1.2 * width());
    back->move(0.04 * height(), 0.3 * width());

    layout->addWidget(in_num);
    layout->addWidget(in_sis);
    layout->addWidget(to_sis);
    layout->addWidget(to_ans);
    back->setLayout(layout);

    QWidget* in_num_text = new QWidget(this);
    in_num_text->resize(width() * 0.5,
                  height() * 0.036);
    in_num_text->move(width() * 0.09,
                height() * 0.26);
    QLabel* tex1 = new QLabel(in_num_text);
    tex1->setText("Введите число");
    tex1->setStyleSheet("color: #EEEBD0;");
    tex1->setGraphicsEffect(eff);
    tex1->setFont(stile);

    QWidget* in_sis_text = new QWidget(this);
    in_sis_text->resize(width(),
                        height() * 0.036);
    in_sis_text->move(width() * 0.09,
                      height() * 0.42);
    QLabel* tex2 = new QLabel(in_sis_text);
    tex2->setText("Введите начальную систему");
    tex2->setStyleSheet("color: #EEEBD0;");
    tex2->setGraphicsEffect(eff);
    tex2->setFont(stile);

    QWidget* to_sis_text = new QWidget(this);
    to_sis_text->resize(width(),
                        height() * 0.036);
    to_sis_text->move(width() * 0.09,
                      height() * 0.58);
    QLabel* tex3 = new QLabel(to_sis_text);
    tex3->setText("Введите конечную систему");
    tex3->setStyleSheet("color: #EEEBD0;");
    tex3->setGraphicsEffect(eff);
    tex3->setFont(stile);

    QWidget* to_ans_text = new QWidget(this);
    to_ans_text->resize(width(),
                        height() * 0.036);
    to_ans_text->move(width() * 0.09,
                      height() * 0.74);
    QLabel* tex4 = new QLabel(to_ans_text);
    tex4->setText("Ответ");
    tex4->setStyleSheet("color: #EEEBD0;");
    tex4->setGraphicsEffect(eff);
    tex4->setFont(stile);

    stile.setPointSize(16);

    QWidget* bruh = new QWidget(this);
    button_to_chenge_file = new QPushButton("Подключить ввод\n вывод из файла", this);
    button_to_chenge_file->setFixedSize(width() * 0.4,
                                        height() * 0.1);
    button_to_chenge_file->setFont(stile);
    button_to_chenge_file->setStyleSheet("background-color: #035E7B;");
    QHBoxLayout *buttonLayout1 = new QHBoxLayout();

    buttonLayout1->addWidget(button_to_chenge_file);

    bruh->resize(width() * 0.45, height() * 0.1);
    bruh->move(width() * 0.06, height() * 0.85);
    bruh->setLayout(buttonLayout1);

    QWidget* bruh2 = new QWidget(this);
    button_to_convert = new QPushButton("Конвертировать", this);
    button_to_convert->setFixedSize(width() * 0.4,
                                        height() * 0.1);
    button_to_convert->setFont(stile);
    button_to_convert->setStyleSheet("background-color: #035E7B;");
    QHBoxLayout *buttonLayout2 = new QHBoxLayout();

    buttonLayout2->addWidget(button_to_convert);

    bruh2->resize(width() * 0.45, height() * 0.1);
    bruh2->move(width() * 0.5, height() * 0.85);
    bruh2->setLayout(buttonLayout2);

    QAbstractButton::connect(button_to_convert, &QPushButton::clicked, this, &kt_window::Convert);
    QAbstractButton::connect(button_to_chenge_file, &QPushButton::clicked, this, &kt_window::ChengeFile);
}
