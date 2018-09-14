#include<bits/stdc++.h>
using namespace std;
typedef long long int lli ;
#define J 100001
vector<int> a[j]; //it is an array of vectors
bool b[j];
 long int c[J];
 long int d[J];
long int l[J];
 long int p[J];
 bool ar[J];
 long int k;
 long int t;
void dfs( int s, int t)
{
    b[s] = true;
    int children=0;
     d[s]=t+1;
     l[s]=t+1;
    for( int i = 0; i< a[s].size();++i)
    {
     if(b[a[s][i]] == false)
      {
          children++;
      p[a[s][i]]=s;
      dfs(a[s][i],t+1);
      l[s]=min(l[s],l[a[s][i]]);
       if((p[s]==-1 && children>1) || p[s]!=-1 && (l[a[s][i]]>=d[s]))
       {
            ar[s]=true;
       }
     }
      else if(a[s][i]!=p[s])
      l[s]=min(l[s],d[a[s][i]]);
    }
}
       void initialize() {
        for( int i = 0;i <J;++i)
        {
        ar[i]=false;
        d[i]=0;
        l[i]=1000;
        p[i]=-1;
        b[i] = false;
        }
    }
int main()
    {
       ios_base::sync_with_stdio(false);
        k=0;
        t=0;
        int x, y, n,m,i,r=0;
        cin >> n >> m;
        initialize();
        while(m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
         }
         for(i=1;i<=n;i++)
         {
             if(b[i]==false)
            dfs(i,0);
         }
         int q;
         cin >> q;
         while(q--)
         {
             cin >> x;
             if(ar[x]==true)
             cout << "Satisfied "  << a[x].size() << "\n";
             else
             cout << "Not Satisfied\n";
         }
    return 0;
    }
