#include "Calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.setStyleSheet(
        "QWidget{"
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
            "stop:0 #ffdbed, stop:0.5 #ffc0cb, stop:1 #ff9eb5);"
        "}"

        "QLineEdit {"
            "background-color: white;"
            "border: 3px solid #ff69b4;"
            "border-radius: 20px;"
            "padding: 15px 15px;"
            "font-size: 18px;"
            "font-family: 'Comic Sans MS';"
            "color: #c71585;"
            "font-weight: bold;"
            "min-height: 19px;"
            "selection-background-color: #ffb6c1;"
        "}"

        "QToolButton  {"
            "background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #ff69b4, stop:1 #ff1493);"
            "color: white;"
            "border: 2px solid white;"
            "border-radius: 20px;"
            "font-size: 16px;"
            "font-family: 'Comic Sans MS';"
            "font-weight: bold;"
            "min-width: 45px;"
            "min-height: 45px;"
            "max-width: 45px;"
            "max-height: 45px;"
        "}"

        "QToolButton:hover {"
            "background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #ff1493, stop:1 #d5006d);"
            "border: 2px solid white;"
            "font-size: 19px;"
        "}"

        "QToolButton:pressed  {"
            "background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "stop:0 #d5006d, stop:1 #c0005d);"
        "}"
    );

    w.show();
    return a.exec();
}

