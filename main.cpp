#include <pthread.h>
#include <iostream>
#include <queue>
#include <string>
#include <math.h>
#include <vector>
#include "MessageQueue.h"
#include <unistd.h>
using namespace std;

void User1(string mess)
{
      cout<<"U1 is  working "<<mess<<endl;
}

void User2(string mess)
{
    cout<<"U2 is  working "<<mess<<endl;
}

int main()
{

    MessageQueue *obj = new MessageQueue;
    obj->RegisterHandler(U1);
    obj->RegisterHandler(U2);
    sleep(1);
    obj->PostMessage("aaa");
    obj->PostMessage("bbb");
   
    int x;
    cin>>x;

    return 0;
}