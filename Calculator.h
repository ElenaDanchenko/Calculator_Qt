#ifndef CALCULATOR_H
#define CALCULATOR_H
// #pragma once

#include <QWidget>
#include <QLineEdit>
#include <Button.h>

class Calculator : public QWidget
{

public:
    Calculator();

// Слот в Qt — это обычный метод класса, который может быть вызван системой в ответ на какое-то событие (сигнал).

private slots:
    void digitClicked(); // 0-9
    void operatorPlusClicked();
    void operatorMinusClicked();
    void operatorMultiplyClicked();
    void operatorDivideClicked();
    void operatorClicked(const QString& operationClick);
    void equalClicked(); // =
    void applyOperation();
    void clearClicked(); // AC
private:
    Button* createButton(const QString& text, const char * member);

private:
    Q_OBJECT // макрос, который является фундаментальной частью механизма сигналов и слотов 
    QLineEdit* display;

    QString operation; // +,-,*,/
    QString secondOperand = ""; // второе число
    QString firstOperand = "";  // первое число
    QString result = "";

    Button* digitButtons[10];
    QString plus_sign = "+";
    QString minus_sign = "-";
    QString multiply_sign = "×";
    QString divide_sign = "/";
    QString equal_sign = "=";
};

#endif // CALCULATOR_H
