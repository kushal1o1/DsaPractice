#include <iostream>
using namespace std;
class Queue{
   public:
    int front,rear;
    int size;
    int *arr;
     public :
    // constructor
    Queue(int s){
        arr = new int[s];
        front=-1;
        rear=-1;
        size=s;
    }
    bool isEmpty();
    bool isFull();
    void Enqueue();
    int Dequeue();
    void display();
};

bool Queue::isEmpty(){
    if((front==-1 && rear==-1)||(front>rear))
    return true;
    return false;
    
}
bool Queue::isFull(){
    if(rear==size-1)
    return true;
    return false;
}
void Queue:: Enqueue(){
          int data;
          if (isFull()){
            cout<<"QUeue is full "<<endl;}
            else{
                if(front==-1 && rear==-1){
                    front=0;
                }
                rear++;
                cout<<"ENter data YOu wanna Insert "<<endl;
                cin>>data;
                arr[rear]=data;
                cout<<data<<" is inserted to queue sucessfullly \n";
            }

}
int Queue::Dequeue(){
    int data;
     if(isEmpty()){
            cout<<"QUeue is Empty";}
            else{
                int data=arr[front];
                front++;
                cout<<data<<" is removed from the QUEUE SUCCESSFULLY ";
            }
}
void Queue::display(){
    for(int i=front;i<=rear;i++){
        cout<<arr[i]<<'\t';
        }
}
int main()
{
    Queue q(5);
    int choice,data;
    cout<<"Queue created\n";
do{
cout<<"Enter your choice "<<endl;
cout<<"1.Enqueue"<<endl;
cout<<"2.Dequeue"<<endl;
cout<<"3.Display"<<endl;
cout<<"4.Exit"<<endl;
cin>>choice;
    switch(choice)
    {
        case 1:
        q.Enqueue();
        break;
        case 2:
        q.Dequeue();
            break;
        case 3:
        q.display();
        break;
        default:
        cout<<"Invalid Choice";

    }
}while(choice!=4);
}
