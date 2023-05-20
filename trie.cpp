#include<bits/stdc++.h>
#define ll long long int
using namespace std;
// class trie{
//     trie* child[26];
//     bool ends;
// public:
//     trie(){
//         for(int i=0;i<26;i++){child[i]=NULL;}
//         ends=false;
//     }
//     void insert(string str,trie *head){
//         trie* curr=head;
//         ll n=str.size();
//         for(ll i=0;i<n;i++){
//             if(curr->child[str[i]-'a']==NULL){curr->child[str[i]-'a']=new trie;}
//             curr=curr->child[str[i]-'a'];
//         }
//         curr->ends=true;
//     }
//     bool search(string str,trie *head){
//         trie* curr=head;
//         ll n=str.size();
//         for(ll i=0;i<n;i++){
//             if(curr->child[str[i]-'a']==NULL){return false;}
//             curr=curr->child[str[i]-'a'];
//         }
//         return curr->ends;
//     }
//     bool startsWith(string str,trie *head){
//         trie* curr=head;
//         ll n=str.size();
//         for(ll i=0;i<n;i++){
//             if(curr->child[str[i]-'a']==NULL){return false;}
//             curr=curr->child[str[i]-'a'];
//         }
//         return 1;
//     }
// };
// class Trie{
//     Trie* child[26];
//     ll ew;
//     ll cp;
// public:
//     Trie(){
//         for(ll i=0;i<26;i++){child[i]=NULL;}
//         ew=0;cp=0;
//     }
//     void Insert(string str,Trie* head){
//         Trie*curr=head;
//         ll n=str.size();
//         for(ll i=0;i<n;i++){
//             if(curr->child[str[i]-'a']==NULL){curr->child[str[i]-'a']=new Trie;}
//             curr=curr->child[str[i]-'a'];
//             curr->cp++;
//         }
//         curr->ew++;
//     }
//     ll Search(string str,Trie *head){
//         Trie* curr=head;
//         ll n=str.size();
//         for(ll i=0;i<n;i++){
//             if(curr->child[str[i]-'a']==NULL){return 0;}
//             curr=curr->child[str[i]-'a'];
//         }
//         return curr->ew;
//     }
//     ll StartsWith(string str,Trie *head){
//         Trie* curr=head;
//         ll n=str.size();
//         for(ll i=0;i<n;i++){
//             if(curr->child[str[i]-'a']==NULL){return 0;}
//             curr=curr->child[str[i]-'a'];
//         }
//         return curr->cp;
//     }
//     void Delete(string str,Trie *head){
//         Trie* curr=head;
//         ll n=str.size();
//         for(ll i=0;i<n;i++){
//             curr=curr->child[str[i]-'a'];
//             curr->cp--;
//         }
//         (curr->ew)--;
//     }
// };
class trie_for_XOR_subarray{
public:
    trie_for_XOR_subarray* child[2];
    trie_for_XOR_subarray(){
        child[0]=NULL;child[1]=NULL;
    }
    void insert(ll arr[],ll m,trie_for_XOR_subarray*head){
        for(int j=0;j<m;j++){
        ll num=arr[j];
        trie_for_XOR_subarray* curr=head;
        for(ll i=5;i>=0;i--){
            if(curr->child[(num>>i)&1]==NULL){curr->child[(num>>i)&1]=new trie_for_XOR_subarray;}
            curr=curr->child[(num>>i)&1];
        }}
    }
    ll max_XOR(ll arr[],ll m,trie_for_XOR_subarray*head){
        ll summ=0;
        for(int k=0;k<m;k++){
        ll num=arr[k];
        trie_for_XOR_subarray*curr=head;
        ll ans=0;
        // trie_for_XOR_subarray*ptr=head;
        for(ll i=5;i>=0;i--){
            ll temp=(num>>i)&1;
            if(temp==1){
                if(curr->child[0]!=NULL){ans+=(2<<i);curr=curr->child[0];}
                else{curr=curr->child[1];}
            }
            else{
                if(curr->child[1]!=NULL){ans+=(2<<i);curr=curr->child[0];}
                else{curr=curr->child[0];}
            }
        }
        summ=max(summ,ans);
        }
        return summ;
    }
    // void printer(trie_for_XOR_subarray*head){

    // }
};
int main(){
    // trie temp;
    // trie* head=new trie;
    // temp.insert("abc",head);
    // cout<<temp.search("abd",head)<<endl;
    // temp.insert("apple",head);
    // cout<<temp.search("apple",head)<<endl;   // return True
    // cout<<temp.search("app",head)<<endl;     // return False
    // cout<<temp.startsWith("app",head)<<endl; // return True
    // temp.insert("app",head);
    // cout<<temp.search("app",head)<<endl;     // return True
    // Trie temp;
    // Trie*head=new Trie;
    // temp.Insert("app",head);
    // temp.Insert("apps",head);temp.Insert("app",head);
    // temp.Insert("apple",head);
    // temp.Delete("app",head);
    // cout<<temp.Search("app",head)<<endl<<temp.StartsWith("app",head);
    ll arr[]={3,10,5,15,2};
    trie_for_XOR_subarray temp;
    trie_for_XOR_subarray* head= new trie_for_XOR_subarray();
    temp.insert(arr,5,head);
    // temp.max_XOR(arr,5,head);
    // cout<<head->child[0];
}