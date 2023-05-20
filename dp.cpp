#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll min_no_of_square(ll n,ll arr[]){
    if(n==1){return 1;}
    else if(n==0){return 0;}
    ll ans=1000;
    for(ll i=1;i*i<=n;i++){
        if(arr[n-i*i]==-1){
            arr[n-i*i]=min_no_of_square(n-i*i,arr);
        }
        ans=min(arr[n-i*i],ans);
    }
    arr[n]=ans+1;
    return ans+1;
}
ll nth_stair(ll n, ll dp[]){
    for(ll i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    ll n;
    cin>>n;
    ll dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;dp[1]=1;dp[2]=2;
    cout<<nth_stair(n,dp);
}