#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll steps=0;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]>=arr[i]){continue;}
        else{steps+=arr[i]-arr[i+1];arr[i+1]=arr[i];}
    }
    cout<<steps;
}