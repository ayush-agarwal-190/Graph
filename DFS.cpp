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

void dfs(int node)
{
    //preorder
    vis[node]=1;
    cout<<node<<" ";
    //inorder
    vector<int> :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(vis[*it]);
        else
        {
            dfs(*it);
        }

    }
    //postorder

}
int main()
{
   int n,m;
   cin>>n>>m;
rep1(i,0,n){
    vis[i]=false;
}

   int x,y;
   rep(i,0,m){
    cin>>x>>y;
   adj[x].push_back(y);
   adj[y].push_back(x);
   }
dfs(1);
    return 0;
}
