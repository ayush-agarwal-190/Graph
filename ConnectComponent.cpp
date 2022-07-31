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
int n,m;
vector<vector<int>> adj;
vector<int> components;

int get_comp(int idx){
    if(vis[idx])
     return 0;
    vis[idx]=true;
    int ans=1;
    for(auto i:adj[idx]){
        if(!vis[i]){
        ans+=get_comp(i);
        vis[i]=true;
        }
    }
    return ans;
}
int32_t main()
{
    cin>>n>>m;
    adj=vector<vector<int>>(n);
    vis=vector<bool>(n);
    rep(i,0,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   rep(i,0,n){
    if(!vis[i]){
        components.push_back(get_comp(i));
    }
   }
//    for(auto i: components)
//       {
//         cout<<i<<" ";
//       }
   long long ans=0;
   for(auto i: components)
      {
        ans+=i*(n-i);
      }
      cout<<(ans/2);

}