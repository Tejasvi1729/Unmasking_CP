#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll M=(1e9)+7;
class Euclid{
public:
    ll x,y,gcd;
};
Euclid Extended_Euclideon(ll a,ll b){
    if(b==0){
        Euclid temp;temp.x=1;temp.y=0;temp.gcd=a;return temp;
    }
    if(b==1){
        Euclid temp;temp.x=0;temp.y=1;temp.gcd=1;return temp;
    }
    Euclid temp=Extended_Euclideon(b,a%b);
    Euclid ans;
    ans.gcd=temp.gcd;ans.x=temp.y;ans.y=temp.x-(a/b)*temp.y;
    return ans;
}
ll mutliplicative_modulo_inverse(ll a,ll m){
    Euclid tt=Extended_Euclideon(a,m);
    return tt.x>0?tt.x:tt.x+m;
}
void euler_totient(ll n){
    ll totient[n+1];
    for(ll i=0;i<=n;i++){
        totient[i]=i;
    }
    for(ll i=2;i<=n;i++){
        if(totient[i]==i){
            for(ll j=2*i;j<=n;j+=i){totient[j]*=(i-1);totient[j]/=i;}
        }
        totient[i]--;
    }
    for(ll i=2;i<=n;i++){cout<<totient[i]<<" ";}
}
// ll binary_exponentiation_recursive(ll a,ll n){
//     if(n==0){return 1;}
//     ll temp=binary_exponentiation_recursive(a,n/2);
//     if(n%2){return temp*temp*a;}
// }
ll binary_exponentiation_iterative(ll a,ll n){
    ll ans=1;
    while(n>0){
        if(n&1){ans*=a;ans=ans%M;}
        a*=a;
        n/=2;
    }
    return ans%M;
}
ll maximum_XOR_subarray(ll arr[],ll n){
    
}
int main(){
    // Euclid tt=Extended_Euclideon(10,7);
    // cout<<tt.x<<" "<<tt.y<<" "<<tt.gcd;
    ll a,b;cin>>a>>b;
    // cout<<mutliplicative_modulo_inverse(a,b);
    // euler_totient(b);
    cout<<binary_exponentiation_iterative(a,b);
}