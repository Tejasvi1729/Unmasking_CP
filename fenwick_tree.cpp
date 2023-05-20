#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll M=(1e9)+7;

ll fetcher(ll i,ll j,ll bit[]){
    ll sj=0;ll si=0;
    while(j>0){
        ll tmm=(j&(-1*j));
        sj+=bit[j];
        j=j-tmm;
    }
    while(i>0){
        ll tmm=(i&(-1*i));
        si+=bit[i];
        i=i-tmm;
    }
    return sj-si;
}
void builder(ll tree[],ll arr[],int n){
    for(int i=0;i<n;i++){
        ll tmm=i+1;
        while(tmm<=n){
            tree[tmm]+=arr[i];
            tmm+=(tmm&(-1*tmm));
        }
    }
}
//***square root decomposition***

void create(ll arr[],ll comp[],ll len,int n){
    for(int i=0;i<n;i++){comp[i/len]=min(arr[i],comp[i/len]);}
}
ll fetch(ll arr[],ll compos[],ll len,int i,int j){
    int l=i/len;int r=j/len;
    ll summ=INT_MAX;
    for(int p=(l+1);p<r;p++){summ=min(summ,compos[p]);}
    while(i<(l+1)*len){summ=min(arr[i],summ);i++;}
    while(j>=(r)*len){summ=min(arr[j],summ);j--;}
    return summ;
}
int main(){
    ll n;cin>>n;
    ll arr[n];
    ll tree[n+1]={0};tree[0]=0;
    for(int i=0;i<n;i++){cin>>arr[i];}
    // builder(tree,arr,n);
    // // for(int i=1;i<=n;i++){cout<<tree[i]<<" ";}
    // cout<<fetcher(3,6,tree);
    ll len=sqrtl(n);
    if(len*len!=n){len++;}
    ll compos[len+10];
    for(int i=0;i<=len+5;i++){compos[i]=INT_MAX;}
    create(arr,compos,len,n);
    cout<<fetch(arr,compos,len,8,13);
    // for(int i=0;i<len+5;i++){cout<<compos[i]<<" ";}
}
// 16 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
