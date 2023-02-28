#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

// QObject类是所有使用元对象系统的类的基类
class QPerson : public QObject
{
    // 声明Q_OBJECT宏，可以使用类使用元对象的特性：动态属性，信号，槽等
    Q_OBJECT

    // Q_CLASSINFO可以为类的元对象定义“名称-值”附加信息
    Q_CLASSINFO("author", "Li Si")
    Q_CLASSINFO("company", "WER")
    Q_CLASSINFO("version", "1.0.0")

    // Q_PROPERTY可以定义属性
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)

private:
    int m_age = 10;
    QString m_name;
    int m_score = 79;
public:
    explicit QPerson(QString fName, QObject *parent = nullptr);
    int age();
    void setAge(int age);
    void incAge();

signals:
    // 自定义信号，必须是无返回值，可以有输入参数，信号函数无需实现，只需要在某些条件下发射信号
    void ageChanged(int value);
public slots:

};

#endif // QPERSON_H
