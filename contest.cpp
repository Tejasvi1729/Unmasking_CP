// #include <iostream>
// using namespace std;
// bool possible(int arr[],int i,int sum,int n,int dp[][1001]){
//     if(sum<0){
//         return 0;
//     }
//     if(i==n){
//         return 0;
//     }
//     if(dp[i][sum]!=-1){
//         return dp[i][sum];
//     }
//     bool p1=possible(arr,i+1,sum,n,dp);
//     bool p2=possible(arr,i+1,sum-arr[i],n,dp);
//     dp[i][sum]=p1||p2;
//     return p1||p2;
// }
// int main() {
//     int t;cin>>t;
//     while(t--){
//         int sum;cin>>sum;
//         int n;cin>>n;
//         int v[n];
//         int dp[n][1001];
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=sum;j++){
//                 if(j==0){dp[i][j]=1;}
//                 dp[i][j]=-1;
//             }
//         }
        
//         for(int i=0;i<n;i++){
//             cin>>v[i];
//         }
//         bool b=possible(v,0,sum,n,dp);
//         if(b){
//             cout<<"YES"<<endl;
//         }
//         else{
//             cout<<"NO"<<endl;
//         }
//     }
// 	return 0;
// }
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll gcd(ll a,ll b){
    if(b==1){return 1;}
    if((a%b)==0){return b;}
    ll ttt=a%b;
    return gcd(b,ttt);
}
int main() {
    ll t;
    cin>>t;
    while(t--){
       ll n;
       cin>>n;
       string s;
       cin>>s;
       ll l=0;ll r=n-1;
    //   if((n%2)==0){
           while(l<r){
               if(s[l]=='0' && s[r]=='1'){l++;r--;}
               else if(s[r]=='0' && s[l]=='1'){l++;r--;}
               else{break;}
           }
           if(l>r){cout<<0<<endl;}
           else if(l==r){cout<<1<<endl;}
           else{cout<<(r-l+1)<<endl;}
    //   }
    }
	return 0;
}