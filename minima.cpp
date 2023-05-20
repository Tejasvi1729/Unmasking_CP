#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t;cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n;
        cin>>k;
        int freq[101];
        for(int p=0;p<101;p++){
            freq[p]=0;
        }
        int temp;
        for(int v=0;v<k;v++){
            cin>>temp;
            freq[temp]+=1;
        }
        for(int a=1;a<(k+1);a++){
            cout<<freq[a]<<" ";
        }
        cout<<endl;
    }
    
}