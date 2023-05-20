#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll M=(1e9)+7;
int kmp(string haystack,string needle){
    if(needle==""){return 1;}
    int lps[needle.size()]={0};
    int i=0;int j=1;
    while(j<needle.size()){
        if(needle[i]==needle[j]){lps[j]=i+1;j++;i++;}
        else if(i==0){needle[j]=0;j++;}
        else{i=needle[i-1];}
    }
    i=0;//for needle
    j=0;//for haystack
    while(j<haystack.size()){
        if(haystack[j]==needle[i]){j++;i++;}
        else if(i==0){j++;}
        else{i=lps[i-1];}
        if(i==needle.size()){return j-i;}
    }
    return -1;
}
bool comp(string haystack,string needle,int ind){
    for(int i=0;i<needle.size();i++){
        if(haystack[ind+i]!=needle[i]){return 0;}
    }return 1;
}
ll RabinKarp(string haystack,string needle){
    if(needle==""){return 0;}
    int n=haystack.size();
    ll len=needle.size();ll hash=0;
    ll hash_h=0;
    ll hashes[len];hashes[0]=1;
    for(int i=1;i<len;i++){hashes[i]=((hashes[i-1]%M)*(107))%M;}
    for(int i=0;i<len;i++){hash+=(hashes[i]*(needle[i]-'a'+1))%M;hash_h+=(hashes[i]*(haystack[i]-'a'+1))%M;}
    if(hash==hash_h){if(comp(haystack,needle,0)){return 0;}}
    for(int i=len;i<(n-len);i++){
        hash_h=hash_h/107;hash_h+=(hashes[len-1]*(haystack[i-1]-'a'+1))%M;
        if(hash==hash_h){
            if(comp(haystack,needle,i+1-len)){return i+1-len;}
        }
    }
    return -1;
}
int main(){
    string s1="abcd";string s2="ab";
    cout<<(kmp(s1,s2));
}