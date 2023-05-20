#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int N=1e5+7;
//****max segment tree****

void max_build_tree(ll max_tree[],int node,int start,int end,ll arr[]){
    if(start==end){max_tree[node]=arr[start];return;}
    int mid=(start+end)/2;
    max_build_tree(max_tree,2*node+1,start,mid,arr);
    max_build_tree(max_tree,2*node+2,mid+1,end,arr);
    max_tree[node]=max(max_tree[2*node+2],max_tree[2*node+1]);
    return;
}
ll max_query(int node,ll tree[],int i,int j,int start,int end){
    if(i<end){return 0;}
    else if(j>start){return 0;}
    else if(start>=i && end<=j){return tree[node];}
    ll mid=(start+end)/2;
    ll t1=max_query(2*node+1,tree,i,j,start,mid);
    ll t2=max_query(2*node+2,tree,i,j,mid+1,end);
    return max(t1,t2);
}

// ********sum segment tree*********

void build_tree(ll tree[],int node,int start,int end,ll arr[]){
    if(start==end){tree[node]=arr[start];return;}
    int mid=(start+end)/2;
    build_tree(tree,2*node+1,start,mid,arr);
    build_tree(tree,2*node+2,mid+1,end,arr);
    tree[node]=tree[2*node+1]+tree[2*node+2];
    return;
}
int query(ll tree[],int node,int start,int end,ll arr[],int i,int j){
    if(end<i){return 0;}
    if(start>j){return 0;}
    if(start<=i && end>=j){return tree[node];}
    int mid=(i+j)/2;
    int q1=query(tree,2*node+1,start,end,arr,i,mid);
    int q2=query(tree,2*node+2,start,end,arr,mid+1,j);
    return q1+q2;
}

// ********max/min segment tree***********
// first-->value  AND second-->number
void max_min_build_tree(pair<ll,ll> max_min_tree[],int node,int start,int end,ll arr[],string type){
    if(start==end){max_min_tree[node].first=arr[start];max_min_tree[node].second=1;return;}
    int mid=(start+end)/2;
    max_min_build_tree(max_min_tree,2*node+1,start,mid,arr,type);
    max_min_build_tree(max_min_tree,2*node+2,mid+1,end,arr,type);
    if(type=="max"){
        if(max_min_tree[2*node+1]==max_min_tree[2*node+2]){
            max_min_tree[node].first=max_min_tree[2*node+1].first;
            max_min_tree[node].second=max_min_tree[2*node+1].second+max_min_tree[2*node+2].second;
        }
        if(max_min_tree[2*node+1]>max_min_tree[2*node+2]){
            max_min_tree[node].first=max_min_tree[2*node+1].first;
            max_min_tree[node].second=max_min_tree[2*node+1].second;
        }
        if(max_min_tree[2*node+1]<max_min_tree[2*node+2]){
            max_min_tree[node].first=max_min_tree[2*node+2].first;
            max_min_tree[node].second=max_min_tree[2*node+2].second;
        }
    }
    if(type=="min"){
        if(max_min_tree[2*node+1]==max_min_tree[2*node+2]){
            max_min_tree[node].first=max_min_tree[2*node+1].first;
            max_min_tree[node].second=max_min_tree[2*node+1].second+max_min_tree[2*node+2].second;
        }
        if(max_min_tree[2*node+1]<max_min_tree[2*node+2]){
            max_min_tree[node].first=max_min_tree[2*node+1].first;
            max_min_tree[node].second=max_min_tree[2*node+1].second;
        }
        if(max_min_tree[2*node+1]>max_min_tree[2*node+2]){
            max_min_tree[node].first=max_min_tree[2*node+2].first;
            max_min_tree[node].second=max_min_tree[2*node+2].second;
        }
    }
    return;
}
pair<ll,ll> max_min_tree_query(pair<ll,ll> max_min_tree[],int node,int start,int end,int i,int j,string type){
    if(start>=i && end<=j){return max_min_tree[node];}
    if(end<i){return make_pair(100000,0);}
    if(start>j){return make_pair(100000,0);}
    int mid=(start+end)/2;
    pair<ll,ll> q1=max_min_tree_query(max_min_tree,2*node+1,start,mid,i,j,type);
    pair<ll,ll> q2=max_min_tree_query(max_min_tree,2*node+2,mid+1,end,i,j,type);
    if(type=="max"){
        if(q1.first==q2.first){
            pair<ll,ll>temp=make_pair(q1.first,q1.second+q2.second);return temp;
        }
        if(q1.first>q2.first){
            pair<ll,ll>temp=make_pair(q1.first,q1.second);return temp;
        }
        if(q1.first<q2.first){
            pair<ll,ll>temp=make_pair(q2.first,q2.second);return temp;
        }
    }
    if(type=="min"){
        if(q1.first==q2.first){
            pair<ll,ll>temp=make_pair(q1.first,q1.second+q2.second);return temp;
        }
        if(q1.first<q2.first){
            pair<ll,ll>temp=make_pair(q1.first,q1.second);return temp;
        }
        if(q1.first>q2.first){
            pair<ll,ll>temp=make_pair(q2.first,q2.second);return temp;
        }
    }
}
// void max_min_tree_update(int ind,int node,int start,int end,pair<ll,ll> max_min_tree[],ll arr[],string type){
//     if(ind>end){return;}
//     if(ind<start){return;}
//     if(start==end){if(start==ind){max_min_tree[node].first=arr[ind];}return;}
//     int mid=(start+end)/2;
//     max_min_tree_update(ind,2*node+1,start,mid,max_min_tree,arr,type);
//     max_min_tree_update(ind,2*node+2,mid+1,end,max_min_tree,arr,type);
//     if(type=="max"){
//         if(max_min_tree[2*node+1]==max_min_tree[2*node+2]){
//             max_min_tree[node].first=max_min_tree[2*node+1];
//             max_min_tree[node].second=max_min_tree[2*node+1].second+max_min_tree[2*node+2].second;
//         }
//         if(max_min_tree[2*node+1]>max_min_tree[2*node+2]){
//             max_min_tree[node].first=max_min_tree[2*node+1];
//             max_min_tree[node].second=max_min_tree[2*node+1].second;
//         }
//         if(max_min_tree[2*node+1]<max_min_tree[2*node+2]){
//             max_min_tree[node].first=max_min_tree[2*node+2];
//             max_min_tree[node].second=max_min_tree[2*node+2].second;
//         }
//     }
//     if(type=="min"){
//         if(max_min_tree[2*node+1]==max_min_tree[2*node+2]){
//             max_min_tree[node].first=max_min_tree[2*node+1];
//             max_min_tree[node].second=max_min_tree[2*node+1].second+max_min_tree[2*node+2].second;
//         }
//         if(max_min_tree[2*node+1]<max_min_tree[2*node+2]){
//             max_min_tree[node].first=max_min_tree[2*node+1];
//             max_min_tree[node].second=max_min_tree[2*node+1].second;
//         }
//         if(max_min_tree[2*node+1]>max_min_tree[2*node+2]){
//             max_min_tree[node].first=max_min_tree[2*node+2];
//             max_min_tree[node].second=max_min_tree[2*node+2].second;
//         }
//     }
//     return;
// }

