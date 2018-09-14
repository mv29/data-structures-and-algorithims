#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i,n) for (i = 0; i < n; ++i)
#define FORK(i,k,n) for (i = k; i <= n; ++i)
#define FORR(i,k,n) for (i = k; i >= n; --i)

#define re(a,b)   memset(a,b,sizeof(a))
#define sz(a)      (int)(a.size())
#define MIN(a,b)     (a) = min((a),(b))
#define MAX(a,b)     (a) = max((a),(b))
#define input(in)    freopen(in,"r",stdin)
#define output(out)  freopen(out,"w",stdout)
#define ALL(a)       a.begin(),a.end()
#define RALL(a)      a.rbegin(),a.rend()
#define LEN(a)       (int)(a.length())

#define FIN(x)       freopen(x,"r",stdin)
#define FOUT(x)      freopen(x,"w",stdout)
#define FCLOSE       {fclose(stdin); fclose(stdout);}

#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define  M           100001
#define INF          1001001001

int ans=0;
void merge(int a[],int l,int mid,int r)
{
  //cout << l << " " << mid  << "  " << r  << "\n";
  int i,j,arr[r-l+1],k;
  int n=r-l+1;
  i=l;
  j=mid+1;
  FORK(j,mid+1,r)
  {
      while(a[i]<=a[j])
      {
          i++;
          if(i>mid)
            break;
      }
      if(i>mid)
        break;
   //     cout << a[i] << " " << a[j] << " " << mid << " " << i << "\n";
      ans+=mid-i+1;
  }
  i=l;
  j=mid+1;
  FOR(k,r-l+1)
  {
      if(i>mid)
      arr[k]=a[j++];
      else if (j>r)
      arr[k]=a[i++];
      else if (a[i]<=a[j])
        arr[k]=a[i++];
      else
        arr[k]=a[j++];
  }
  FOR(i,n)
  a[l++]=arr[i];
}
void mergesort(int a[],int l,int r)
{
    if(l<=r)
    {
    int mid =(l+r)/2;
    if(l==r)
     return;
     mergesort(a,l,mid);
     mergesort(a,mid+1,r);
     merge(a,l,mid,r);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);  cin.tie(0);
    int n,i;
    cin >> n;
    int a[n];
    FOR(i,n)
    cin >> a[i];
    mergesort(a,0,n-1);
    cout << ans ;
    return 0;
}
