#include<bits/stdc++.h>
#define siz 100001
using namespace std;
vector<int>v[siz];
bool vis[siz],art[siz];
int n,num[siz],parent[siz],low[siz];
stack<int>st;
int k;
void dfs(int u)
{
	static int time=1;
	int children=0;
	vis[u]=1;
	num[u]=low[u]=time++;
	for(int i=0;i<v[u].size();i++)
	{
		int curr=v[u][i];
		if(!vis[curr])
		{
			children++;
			parent[curr]=u;
			dfs(curr);
			low[u]=min(low[u],low[curr]);
			if((!parent[u] && children>1) || (parent[u] && low[curr]>=num[u])){

                    k++;
                    art[u]=1;
			}
		}
		else if(curr!=parent[u])
			low[u]=min(low[u],num[curr]);
	}
}
int main()
{
	int n,m,q,p;
	scanf("%d%d%d",&n,&m,&p);
	int i;
	k=0;
	for(i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	cout << k << "\n";
	return 0;
}
