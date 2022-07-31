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

int32_t main()
{
    int n,m;
    cin>>n>>m;
    int cnt=0;
    vector<vector<int>> adj_list(n);
    vector<int> indeg(n,0);
    rep(i,0,m)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> pq;
    rep(i,0,n)
    {
        if(indeg[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        cnt++;
        int x=pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it: adj[x])
        {
            indeg[it]--;
            if(indeg[it]==0)
            pq.push(it);
        }
    }
}