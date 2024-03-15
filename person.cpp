#include "person.h"

Person::Person() : age(0) {}

Person::~Person() {}

QString Person::getName() const {
    return name;
}

void Person::setName(const QString &name) {
    this->name = name;
}

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    this->age = age;
}

QString Person::getBirthday() const {
    return birthday;
}

void Person::setBirthday(const QString &birthday) {
    this->birthday = birthday;
}
