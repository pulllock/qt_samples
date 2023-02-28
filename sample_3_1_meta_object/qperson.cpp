#include "qperson.h"

// 构造函数
QPerson::QPerson(QString fName, QObject *parent)
    : QObject{parent}
{
    m_name = fName;
}

// 返回age
int QPerson::age() {
    return m_age;
}

// 设置age
void QPerson::setAge(int value) {
    m_age = value;
    // 使用emit发射自定义信号
    emit ageChanged(m_age);
}

void QPerson::incAge() {
    m_age++;
    // 使用emit发射自定义信号
    emit ageChanged(m_age);
}
