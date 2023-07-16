#include<bits/stdc++.h>
using namespace std;
// bool p1=1;
template<class T>
class node{
public:
    node* left;
    T data;
    node* right;
    node(T info){data=info;left=NULL;right=NULL;}
    void helper(node*&root,T info){
        if(root==NULL){root=new node(info);return;}
        if(root->data > info){
            if(root->left==NULL){root->left=new node(info);return;}
            helper(root->left,info);
            return;
        }
        if(root->right==NULL){root->right=new node(info);return;}
        helper(root->right,info);
        return;
    }
    void print(node*head){cout<<head->data<<" "<<head->left->data<<" "<<head->right->data<<" ";}
    void inorder_traversel(node*head){
        if(head==NULL){
            return;
        }
        inorder_traversel(head->left);
        cout<<head->data<<endl;
        inorder_traversel(head->right);
        return;
    }
    bool search(node*head, T info,node*&temp,char&c){
        // if(head->data==info{temp=head;c='t';})
        if(head==NULL){return 0;}
        if(head->data==info){return 1;}
        if(head->data>info){bool b1=search(head->left,info,temp,c);if(b1==1 && head->left->data==info){c='l';temp=head;}return b1;}
        bool b1=search(head->right,info,temp,c);if(b1==1 && head->right->data==info){c='r';temp=head;}return b1;
    }
    node* tree_maker(){
        T inf;cin>>inf;
        node *root=new node(inf);
        if(inf==-1){return NULL;}
        root->left=tree_maker();
        root->right=tree_maker();
        return root;
    }
    void deletion(node*root,node*parent,char c){
        node *temp;
        if(c=='l'){temp=parent->left;}
        if(c=='r'){temp=parent->right;}
        if(temp->left==NULL && temp->right==NULL){
            if(c=='l'){parent->left==NULL;}
            if(c=='r'){parent->right==NULL;}
            delete temp;
            return;
        }
        if(temp->left==NULL){
            if(c=='l'){parent->left=temp->right;}
            if(c=='r'){parent->right=temp->right;}
            delete temp;
            return;
        }
        if(temp->right==NULL){
            if(c=='l'){parent->left=temp->left;}
            if(c=='r'){parent->right=temp->left;}
            delete temp;
            return;
        }
    }
    // void BST_from_preorder(node*root,int minn,int maxx,int i,int arr[],int n){
    //     if(i==n){return;}
    //     if(arr[i]>root->data && arr[i]<maxx){
    //         if(root->right==NULL){root->right=new node(arr[i]);BST_from_preorder(root,minn,maxx,i+1,arr,n);return;}
    //         else{BST_from_preorder(root->right,root->data,maxx,i,arr,n);return;}
    //     }
    //     else if(arr[i]<root->data && arr[i]>minn){
    //         if(root->left==NULL){root->left=new node(arr[i]);BST_from_preorder(root,minn,maxx,1+i,arr,n);return;}
    //         else{BST_from_preorder(root->left,minn,root->data,i,arr,n);return;}
    //     }
    //     return;
    // }
    // pair<int,pair<T,T> >valid_bst_m2(node* root,bool p){
    //     // if(root==NULL){return make_pair(10000,-1111);}
    //     if(root->left==NULL && root->right==NULL){return make_pair(root->data,root->data);}
    //     pair<T,T>l;
    //     if(root->left!=NULL){l=valid_bst_m2(root->left);if((l.second)>(root->data)){p1=0;}}
    //     else{l=make_pair(root->data,root->data);}
    //     pair<T,T>r;
    //     if(root->right!=NULL){r=valid_bst_m2(root->right);if((r.first)<(root->data)){p1=0;}}
    //     else{r=make_pair(root->data,root->data);}
    //     pair<T,T> temp;
    //     temp.first=min(min(l.first,r.first),root->data);
    //     temp.second=max(max(l.second,r.second),root->data);
    //     return temp;
    // }
    // bool valid_bst_2(node* root){
    //     if(root==NULL){return 1;}
    //     if(root)
    // }
    node* balanced_BST_from_sorted_array(int s,int e,int arr[]){
        if(s>e){return NULL;}
        node* root=NULL;
        int mid;
        mid=(s+e)/2;
        root=new node(arr[mid]);
        root->left=balanced_BST_from_sorted_array(s,mid-1,arr);
        root->right=balanced_BST_from_sorted_array(mid+1,e,arr);
        return root;
    }
    void zig_zag_traversal(node*root){
        bool b=1;
        queue<node*>q;
        stack<node*>s;
        vector<node*>vec;
        q.push(root);
        q.push(NULL);
        while(q.empty()==0){
            node* tem=q.front();q.pop();
            if(tem!=NULL){
                if(tem->left!=NULL){q.push(tem->left);}
                if(tem->right!=NULL){q.push(tem->right);}
                if(b==1){
                    vec.push_back(tem);
                }
                if(b==0){s.push(tem);}
            }
            else{
                q.push(NULL);
                if(b==1){b=0;}
                else{b=1;while(s.empty()==0){vec.push_back(s.top());s.pop();}}
                while(q.front()==NULL){q.pop();}
            }
        }
        for(auto x:vec){cout<<(x->data)<<" ";}
    }
    bool identical_bst(node* root1,node*root2){
        if(root1==NULL && root2==NULL){return 1;}
        else if(root1==NULL && root2!=NULL){return 0;}
        else if(root1!=NULL && root2==NULL){return 0;}
        else if(root1->data==root2->data){
            bool b1=identical_bst(root1->left,root2->left);
            bool b2=identical_bst(root1->right,root2->right);
            return b1 && b2;
        }
        return 0;
    }
    pair<T,T> valid_BST(node *root,int &p){
        //1st min 2nd max

        if(root==NULL){return make_pair(1000000,-1000000);}
        pair<T,T> lft=valid_BST(root->left,p);
        pair<T,T> rig=valid_BST(root->right,p);
        pair<T,T> temp=make_pair(root->data,root->data);
        temp.first=min(temp.first,min(lft.first,rig.first));
        temp.second=max(temp.second,max(lft.second,rig.second));
        if(lft.second>=root->data){p=(p*0);return temp;}
        if(rig.first<=root->data){p=(p*0);return temp;}
        return temp;
    }
};

