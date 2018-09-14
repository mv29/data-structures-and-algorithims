#include<bits/stdc++.h>
using namespace std;
typedef long long int lli ;
vector<int> a[100001]; //it is an array of vectors
bool b[1000001];
 int c[1000001];
 int d[1000001];
 int l[1000001];
 int p[1000001];
 bool ar[1000001];
 vector<int> h[1000001];
 int t;
void dfs(int s,int v, long int t)
{
    b[s] = true;
    int children=0;
     d[s]=t+1;
     l[s]=t+1;
    for(int i = 0; i< a[s].size();++i)
    {
     if(b[a[s][i]] == false)
     {
          children++;
      p[a[s][i]]=s;
      dfs(a[s][i],v,t+1);
      l[s]=min(l[s],l[a[s][i]]);
       if(l[a[s][i]]>d[s])
        h[s].push_back(a[s][i]);
      }
      else if(a[s][i]!=p[s])
      l[s]=min(l[s],d[a[s][i]]);
    }
}
       void initialize() {
        for(int i = 0;i <1000001;++i)
        {
        ar[i]=false;
        d[i]=0;
        l[i]=100000000;
        p[i]=-1;
        b[i] = false;
        }
    }
int main()
    {
       ios_base::sync_with_stdio(false);
        k=0;
        t=0;
        q=0;
        int x, y, n,m,i,r=0;
        cin >> n >> m;
        initialize();
        while(m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
         }
         for(i=0;i<n;i++)
         {
             if(b[i]==false)
            dfs(i,n,0);
         }
         cout << "\n";
         for(i=0;i<n;i++)
         {
             if(h[i].size()>0)
             {
                 sort(h[i].begin(),h[i].end());
                 for(int g=0;g<h[i].size();g++)
                 cout << i << " " << h[i][g] << "\n";
             }
         }
    return 0;
    }
