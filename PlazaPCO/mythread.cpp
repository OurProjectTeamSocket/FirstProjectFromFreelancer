#include "mythread.h"
#include <QtCore>

MyThread::MyThread()
{

}

void MyThread::run(){
    QMutex mutex;
    mutex.lock();
    if(this->stop) return;
    mutex.unlock();

    emit Recording("");
}
