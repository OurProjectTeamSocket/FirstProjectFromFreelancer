#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QtDebug>

class MyThread : public QThread
{
    std::string home = getenv("HOME");

public:
    MyThread();
    void run();

    bool stop;

signals:
    void Recording(std::string);

public slots:

};

#endif // MYTHREAD_H
