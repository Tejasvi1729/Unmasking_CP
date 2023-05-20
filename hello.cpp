#include <bits/stdc++.h>
using namespace std;

int Solution(vector<int> &A, int B) {
    int n=A.size();
    int i=0;int j=1;
    // vector<int>niga;
    // for(int i=0;i<n;i++){niga.push_back((-1)*)}
    if((A[n-1]-A[0])<B){return 0;}
    if(n==0){return 0;}
    
    while(i<j){
		// cout<<i<<" "<<j<<endl;
		if((A[j]-A[i])==B){return 1;}
		while(j<n){
			j++;
			// cout<<i<<" "<<j<<endl;
			if((A[j]-A[i])==B){return 1;}
			if((A[j]-A[i])>B){break;}
		}
		if((A[j]-A[i])==B){return 1;}
		i++;j=i+1;
		// cout<<i<<" "<<j<<endl;
        // if(j-1!=i){if((A[j-1]-A[i])==B){return 1;}}
        // if(j+1!=i){if((A[j]-A[i-1])==B){return 1;}}
        // j--;i++;
    }
    return 0;
}
// 33 0 1 9 10 13 17 17 17 23 25 29 30 37 38 39 39 40 41 42 60 64 70 70 70 72 75 85 85 90 91 91 93 95
// 83
void Is_BT_BST()
int main()
{
    int n;cin>>n;int b;
	vector<int> a(n,0);for(int i=0;i<n;i++){cin>>a[i];}cin>>b;
	Solution(a,b);
    // while(t--){
	// 	unordered_map<string, vector<int> >record;
	// 	int n;cin>>n;
	// 	string temp;
	// 	// string first[n];
	// 	// string second[n];
	// 	// string third[n];
	// 	// for(int i=0;i<n;i++){
	// 	// 	cin>>first[i];
	// 	// }
	// 	// for(int i=0;i<n;i++){
	// 	// 	cin>>second[i];
	// 	// }
	// 	// for(int i=0;i<n;i++){
	// 	// 	cin>>third[i];
	// 	// }
	// 	for(int i=0;i<n;i++){
	// 		cin>>temp;
	// 		record[temp].second.push_back(1);
	// 	}
	// 	for(int i=0;i<n;i++){
	// 		cin>>temp;
	// 		record[temp].second.push_back(2);
	// 	}
	// 	for(int i=0;i<n;i++){
	// 		cin>>temp;
	// 		record[temp].third.push_back(3);
	// 	}
	// 	int p[4]=0;
	// 	for(auto x:record){
	// 		if(x.second.length()==3){continue;}
	// 		else if(x.second.length()==2){
	// 			p[x.second[0]]++;
	// 			p[x.second[1]]++;
	// 		}
	// 		else{
	// 			p[x.second[0]]+=3;
	// 		}
	// 	}
	// 	cout<<p[1]<<" "<<p[2]<<" "<<p[3]<<endl;
    // }
}