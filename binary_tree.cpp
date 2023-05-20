#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
template<class T>
class node{
public:
    T data;
    node*left;
    node*right;
    node(T info){
        data=info;
        left=NULL;right=NULL;
    }
    node(){
        left=NULL;right=NULL;
    }
    node* tree_maker(){
        T inf;cin>>inf;
        node *root=new node(inf);
        if(inf==-1){return NULL;}
        root->left=tree_maker();
        root->right=tree_maker();
        return root;
    }
    void finder(node*root,T d,node*&n){
        if(root==NULL){
            return;
        }
        if(root->data==d){n=root;return;}
        if(root->data>d){finder(root->left,d,n);}
        else if(root->data<d){finder(root->right,d,n);}
        return;
    }
    void inorder_traversel(node*head,vector<T>&temp,vector<T>&temp1){
        if(head==NULL){
            // cout<<" NULL ";
            return;
        }
        inorder_traversel(head->left,temp,temp1);
        temp.push_back(head->data);
        temp1.push_back(head->data);
        inorder_traversel(head->right,temp,temp1);
        return;
    }
    void preorder_traversel(node*head){
        if(head==NULL){
            return;
        }
        cout<<head->data<<" ";
        preorder_traversel(head->left);
        preorder_traversel(head->right);
        return;
    }
    void postorder_traversel(node*head){
        if(head==NULL){
            return;
        }
        postorder_traversel(head->left);
        postorder_traversel(head->right);
        cout<<head->data<<" ";
        return;
    }
    node* in_pre_to_tree(T inorder[],T preorder[],int s,int e,int &k){
        if(s>e || k==e){
            return NULL;
        }
        int curr=s;
        while(curr<e && preorder[k]!=inorder[curr]){
            curr++;
        }
        node*head=new node(inorder[curr]);
        k++;
        head->left=in_pre_to_tree(inorder,preorder,s,curr-1,k);
        head->right=in_pre_to_tree(inorder,preorder,curr+1,e,k);
        return head;
    }
    node* in_post_to_tree(T inorder[],T postorder[],int s,int e,int &k){
        if(s==-1 || s>e || k==-1){
            return NULL;
        }
        int curr=s;
        while(curr<=e && postorder[k]!=inorder[curr]){
            curr++;
        }
        node*head=new node(inorder[curr]);
        k--;
        head->right=in_post_to_tree(inorder,postorder,curr+1,e,k);
        head->left=in_post_to_tree(inorder,postorder,s,curr-1,k);
        return head;
    }
    void level_traversal(node*head){
        queue<node*> q;
        q.push(head);q.push(NULL);
        while(!q.empty()){
            if(q.front()!=NULL){
                if(q.front()->left!=NULL){q.push(q.front()->left);}
                if(q.front()->right!=NULL){q.push(q.front()->right);}
                cout<<q.front()->data<<" ";
                q.pop();
            }
            else{
                cout<<endl;
                q.push(NULL);
                q.pop();
                if(q.front()==NULL){q.pop();}
            }
        }
        return;
    }
    void right_view(node*head){
        queue<node*> q;
        q.push(head);q.push(NULL);
        while(!q.empty()){
            if(q.front()!=NULL){
                if(q.front()->left!=NULL){q.push(q.front()->left);}
                if(q.front()->right!=NULL){q.push(q.front()->right);}
                T dd=q.front()->data;
                q.pop();
                if(q.front()==NULL){
                    cout<<dd;
                }
            }
            else{
                cout<<endl;
                q.push(NULL);
                q.pop();
                if(q.front()==NULL){q.pop();}
            }
        }
        return;
    }
    void left_view(node*head){
        queue<node*> q;
        q.push(head);q.push(NULL);
        cout<<head->data;
        while(!q.empty()){
            if(q.front()!=NULL){
                if(q.front()->left!=NULL){q.push(q.front()->left);}
                if(q.front()->right!=NULL){q.push(q.front()->right);}
                T dd=q.front()->data;
                q.pop();
            }
            else{
                cout<<endl;
                q.push(NULL);
                q.pop();
                if(q.front()!=NULL){cout<<q.front()->data;}
                if(q.front()==NULL){q.pop();}
            }
        }
        return;
    }
    bool exist(node*head,T d1,T d2,node*&ans){
        if(head==NULL){return 0;}
        if(head->data==d1 || head->data==d2){ans=head;return 1;}
        bool p1=exist(head->left,d1,d2,ans);
        bool p2=exist(head->right,d1,d2,ans);
        if(p1 || p2){if(p1&&p2){ans=head;}return 1;}
        return 0;
    }
    int height(node*head){
        if(head==NULL){return 0;}
        return max(height(head->left),height(head->right))+1;
    }
    int diameter(node*head){
        if(head==NULL){
            return 0;
        }
        int tt=height(head->left)+height(head->left)+1;
        return max(max(diameter(head->left),diameter(head->right)),tt);
    }
    pair<int,int> height_diameter(node*root){
        if(root==NULL){pair<int,int>l;l.first=0;l.second=0;return l;}
        pair<int,int>l=height_diameter(root->left);
        pair<int,int>r=height_diameter(root->right);
        int t1=l.second;int t2=r.second;int t3=l.first+r.first;
        return make_pair(max(l.first,r.first)+1,max(max(t1,t2),t3+1));
    }
    // pair<bool,int> balanced(node*root){
    //     if(root==NULL){pair<bool,int>lk;lk.first=1;lk.second=0;return lk;}
    //     pair<bool,int>l=balanced(root->left);
    //     pair<bool,int>r=balanced(root->right);
    //     if(l.first && r.first){
    //         if(-1<=(l.second-r.second)<=1){return make_pair(1,max(l.second,r.second)+1);}
    //     }
    //     return make_pair(0,max(l.second,r.second)+1);
    // }
    bool ancestor(node*root,T target,stack<node*> &q1){
        if(root==NULL){return 0;}
        if(root->data==target){q1.push(root);return 1;}
        if(ancestor(root->left,target,q1)||ancestor(root->right,target,q1)){
            q1.push(root);return 1;
        }
        return 0;
    }
    void LCS(node*root,T target1,T target2){
        stack<node*> q1;stack<node*> q2;
        ancestor(root,target1,q1);
        ancestor(root,target2,q2);
        node* temp;
        while(!q1.empty() && !q2.empty()){
            if(q1.top()==q2.top()){temp=q1.top();}
            q1.pop();q2.pop();
        }
        cout<<temp->data;
    }
    bool balanced(node*root){
        if(root==NULL){return 1;}
        bool l=balanced(root->left);
        bool r=balanced(root->right);
        if(l==0 || r==0){
            return 0;
        }
        int lh=height(root->left);int rh=height(root->right);
        if(-2<(lh-rh)<2){return 1;}
        return 0;
    }
    int distance(node*root,T nd){
        if(root==NULL){return -1;}
        if((root->data)==nd){return 0;}
        int t1=max(distance(root->left,nd),distance(root->right,nd));
        if(t1==-1){return -1;}
        return t1+1;
    }
    void setter(node*root,unordered_map<node*,node*> &umap){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            umap[root->left]=root;
        }
        if(root->right!=NULL){
            umap[root->right]=root;
        }
        setter(root->left,umap);
        setter(root->right,umap);
    }
    // void nodes_at_distance_k(node*root,node*target,int k){
    //     unordered_map<node*,node*> umap;
    //     setter(root,umap);
    //     queue<node*>
    // }
    // pair<node<T>*,node<T>*> flatten(node<T>*root){
    //     if(root==NULL){return make_pair(NULL,NULL);}
    //     node*t1=root;
    //     node*t2=root->left;
    //     node*t3=root->right;
    //     root->left=NULL;
    //     pair<node*,node*>p1=flatten(t2);
    //     pair<node*,node*>p2=flatten(t3);
    //     root->right=p1.first;
    //     p1.second->right=p2.first;
    //     p2.second->right=NULL;
    //     return make_pair(root,p2.second);
    // }
    void helper_bst(node*root,node*&n1,T d1,char &c){
        if(root==NULL){return;}
        if(root->left!=NULL){
            if(root->left->data==d1){c='l';n1=root;return;}
        }
        if(root->right!=NULL){
            if(root->right->data==d1){c='r';n1=root;return;}
        }
        helper_bst(root->left,n1,d1,c);helper_bst(root->right,n1,d1,c);
        return;
    }
    void recover_bst(node*root){
        vector<T>in;vector<T>in2;
        inorder_traversel(root,in,in2);
        sort(in2.begin(),in2.end());
        vector<T> v;
        for(int i=0;i<in.size();i++){
            if(in[i]!=in2[i]){v.push_back(in[i]);}
        }
        node* n1=NULL;node* n2=NULL;char c1,c2;
        helper_bst(root,n1,v[0],c1);helper_bst(root,n2,v[1],c2);
        if(c1=='l' && c2=='l'){
            node*t1=n1->left;node*t2=n2->left;
            n1->left=t2;n2->left=t1;
            swap(t1->left,t2->left);swap(t1->right,t2->right);
        }
        else if(c1=='l' && c2=='r'){
            node*t1=n1->left;node*t2=n2->right;
            n1->left=t2;n2->right=t1;
            swap(t1->left,t2->left);swap(t1->right,t2->right);
        }
        else if(c1=='r' && c2=='l'){
            node*t1=n1->right;node*t2=n2->left;
            n1->right=t2;n2->left=t1;
            swap(t1->left,t2->left);swap(t1->right,t2->right);
        }
        else{
            node*t1=n1->right;node*t2=n2->right;
            n1->right=t2;n2->right=t1;
            swap(t1->left,t2->left);swap(t1->right,t2->right);
        }
    }
    void vertical_traversal(node*root,map<int,vector<node*> >&answer,int i){
        if(root==NULL){return;}
        answer[i].push_back(root);
        vertical_traversal(root->left,answer,i-1);
        vertical_traversal(root->right,answer,i+1);
        return;
    }
};
int main() {
    node<int> tempo;
    // int b[]={1,2,};
    // int a[]={1,};
    // int b[]={4,3};
    // int a[]={4,3};    
    // char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    // char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    // int in[] = {4,2,1,5,3};
    // int post[] = {4,2,5,3,1};
    // int o=4;
    // node<int> *root=tempo.in_post_to_tree(in,post,0,4,o);
    node<int> *root=tempo.tree_maker();
    // node<int>* root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);
    // pair<node<int> *,node<int> * >rr;
    // tempo.exist(root,1,7,rr);cout<<rr->data;
    // cout<<l.first<<" "<<l.second;
    // tempo.inorder_traversel(root);
    // rr=tempo.flatten(root);
    // cout<<tempo.distance(root,13);
    // tempo.LCS(root,4,2);
    // tempo.recover_bst(root);
    // vector<int>temp;
    map<int,vector<node<int>* > >answer;
    tempo.vertical_traversal(root,answer,0);
    for(auto x:answer){
        cout<<x.first<<endl;
        for(auto g:x.second){
            cout<<g->data<<" ";
        }
        cout<<endl<<endl;
    }
    // tempo.inorder_traversel(root,temp,temp);
    // for(auto x:temp){cout<<x<<" ";}
	return 0;
}
// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 9 13 -1 -1 -1