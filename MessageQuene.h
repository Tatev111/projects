#include <pthread.h>
#include <iostream>
#include <queue>
#include <string>
#include <math.h>
#include <vector>
#include <string.h>
using namespace std;

typedef void (*MessageHandler)(string str);
class MessageQueue{
    private:
    queue<string> _queue;
    vector<MessageHandler> _handlers;

    public:
  
    MessageQueue();
    void PostMessage(string);
    void RegisterHandler(MessageHandler);

    friend void * MessHand(void * par);
   friend void * MessBroadcaster(void * par);
    
};
