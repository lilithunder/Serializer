#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    name = new QLabel("Name");
    nameLineEdit = new QLineEdit;
    age = new QLabel("Age");
    ageEdit = new QLineEdit;
    birthday = new QLabel("Birthday");
    birthLineEdit = new QLineEdit;

    leftside = new QVBoxLayout;
    leftside->addWidget(name);
    leftside->addWidget(nameLineEdit);
    leftside->addWidget(age);
    leftside->addWidget(ageEdit);
    leftside->addWidget(birthday);
    leftside->addWidget(birthLineEdit);

    serialize = new QPushButton("Serialize");
    deserialize = new QPushButton("Deserialize");

    rightside = new QVBoxLayout;
    rightside->addWidget(serialize);
    rightside->addWidget(deserialize);

    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *center = new QHBoxLayout(centralWidget);
    center->addLayout(leftside);
    center->addLayout(rightside);
    centralWidget->setLayout(center);
    setCentralWidget(centralWidget);

    connect(serialize, &QPushButton::clicked, this, &MainWindow::Serialize);
    connect(deserialize, &QPushButton::clicked, this, &MainWindow::Deserialize);

    person = new Person;
}

MainWindow::~MainWindow() {
    delete name;
    delete age;
    delete birthday;
    delete nameLineEdit;
    delete birthLineEdit;
    delete ageEdit;
    delete serialize;
    delete deserialize;
    delete leftside;
    delete rightside;
    delete person;
}

void MainWindow::Serialize() {
    QString filename = "info.txt";
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        out << nameLineEdit->text() << '\n';
        out << ageEdit->text().toInt() << '\n';
        out << birthLineEdit->text() << '\n';

        file.close();

        qDebug() << "Serialized data saved to file:" << filename;
    } else {
        qDebug() << "Failed to open file for writing.";
    }
}

void MainWindow::Deserialize() {
    QString filename = "info.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        QString name = in.readLine();
        int age = in.readLine().toInt();
        QString date = in.readLine();

        nameLineEdit->setText(name);
        ageEdit->setText(QString::number(age));
        birthLineEdit->setText(date);

        file.close();

        qDebug() << "Deserialized data loaded from file:" << filename;
    } else {
        qDebug() << "Failed to open file for reading.";
    }
}
