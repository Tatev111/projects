#include <pthread.h>
#include <iostream>
#include <queue>
#include <string>
#include <math.h>
#include <vector>
#include "MessageQueue.h"
using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv;


void MessageQueue::PostMessage(string message){
    pthread_mutex_lock(&mutex);
    cout<<"Post Message called with "<<message<<endl;
     
    _queue.push(message);
    
    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&mutex);
    
}

void MessageQueue::RegisterHandler(MessageHandler handler)
{
    _handlers.push_back(handler);
}

struct obprop{
    vector<MessageHandler>* _handlers;
    string _message;
};

void * MessBroadcaster(void * par)
{
    obprop* ob = (obprop*)par;
    for(int i = 0; i < ob->_handlers->size(); ++i)
    {
        (*ob->_handlers)[i](ob->_message);
    }
    return 0;
}
