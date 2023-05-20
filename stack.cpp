#include<iostream>
#include<stack>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
// #define int int

template<class T>
class stackk{
    T*arr;
    int size;
    int capacity;
public:
    stackk(){
        size=0;capacity=1;
        arr=new T[1];
    }
    void push_back(T data){
        if(size==capacity){
            T *temp=new T[capacity*2];
            for(int i=0;i<capacity;i++){
                temp[i]=arr[i];
            }
            capacity*=2;
            arr=temp;
        }
        arr[size]=data;
        size++;
    }
    void pop(){
        size--;
    }
    T top(){
        return arr[size-1];
    }
    bool empty(){
        if(size==0){return 1;}
        return 0;
    }
};
void reverse_sentence(string sen){
    stack<string> ss;
    string temp="";
    int n=sen.size();
    for(int i=0;i<n;i++){
        char x=sen[i];
        if(x==' '){ss.push(temp);ss.push(" ");temp="";}
        else{temp.push_back(x);}
    }
    while(!ss.empty()){
        cout<<ss.top();
        ss.pop();
    }
    return;
}
void prefix_evaluations(string s){
    int n=s.size();
    stack<int> ss;
    for(int i=n-1;i>=0;i--){
        char c=s[i];
        if(c=='+'){
            int op1=ss.top();ss.pop();int op2=ss.top();
            if(ss.empty()){cout<<"INVALID";return;}ss.pop();
            ss.push(op1+op2);
        }
        else if(c=='-'){
            int op1=ss.top();ss.pop();int op2=ss.top();
            if(ss.empty()){cout<<"INVALID";return;}ss.pop();
            ss.push(op1-op2);
        }
        else if(c=='*'){
            int op1=ss.top();ss.pop();int op2=ss.top();
            if(ss.empty()){cout<<"INVALID";return;}ss.pop();
            ss.push(op1*op2);
        }
        else if(c=='/'){
            int op1=ss.top();ss.pop();int op2=ss.top();
            if(ss.empty()){cout<<"INVALID";return;}ss.pop();
            ss.push(op1/op2);
        }
        else{
            ss.push(c-'0');
        }
    }
    cout<<ss.top();
}
void postfix_evaluations(string s){
    int n=s.size();
    stack<int>ss;
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c=='+'){
            int op1=ss.top();ss.pop();int op2=ss.top();
            if(ss.empty()){cout<<"INVALID";return;}ss.pop();
            ss.push(op2+op1);
        }
        else if(c=='-'){
            int op1=ss.top();ss.pop();int op2=ss.top();
            if(ss.empty()){cout<<"INVALID";return;}ss.pop();
            ss.push(op2-op1);
        }
        else if(c=='*'){
            int op1=ss.top();ss.pop();int op2=ss.top();
            if(ss.empty()){cout<<"INVALID";return;}ss.pop();
            ss.push(op2*op1);
        }
        else if(c=='/'){
            int op1=ss.top();ss.pop();int op2=ss.top();
            if(ss.empty()){cout<<"INVALID";return;}ss.pop();
            ss.push(op2/op1);
        }
        else{
            ss.push(c-'0');
        }
    }
    cout<<ss.top();
}
// void 
void insert_at_bot(stack<int> &s,int data){
    if(s.empty()){s.push(data);return;}
    int dd=s.top();
    s.pop();
    insert_at_bot(s,data);
    s.push(dd);
    return;
}
void reverse_stack(stack<int> &s){
    if(s.empty()){return;}
    int tp=s.top();
    s.pop();
    reverse_stack(s);
    insert_at_bot(s,tp);
    return;
}
bool high_priority(char op1,char op2){
    // if(op1=='(' || op1==')')return 1;
    if((op1=='*' || op1=='/') && (op2=='+' || op2=='-')){
        return 1;
    }
    return 0;
}
void infix_to_postfix(string str){
    string s="";int n=str.size();
    stack<char>sta;char c;
    for(int i=0;i<n;i++){
        c=str[i];
        if(c>='0' && c<='9'){s.push_back(c);}
        else if(c=='+' || c=='-' || c=='/' || c=='*'){
            if(sta.empty()){sta.push(char(c));}
            else{
                while(sta.empty()==0 && high_priority(sta.top(),c)==1){s.push_back(char(sta.top()));sta.pop();}
                sta.push(char(c));
            }
        }
        else if(c=='('){sta.push('(');}
        else{
            while(sta.empty()==0 && sta.top()!='('){s.push_back(sta.top());sta.pop();}
            if(sta.empty()==0){sta.pop();}
        }
    }while(sta.empty()==0){s.push_back(sta.top());sta.pop();}
    cout<<s<<endl;
}
// void infix_to_postfix(string str){
//     stack<char> s;char op;
//     char x;int n=s.size();
//     for(int i=0;i<n;i++){
//         x=str[i];
//         if(x<='9' && x>='0'){
//             if(s.empty() || (s.top()<='9' && s.top()>='0')){
//                 s.push(x);
//             }
//             else{
//                 i++;
//                 op=s[i];
//                 if(high_priority(s.top(),op)){
//                     op=s.top();
//                     s.pop();
//                     s.push(s[i]);s.push(op);
//                 }
//                 else{
//                     s.push(s[i]);
//                 }
//             }
//         }
//     }
// }
void balanced_paranthesis(string str){
    stack<char> s;
    for(auto x:str){
        if(x=='(' || x=='{' || x=='['){s.push(x);}
        else if(x==')' || x=='}' || x==']'){
            if(s.empty()){cout<<"INVALID";return;}
            else if(x==')' && s.top()=='('){s.pop();}
            else if(x=='}' && s.top()=='{'){s.pop();}
            else if(x==']' && s.top()=='['){s.pop();}
            else{cout<<"INVALID";return;}
        }
        else{
            cout<<"INVALID";return;
        }
    }
    if(!s.empty()){cout<<"INVALID";return;}
    cout<<"VALID";return;
}
template<class T>
class stack_q{
    queue<T>q1;
    queue<T>q2;
public:
    void push(T data){
        if(q1.empty()){
            q1.push(data);return;
        }
        while(!q1.empty()){
            q2.push(q1.front());q1.pop();
        }
        q1.push(data);
        while(!q2.empty()){
            q1.push(q2.front());q2.pop();
        }
    }
    T top(){
        return q1.front();
    }
};
template<class T>
class stack_q_m2{
    queue<T>q1;
    queue<T>q2;
public:
    void push(T data){
        q1.push(data);return;
    }
    T top(){
        T tem;
        while(q1.size()!=0){
            if(q1.size()==1){
                tem=q1.front();
            }
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
        return tem;
    }
};
void deleted(int arr[],int n,int k){
    // dequeue<int> temp;
    multiset<int> mm;
    for(int i=0;i<k-1;i++){
        mm.insert(arr[i]);
    }
    for(int i=k-1;i<n;i++){
        mm.insert(arr[i]);
        cout<<(*mm.end())<<" ";
        mm.erase(mm.lower_bound(arr[i-k-1]));
    }
}
int main(){
    // stackk<int> s;
    // s.push_back(10);
    // s.push_back(20);
    // s.push_back(30);
    // s.push_back(10);
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // cout<<s.empty();
    // string sen="({[]]]";
    // stack<int> ss;
    // reverse_stack(ss);
    // reverse_stack(ss);
    // while(!ss.empty()){
    //     cout<<ss.top()<<" ";ss.pop();
    // }
    // balanced_paranthesis(sen);
    int arr[]={1,2,3,4,5,6,7,8,9};
    infix_to_postfix("(9-8/2)*(9/8-2)");
    // deleted(arr,9,3);
}