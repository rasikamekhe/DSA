*/Queues are frequently used in computer programming, and a typical example is the creation of a job
queue by an operating system. If the operating system does not use priorities, then the jobs are
processed in the order they enter the system. Write C++ program for simulating job queue. Write
functions to add job and delete job from queue*/

#include<iostream>
using namespace std;
class QUEUE{
    public:
    int queue[20],n,temp;
    int front=-1;
    int rear=-1;
    void enqueue();
    void dequeue();
    void display();
};
void QUEUE::enqueue()
{
    cout<<"Enter the value of n: ";
    cin>>n;
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=n;
    }
    else if(rear>=0 && rear<n){
        rear++;
        queue[rear]=n;
    }
    else{
    cout<<"Can't insert";
}   
display();
}

void QUEUE::dequeue()
{
    if((rear==0 && rear==0)|| ( front==rear)){
        temp=queue[front];
        front=rear=-1;
    }
    else if(front<rear){
        temp=queue[front];
        front++;
    }
    cout<<temp<<"is delted from queue!"<<endl;
    cout<<"\n Remaining elements are: "<<endl;
    display();
}
void QUEUE::display()
{
   
        for(int i=front;i<=rear;i++){
            cout<<"  "<<queue[i]<<endl;
        }
 }


int main(){
   int ch,op;
   QUEUE obj;
    do{
        cout<<"---MENU---";
        cout<<"\n 1.ENQUEUE";
        cout<<"\n 2.DEQUEUE";

        cout<<"\n Enter your choice: ";
        cin>>ch;

        switch(ch){
            case 1:
            cout<<"INSERTING..";
            obj.enqueue();
            cout<<" Inserted!";
            break;
            case 2:
            cout<<"DELETING..";
            obj.dequeue();
            cout<<" Deleted!";
            break;
        }
        cout<<"\n Do you want to perform again? Yes:press 1, No:press 0 \t";
        cin>>op;       
}
    while(op==1);
    return 0;
}
