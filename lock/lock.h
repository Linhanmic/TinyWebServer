#ifndef TINYWEBSERVER_LOCK_H_
#define TINYWEBSERVER_LOCK_H_

#include <semaphore.h>

class sem{
    public:
    sem(){
        if(sem_init(&m_sem_, 0, 0) != 0){
            throw std::exception();
        }
    }

    sem(int num){
        if(sem_init(&m_sem_, 0, num) !=0){
            throw std::exception();
        }
    }

    ~sem(){
        sem_destroy(&m_sem_);
    }

    bool wait(){
        return sem_wait(&m_sem_) == 0;
    }

    bool post(){
        return sem_post(&m_sem_) == 0;
    }

    private:
    sem_t m_sem_;
}