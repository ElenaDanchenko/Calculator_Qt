QT += core gui widgets      # Подключаемые модули Qt
TARGET = Simple_Calculator  # Имя исполняемого файла
TEMPLATE = app              # Тип проекта (приложение)

# Перечисление исходников
SOURCES += \
    Button.cpp \
    Calculator.cpp \
        main.cpp\

# Перечисление заголовков
HEADERS += \
    Button.h \
    Calculator.h