int main(){
    node<int> b(0);
    node<int>* root=NULL;
    node<int>* roott=NULL;
    // int pre[] = { 10, 5, 1 };
    // b.BST_from_preorder(root,INT_MIN,INT_MAX,1,pre,3);
    // b.helper(root, 50);
    // b.helper(root, 30);
    // b.helper(root, 20);
    // b.helper(root, 40);
    // b.helper(root, 70);
    // b.helper(root, 60);
    // b.helper(root, 80);
    // root=b.tree_maker();
    // b.inorder_traversel(root);
    // node<int>*tt;
    // char cc='p';
    // b.search(root,80,tt,cc);
    // b.print(tt);cout<<endl;
    // b.deletion(root,tt,cc);
    // b.print(tt);
    // cout<<rev("abcd",0);
    // vector<int> record;
    // record.push_back(1);
    // record.push_back(2);
    // record.push_back(3);
    // int n=record.size();
    // string pp;
    // substring("abcd","abcp",3,3,pp);
    // for(auto x:pp){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    // b.print(root);b.print(root);b.print(root);
    // int arr[]={1,2,3,4,5,6,7,8,9};
    root=b.tree_maker();
    int p=1;
    b.valid_BST(root,p);
    cout<<p;
    // arr[2]=1;
    // root=b.tree_maker();
    // pair<int,int>p=b.valid_bst_m2(root);
    // cout<<p.first<<" "<<p.second<<" "<<p1;
}
// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 9 13 -1 -1 -1
