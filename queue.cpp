#include<iostream>
#include<stack>
using namespace std;
template<class T>
class queueu{
    T* ptr;
    int length;
    int fr;
    int capacity;
public:
    queueu(){
        length=0;
        capacity=1;
        fr=0;
        ptr=new T[1];
    }
     void push(T data){
        if(length==capacity){
            capacity*=2;
            T* temp=new T[capacity];
            for(int i=0;i<(capacity/2);i++){
                temp[i]=ptr[i];
            }
            ptr=temp;
        }
        ptr[length]=data;
        length++;
    }
    T front(){
        return ptr[fr];
    }
    void pop(){
        if(fr==length){
            cout<<"INVALID";return;
        }
        fr++;
    }
};
template<class T>
class node{
public:
    T data;
    node* next;
    node(T info){
        data=info;
        next=NULL;
    }
};
template<class T>
class q_ll{
    node<T>* head;
    node<T>* tail;
public:
    q_ll(){
        head=NULL;tail=NULL;
    }
    void push(T data){
        node<T>* temp=new node<T>(data);
        if(head==NULL){
            head=temp;tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    T front(){
        return head->data;
    }
    void pop(){
        if(head==NULL){cout<<"INVALID";return;}
        node<T>* temp=head;
        head=temp->next;
        delete temp;
        if(head==NULL){tail=NULL;}
    }
};
template<class T>
class q_stack{
    stack<T>s1;
    stack<T>s2;
public:
    void push(T data){
        s1.push(data);
    }
    T front(){
        if(!s2.empty()){return s2.top();}
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
};
template<class T>
class stack_q{

};
int main(){
    q_ll<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    // cout<<q.front();
    // q.pop();
}