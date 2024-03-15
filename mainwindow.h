#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "person.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Serialize();
    void Deserialize();

private:
    QLabel *name;
    QLineEdit *nameLineEdit;
    QLabel *age;
    QLineEdit *ageEdit;
    QLabel *birthday;
    QLineEdit *birthLineEdit;

    QVBoxLayout *leftside;
    QVBoxLayout *rightside;

    QPushButton *serialize;
    QPushButton *deserialize;

    Person *person;
};

#endif // MAINWINDOW_H
