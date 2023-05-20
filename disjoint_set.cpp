#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class disjoint_set{
    ll* parent;
    ll* rank;
public:
    disjoint_set(int n){
        parent=new ll[n+1];rank=new ll[n+1];
        for(int i=0;i<=n;i++){parent[i]=i;rank[i]=0;}
    }
    ll find_parent(ll data){
        if(data==parent[data]){return data;}
        data=parent[data];
        return data;
    }
    void unionn(ll u,ll v){
        ll pu=find_parent(u);ll pv=find_parent(v);
        if(rank[pu]==rank[pv]){
            parent[pv]=pu;rank[pu]++;
        }
        else if(rank[pu]>rank[pv]){parent[pv]=pu;}
        else{parent[pu]=pv;}
    }
    
};
// bool comparatorf(vector<pair<ll,ll> > &a, vector<pair<ll,ll> > &b)
// {
//     if(a.second>b.second)return true;
//     // return a.F<=b.F;
//     return false;
// }
void cycle_detection_undirected(ll n,vector<vector<ll> >v,bool &poss){
    disjoint_set ds(n);
    for(ll i=1;i<=n;i++){
        ll pu=ds.find_parent(i);
        for(auto x:v[i]){
            ll pv=ds.find_parent(x);
            if(pu==pv){poss=0;break;}
            else{ds.unionn(i,x);}
        }
    }
    return;
}
void kurskel(ll n,ll m,vector<pair<ll,pair<ll,ll> > > adjl){
    disjoint_set ds(n);
    bool arr[1000]={0};
    ll i=1;
    for(auto x:adjl){
        ll w=x.first;
        pair<ll,ll> temp=x.second;
        ll n1=temp.first;ll n2=temp.second;
        ll pn1=ds.find_parent(n1);ll pn2=ds.find_parent(n2);
        if(pn1!=pn2){ds.unionn(n1,n2);arr[i]=1;}
        i++;
    }
    for(int i=1;i<=m;i++){cout<<arr[i]<<" ";}
}
// void prims(ll n,ll m,vector<pair<ll,pair<ll,ll> > > adjl){
    
// }

// u weight v
void dijakstra(vector<vector<pair<ll,ll> > >adjl,ll n,priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > &q,ll dis[]){
    if(q.empty()){return;}
    pair<ll,ll> temp=q.top();
    q.pop();
    for(auto x:adjl[temp.second]){
        ll tt1=temp.first+x.first;
        if(dis[x.second]>=tt1){
            dis[x.second]=tt1;q.push(make_pair(tt1,x.second));
        }
        else{continue;}
    }
    dijakstra(adjl,n,q,dis);
    return;
}
// w u v
void bellman_ford(vector<pair<ll,pair<ll,ll> > >adjl,ll n,ll dis[]){
    for(ll i=1;i<n;i++){
        for(auto x:adjl){
            pair<ll,pair<ll,ll> > rec=x;
            ll w=rec.first;pair<ll,ll> edges=rec.second;
            if(dis[edges.first]==1e10){continue;}
            else{dis[edges.second]=min(dis[edges.second],dis[edges.first]+rec.first);}
        }
    }
    return;
}
int main(){
    ll n,m;
    cin>>n>>m;
    // n=7;
    // u v weight
    vector<ll> temm;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >ttt;
    // priority_queue<ll, vector<ll>, greater<ll> > ttt;
    vector<pair<ll,pair<ll,ll> > > adjl;
    // vector<vector<pair<ll,ll> > >adjl(n+1);// u w v
    ll dis[n+1];
    for(ll i=0;i<=n;i++){dis[i]=1e10;}
    for(int i=0;i<m;i++){
        ll n1,n2,w;cin>>w>>n1>>n2;
        pair<ll,ll> tt=make_pair(n1,n2);
        adjl.push_back(make_pair(w,tt));
        // adjl[n2].push_back(make_pair(w,n1));
        // adjl[n1].push_back(make_pair(w,n2));
    }
    // ttt.push(make_pair(0,1));
    dis[1]=0;
    // dijakstra(adjl,n,ttt,dis);
    // for(ll i=1;i<=n;i++){
    //     cout<<dis[i]<<" ";
    // }
    // while(ttt.empty()==0){
    //     cout<<ttt.top().first<<" "<<ttt.top().second<<endl;
    //     // cout<<ttt.top()<<endl;
    //     ttt.pop();
    // }
    // bool ppp=1;
    // kurskel(n,m,adjl);
    bellman_ford(adjl,n,dis);
     for(ll i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}
// 6 9
// 1 1 4
// 2 1 2
// 3 2 3
// 3 2 4
// 4 1 5
// 5 3 4
// 7 2 6
// 8 3 6
// 9 4 5

/* dijakstra test case
6 6
1 1 4
1 3 5
2 1 2
3 4 3
4 2 3
5 2 5
*/