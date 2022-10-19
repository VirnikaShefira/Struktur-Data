#include <iostream>
#define MAX 12
using namespace std;

string stack_old = "HA***L*OAP***A*KAB*A***R";
string stack_new;
int top = -1;
int message_length()
{
    int a = sizeof(stack_old)/sizeof(stack_old[0]);
    return a;
}

void push(char alphabet)
{
    if(top==message_length())
    {
        cout<<"stack penuh";
    }

    else
    {
        stack_new[top]=alphabet;
    }
}

void pop()
{
    top--;
}

void printstack()
{
    for(int i=0; i<MAX; i++)
    {
        cout << stack_new[i];
    }
    cout << endl;
}

int main()
{
    int a = message_length();
    for(int i=-1;i<a;i++){
        push(stack_old[i]);
        top++;
        if(stack_new[top-1]=='*'){
            pop();
        }
    }
    printstack();

    return 0;
}
