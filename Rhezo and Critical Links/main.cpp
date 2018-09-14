#include<bits/stdc++.h>
using namespace std;
typedef long long int lli ;
vector <int> a[100001]; //it is an array of vectors
bool b[1000001];
 int c[1000001];
int k;
void dfs(long long int s,long long int ans)
{
    b[s] = true;
     }
     k++;
    for(int i = 0;i < a[s].size();++i)
    {
     if(b[a[s][i]] == false)
      {
          dfs(a[s][i],s);
      }
    }
}
    void initialize() {
        for(int i = 0;i <1000001;++i)
         b[i] = false;
    }
int main()
    {
       ios_base::sync_with_stdio(false);
        k=0;
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
              {
                  dfs(i,0);
                  c[i]=k;
                  dfs()
              }
         }
         for(i=0;i<n;i++)
         {
             dfs
         }
         cout << k << "\n";
    return 0;
    }
