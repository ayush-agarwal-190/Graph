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

vector<bool> vis;
vector<int> col;
vector<vector<int>> adj;
bool bipart=true;;

void color(int u,int curr){
    if(col[u]!=-1 and col[u]!=curr){
        bipart=false;
        return;
    }
    col[u]=curr;
    if(vis[u])
    return;
    vis[u]=true;
    for(auto i:adj[u]){
        color(i,curr xor 1);
        // 0 xor 1=1
        // 1 xor 1=0
    }

}
int32_t main()
{
    int n,m;
    cin>>n>>m;
    adj=vector<vector<int>>(n);
    vis=vector<bool>(n,false);
    col=vector<int>(n-1);

    rep(i,0,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   rep(i,0,n){
    if(!vis[i]){
        color(i,0);
    }
   }
if(bipart)
cout<<"Graph is Bipart"<<endl;
else
cout<<"Graph is not biparted"<<endl;
  

}