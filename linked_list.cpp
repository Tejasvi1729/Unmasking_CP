#include<iostream>
using namespace std;
template <class T>
class node{
    T data;
    node* next;
public:
    node(T n){
        data=n;
        next=NULL;
    }
    void insertion_at_head(T n,node* &head,node*&tail){
        node* temp=new node(n);
        if(head==NULL){tail=temp;head=temp;return;}
        temp->next=head;
        head=temp;
        return;
    }
    void insertion_at_tail(T n,node* &head,node*&tail){
        node* temp=new node(n);
        if(tail==NULL){head=temp;tail=temp;return;}
        tail->next=temp;
        tail=temp;
        return;
    }
    void printer(node*head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
    void deletion(node*&head,node*&tail,node*del){
        node* temp=head;
        if(del==head){
            head=head->next;delete temp;return;
        }
        while(temp->next!=del){
            temp=temp->next;
        }
        temp->next=del->next;
        delete del;
    }
    void reverse_iterative(node*&head,node*&tail){
        node*temp=head;
        node*p=NULL;node*c=head;node*n=c->next;
        while(n!=NULL){
            c->next=p;p=c;c=n;n=n->next;
        }
        c->next=p;p=c;c=n;
        tail=temp;
        head=p;
    }
    pair<node*,node*> reverse_recursion(node*head,node*tail){
        if(head==tail){return(make_pair(head,tail));}
        pair<node*,node*> temp=reverse_recursion(head->next,tail);
        temp.first->next=head;
        head->next=NULL;
        return(make_pair(head,tail));
    }
    pair<node*,node*> reverse_knodes(node*head,node*tail,int k){
        if(head==tail || head==NULL){
            return(make_pair(head,tail));
        }
        node*temp=head;
        node*p=NULL;node*c=head;node*n=c->next;
        int count=0;
        node*store;
        while(count<k){
            c->next=p;p=c;c=n;n=n->next;count++;
        }
        store=c->next;
        c->next=p;p=c;c=n;
        pair<node*,node*>rec=reverse_knodes(store,tail,k);
        rec.first->next=c;
        return(make_pair(head,tail));
    }
    void cycle_maker(node*head){
        node* fast=head;
        node* slow=head;
        while(fast!=NULL && fast->next!=NULL&& fast->next->next!=NULL){
            fast=(fast->next)->next;
            slow=slow->next;
        }
        while(fast->next!=NULL){fast=fast->next;}
        fast->next=slow;
    }
    bool cycle_detection(node*head){
        node* fast=head;
        node* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=(fast->next)->next;
            slow=slow->next;
            if(fast==slow){
                return 1;
            }
        }
        return 0;
    }
    void cycle_remover(node*head){
        node* fast=head;
        node* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=(fast->next)->next;
            slow=slow->next;
            if(fast==slow){
                break;
            }
        }
        fast=head;
        while(fast->next!=slow->next){
            fast=fast->next;slow=slow->next;
        }
        slow->next=NULL;
    }
    node* merger(node *head1, node *head2){
        node* c1=head1;node* c2=head2;
        node* p1;node* p2;
        while(c1->next!=NULL && c2->next!=NULL){
            if(c1->next->data < c2->data){
                c1=c1->next;
            }
            else{
                node* tempo=c2;
                c2=tempo->next;
                tempo->next=c1->next;
                c1->next=tempo;
            }
        }
        if(c1->next==NULL){
            c1->next=c2;
        }
        else{
            while(c1->next!=NULL){
                c1=c1->next;
            }
            c1->next=c2;
        }
        return head1;
    }
    void merger_recursion(node*h1,node*h2,node*p3){
        if(h1==NULL){
            p3->next=h2;
            return;
        }
        if(h2==NULL){
            p3->next=h1;
            return;
        }
        if(h1->data <= h2->data){
            p3->next=h1;
            h1=h1->next;
            p3=p3->next;
            return merger_recursion(h1,h2,p3);
        }
        else if(h1->data > h2->data){
            p3->next=h2;
            h2=h2->next;
            p3=p3->next;
            return merger_recursion(h1,h2,p3);
        }
    }
    node* even_odd_positioned_together(node*head){
        node *odd=head;node* op=odd;
        node*even=head->next;node* ep=even;
        while(odd->next!=NULL && even->next!=NULL){
            odd->next=even->next;odd=even->next;
            even->next=odd->next;even=odd->next;
        }
        odd->next=ep;
        return op;
    }
};

template <class T>
class dll{
private:
    dll* prev;
    dll* next;
    T data;
public:
    dll(T info){
        data=info;
        prev=NULL;
        next=NULL;
    };
    void insertion_at_tail(T n,dll*&head,dll*&tail){
        dll*temp=new dll(n);
        if(head==NULL && tail==NULL){
            head=temp;tail=temp;
        }
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
        return;
    }
    void insertion_at_head(T n,dll*&head,dll*&tail){
        dll*temp=new dll(n);
        if(head==NULL && tail==NULL){
            head=temp;tail=temp;
        }
        temp->next=head;head->prev=temp;head=temp;
        return;
    }
    void printer(dll*head){
        while(head!=NULL){
            cout<<head->data<<"->";
            head=head->next;
        }
        cout<<"NULL";
        cout<<endl;
    }
    void deletion(dll *&head,int pos){
        dll* tem=head;
        dll* zeta;
        while(pos--){tem=tem->next;}zeta=tem;
        if(tem->next==NULL){tem->prev->next=NULL;delete tem;}
        else if(tem==head){tem->next->prev=NULL;head=tem->next;delete tem;}
        else{tem->prev->next=tem->next;tem->next->prev=tem->prev;delete tem;}
        return;
    }
};

int main(){
    node<int> *head=NULL;
    node<int> *tail=NULL;
    node<int> temp(-1);
    node<int> *head0=NULL;
    node<int> *tail0=NULL;
    node<int>* p3=new node(-1);
    temp.insertion_at_tail(1,head,tail);
    temp.insertion_at_tail(2,head,tail);
    temp.insertion_at_tail(3,head,tail);
    temp.insertion_at_tail(4,head,tail);
    temp.insertion_at_tail(5,head,tail);
    temp.insertion_at_tail(6,head,tail);
    temp.insertion_at_tail(7,head,tail);
    // temp.deletion(head,0);
    temp.insertion_at_tail(2,head0,tail0);
    temp.insertion_at_tail(4,head0,tail0);
    temp.insertion_at_tail(6,head0,tail0);
    temp.insertion_at_tail(8,head0,tail0);
    // temp.insertion_at_tail(4,head0,tail0);
    // temp.insertion_at_tail(5,head0,tail0);
    // temp.insertion_at_tail(6,head0,tail0);
    // temp.deletion(head,tail,tail);
    // temp.cycle_maker(head);
    // temp.reverse_knodes(head,tail,2);
    // temp.reverse_knodes(head,tail,4 );
    // temp.cycle_remover(head);
    // cout<<temp.cycle_detection(head);
    // node<int>*tt=temp.merger(head,head0);
    // node<int>*ptr=temp.even_odd_positioned_together(head);
    temp.merger_recursion(head,head0,p3);
    temp.printer(p3);cout<<endl;
}