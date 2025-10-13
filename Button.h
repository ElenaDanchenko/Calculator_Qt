#ifndef BUTTON_H
#define BUTTON_H

#include <QToolButton>

class Button:public QToolButton
{
    Q_OBJECT
public:
    // explicit - запрещает неявное преобразование аргументов при создании объекта
    explicit Button(const QString& text, QWidget *parent = nullptr);

    // sizeHint() - виртуальный метод из QWidget
    // Возвращает "рекомендуемый размер" виджета
    QSize sizeHint() const override;

};

#endif // BUTTON_H
