#include"bits/stdc++.h"
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii [pair]<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N=1e5+2;
bool vis[N];
vector<int> adj[N];
bool iscyclic(int src,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &stack)
{
stack[src]=true;
if(!visited[src]){
    visited[src]=true;
    for(auto i:adj[src]){
        if(!visited[i] and iscyclic(i,adj,visited,stack)){
            return true;
        }
        if(stack[i])
        return true;
    }
}
stack[src]=false;
return false;
}
int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    rep(i,0,m){
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v); 
    //    adj[v].push_back(u);
    }
    bool cycle=false;
    vector<int> stack(n,0);
    vector<bool> visited(n,0);
    rep(i,0,n){
        if(!visited[i] and iscyclic(i,adj,visited,stack)){
            cycle=true;
        }
    }
    if(cycle)
      cout<<"Cycle is present";
    else
    cout<<" cycle is not present";


}