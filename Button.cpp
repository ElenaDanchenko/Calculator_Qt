#include "Button.h"

Button::Button(const QString &text, QWidget *parent)
    :QToolButton(parent){
    setText(text);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
}

QSize Button::sizeHint() const
{
    // 1. Получаем стандартный рекомендуемый размер от базового класса
    QSize size = QToolButton::sizeHint();

    // 2. Увеличиваем высоту на 30 пикселей
    size.rheight() += 30;

    // 3. Устанавливаем ширину равной максимальному значению
    // между текущей шириной и высотой (делаем кнопку квадратной)
    size.rwidth() = qMax(size.width(), size.height());

    // 4. Возвращаем модифицированный размер
    return size;
}


