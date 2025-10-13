#include "Calculator.h"
#include <QGridLayout>
#include <Button.h>

Calculator::Calculator() {

    display = new QLineEdit();
    display->setAlignment(Qt::AlignRight);
    display->setText("0");
    display->setMaxLength(16);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 10);
    display->setFont(font);

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    for (int i = 9; i >= 0; --i){
        digitButtons[i] = createButton(QString::number(i),SLOT(digitClicked()));
    }

    Button *plusButton = createButton(plus_sign, SLOT(operatorPlusClicked()));
    Button *minusButton =  createButton(minus_sign, SLOT(operatorMinusClicked()));
    Button *multiplyButton = createButton(multiply_sign, SLOT(operatorMultiplyClicked()));
    Button *divideButton =  createButton(divide_sign, SLOT(operatorDivideClicked()));
    Button *equalButton =  createButton(equal_sign, SLOT(equalClicked()));
    Button *clearButton =  createButton("AC", SLOT(clearClicked()));

    mainLayout->addWidget(display, 0, 0, 1, 4);

    mainLayout->addWidget(plusButton, 1, 3, 1, 1);
    mainLayout->addWidget(minusButton, 2, 3, 1, 1);
    mainLayout->addWidget(multiplyButton, 3, 3, 1, 1);
    mainLayout->addWidget(divideButton, 4, 3, 1, 1);
    mainLayout->addWidget(equalButton, 4, 2, 1, 1);
    mainLayout->addWidget(clearButton, 4, 0, 1, 1);

    for (int i = 0; i <= 9; ++i) {
        int row, col;
        if (i == 0) {
            row = 4;
            col = 1;
        } else {
            row = (9 - i) / 3 + 1;  // 1,1,1,2,2,2,3,3,3
            col = (9 - i) % 3;
        }
        mainLayout->addWidget(digitButtons[i], row, col, 1, 1);
    }

    setLayout(mainLayout);
    setWindowTitle("Simple Calc");
}

Button *Calculator::createButton(const QString &text, const char *member)
{
    Button *btn = new Button(text);
    connect(btn,SIGNAL(clicked()), this, member);
    return btn;
}

void Calculator::digitClicked()
{
    if (result != "err"){
        Button *btn = (Button*) sender();
        int digit = btn->text().toLongLong();

        if (operation.isEmpty())
        {
            firstOperand += QString::number(digit);
            firstOperand = QString::number(firstOperand.toLongLong());
            result = "";
        } else {
            secondOperand += QString::number(digit);
            secondOperand = QString::number(secondOperand.toLongLong());
        }

        display -> setText(firstOperand + operation + secondOperand);
    }
}

void Calculator::operatorPlusClicked()
{
    operatorClicked(plus_sign);
}

void Calculator::operatorMinusClicked()
{
    operatorClicked(minus_sign);
}

void Calculator::operatorMultiplyClicked()
{
    operatorClicked(multiply_sign);
}

void Calculator::operatorDivideClicked()
{
    operatorClicked(divide_sign);
}

void Calculator::operatorClicked(const QString &operationClick)
{
    if (result != "err") {

        if (!operation.isEmpty() && !firstOperand.isEmpty() && !secondOperand.isEmpty()){
            applyOperation();
        }

        if (!result.isEmpty()){
            firstOperand = result;
        } else {
            if (firstOperand.isEmpty()){
                firstOperand = "0";
            }
        }

        operation = operationClick;
        secondOperand = "";

        display -> setText(firstOperand + operation);
    }
}

// equalClicked() - функция расчета результата
void Calculator::equalClicked()
{
    if (!operation.isEmpty() && !firstOperand.isEmpty() && !secondOperand.isEmpty()){
        applyOperation();
        display -> setText(result);
        firstOperand = "";
        operation ="";
        secondOperand = "";
    }
}

void Calculator::applyOperation()
{
    if (operation == plus_sign) {
        result = QString::number(firstOperand.toLongLong() + secondOperand.toLongLong());
    } else if (operation == minus_sign) {
        result = QString::number(firstOperand.toLongLong() - secondOperand.toLongLong());
    } else if (operation == multiply_sign) {
        result = QString::number(firstOperand.toLongLong() * secondOperand.toLongLong());
    } else if (operation == divide_sign) {
        if (secondOperand.toLongLong() != 0) {
            result = QString::number(firstOperand.toLongLong() / secondOperand.toLongLong());
        } else {
            result = "err";
        }
    }
}

void Calculator::clearClicked()
{
    firstOperand = "";
    operation ="";
    secondOperand = "";
    result = "";

    display -> clear();
}


