#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person {
public:
    Person();
    ~Person();

    QString getName() const;
    void setName(const QString &name);

    int getAge() const;
    void setAge(int age);

    QString getBirthday() const;
    void setBirthday(const QString &birthday);

private:
    QString name;
    int age;
    QString birthday;
};

#endif // PERSON_H
