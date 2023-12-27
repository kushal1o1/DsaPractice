#include <iostream>
using namespace std;
class circularQueue{
   public:
    int c=0;
    int front,rear;
    int size;
    int *arr;
     public :
    // constructor
    circularQueue(int s){
        arr = new int[s-1];
        front=0;
        rear= 0;
        size=s;
    }
    bool isEmpty();
    bool isFull();
    void Enqueue();
    int Dequeue();
    void display();
};

bool circularQueue::isEmpty(){
    if (c<0)
    return true;
    return false;
    
}
bool circularQueue::isFull(){
    if(c>size)
    return true;
    return false;
}
void circularQueue:: Enqueue(){
          int data;
          if (isFull()){
            cout<<"QUeue is full "<<endl;}
            else{
                rear=(rear+1)%size;
                c++;
                cout<<"ENter data YOu wanna Insert "<<endl;
                cin>>data;
                arr[rear]=data;
                cout<<data<<" is inserted to circularQueue sucessfullly \n";
            }

}
int circularQueue::Dequeue(){
    int data;
     if(isEmpty()){
            cout<<"QUeue is Empty";}
            else{
                int data=arr[front];
                front=(front+1)%size;
                cout<<data<<" is removed from the circularQueue SUCCESSFULLY ";
                c--;
            }
}
void circularQueue::display(){
int i=front;
int j=0;
while(j<c){
    cout<<arr[i]<<" ";
    i=(i+1)%size;
    j++;
}

}
int main()
{
    circularQueue q(5);
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