// **** segment tree + binary search *****

void min_ind_greater(int &ind,int node,int start,int end,ll max_tree[],ll arr[],ll value){
    if(start==end){if(arr[start]>=value){ind=min(ind,start);}return;}
    ll mid=(start+end)/2;
    if(max_tree[2*node+1]>=value){min_ind_greater(ind,2*node+1,start,mid,max_tree,arr,value);}
    else if(max_tree[2*node+2]>=value){min_ind_greater(ind,2*node+2,mid+1,end,max_tree,arr,value);}
    return;
}

//****

int main(){
    ll n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];}
    ll tree[4*n];pair<ll,ll> max_min_tree[4*n];
    // pair<ll,ll>temp=make_pair(0,0);
    // memset(max_min_tree,temp,sizeof(max_min_tree));
    memset(tree,0,sizeof(tree));
    int index=n+100;
    // for(int i=0;i<=4*n;i++){max_min_tree[i]=temp;}
    max_build_tree(tree,0,0,n-1,arr);
    // max_min_build_tree(max_min_tree,0,0,n-1,arr,"min");
    // for(int i=0;i<=2*n;i++){cout<<max_min_tree[i].first<<" "<<max_min_tree[i].second<<endl;}
    min_ind_greater(index,0,0,n-1,tree,arr,4);
    arr[2]=2;
    // max_min_tree_update(2,0,0,n-1,max_min_tree,arr);
    // for(int i=0;i<=2*n;i++){cout<<tree[i]<<" ";}
    cout<<index;
    // temp= max_min_tree_query(max_min_tree,0,0,n-1,0,n-1,"min");
    // cout<<temp.first<<" "<<temp.second;
    // cout<<max_min_tree_query(max_min_tree,0,0,n-1,1,n-3);
}
// 6
// 1 3 5 7 9 11
// 9
// 2 4 6 8 10 12 14 16 18