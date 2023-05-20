#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void bfs(ll visited[],queue<ll> &q,vector<vector<ll> >v){
    if(q.empty()){return;}
    ll i=q.front();
    for(auto x:v[i]){
        if(visited[x]==0){
            visited[x]=1;
            q.push(x);
        }
    }
    cout<<q.front()<<" ";q.pop();
    bfs(visited,q,v);
    return;
}
void dfs(ll visited[],vector<vector<ll> >v,ll rec,ll &count){
    if(count == 7){return;}
    for(auto x:v[rec]){
        if(visited[x]==0){
            cout<<(x);
            visited[x]=1;
            count++;
            dfs(visited,v,x,count);
        }
    }
    return;
}
void dfs_topological(ll visited[],vector<vector<ll> >v,ll rec,stack<ll> &s){
    if(v[rec].size()==0){return;}
    
    for(auto x:v[rec]){
        if(visited[x]==0){
            // count++;
            dfs_topological(visited,v,x,s);
            visited[x]=1;
            s.push(x);
        }
    }
    return;
}
void cycle_detection_undirected(bool visited[],vector<vector<ll> >v,ll curr,ll parent,bool &poss){
    if(v[curr].size()==0){return;}
    visited[curr]=1;
    for(auto x:v[curr]){
        if(x!=parent && visited[x]==1){
            // cout<<x<<" ";
            poss=0;
        }
        else if(x!=parent && visited[x]==0){
            visited[x]=1;
            cycle_detection_undirected(visited,v,x,curr,poss);
        }
    }
    return;
}
void cycle_detection_directed(bool visited[],bool dfsvisited[],vector<vector<ll> >v,ll curr,ll parent,bool &poss){
    if(v[curr].size()==0){return;}

    visited[curr]=1;
    dfsvisited[curr]=1;
    for(auto x:v[curr]){
        if(x==parent){continue;}
        else if(visited[x]==0 && dfsvisited[x]==0){
            visited[x]=1;dfsvisited[x]=1;
            cycle_detection_directed(visited,dfsvisited,v,x,curr,poss);
            dfsvisited[x]=0;
        }
        else if(visited[x]==1 && dfsvisited[x]==1){
            poss=1;
        }
        else if(visited[x]==1 && dfsvisited[x]==0){
            visited[x]=1;dfsvisited[x]=1;
            cycle_detection_directed(visited,dfsvisited,v,x,curr,poss);
            dfsvisited[x]=0;
        }
    }
    dfsvisited[curr]=0;
    return;
}
ll connected_components(bool visited[],vector<vector<ll> >v,ll curr){
    if(v[curr].size()==0){return 1;}
    ll ans=1;
    for(auto x:v[curr]){
        if(visited[x]==1){
            continue;
        }else{
            visited[x]=1;
            ans+=connected_components(visited,v,x);
        }
    }
    return ans;
}
void bipartite_graph(vector<vector<ll> >v,queue<ll> &q,char color[],bool &p){
    if(q.empty()){return;}
    // if()
    ll curr=q.front();
    char col=color[curr];
    for(auto x:v[curr]){
        if(color[x]=='W'){
            if(col=='R'){color[x]='B';}
            else{color[x]='R';}
            q.push(x);
        }
        else if(color[x]==col){p=0;}
    }
    q.pop();
    bipartite_graph(v,q,color,p);
    return;
}
ll paths(vector<vector<ll> >board,ll i,ll steps[]){
    if(i==100){return 0;}
    ll ans=20;
    for(auto x:board[i]){
        ll kk=steps[x];
        if(kk==-1){kk=paths(board,x,steps);if((x-i)>6 || (x-i)<-6){kk--;}}
        ans=min(ans,kk);
    }
    steps[i]=ans+1;
    return ans+1;
}
void snake_ladders(){
    vector<vector<ll> >board(100);ll step[101];
    ll ladder,snakes;snakes=0;
    cin>>ladder;
    for(ll i=0;i<ladder;i++){ll t1,t2;cin>>t1>>t2;board[t1].push_back(t2);}
    cin>>snakes;
    for(ll i=0;i<snakes;i++){ll t1,t2;cin>>t1>>t2;board[t1].push_back(t2);}
    for(ll i=1;i<100;i++){
        step[i]=-1;
        if(board[i].empty()){ll ii=i+1;ll c=0;while(ii<=100&&c<6){board[i].push_back(ii);ii++;c++;}}
    }
    step[100]=0;
    cout<<paths(board,1,step);
    // for(ll i=1;i<=100;i++){
    //     cout<<i<<"->";
    //     for(auto x:board[i]){cout<<x<<" ";}
    //     cout<<endl;
    // }
}
int main(){
    // ll n,m;
    // cin>>n>>m;
    // bool visit[n+1]={0};visit[1]=1;
    // bool dfsvisit[n+1]={0};dfsvisit[1]=1;
    // vector<ll> temm;
    // vector<vector<ll> > adjl(1+n,temm);
    // for(int i=0;i<m;i++){
    //     ll n1,n2;cin>>n1>>n2;
    //     adjl[n1].push_back(n2);
    //     adjl[n2].push_back(n1);
    // }
    snake_ladders();
    // char color[n+1];for(int i=0;i<n;i++){color[i+1]='W';}color[1]='R';
    // bool bb=1;queue<ll> q;
    // q.push(1);
    // bipartite_graph(adjl,q,color,bb);
    // cout<<bb;
    // for(int i=0;i<n;i++){cout<<color[i+1]<<" ";}
}
// 7 7
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7
// 7 3

// 3 3
// 1 2
// 2 3
// 3 1