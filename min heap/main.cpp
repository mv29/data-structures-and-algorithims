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
#define S            substr

void min_heapify (vector<long long int>& a, int i, int n)
{
        int left = 2*i ;                  //left child
        int right = 2*i +1; //right child
        int largest;
        if(left<= n and a[left] < a[i] )
              largest = left;
        else
             largest = i;
        if(right <= n and a[right] < a[largest] )
            largest = right;
        if(largest != i )
        {
            swap (a[i] ,a[largest]);
            min_heapify (a, largest,n);
        }
}
void bh (vector<long long int>& a,int n)
{
        for(int i = n/2 ; i >= 1 ; i-- )
        {
            min_heapify (a,i,n) ;
        }
}
int em(vector<long long int>& a)
{
        int min = a[1];
        a[1] = a[a.size()-1];
        min_heapify(a,1,a.size()-1);
        return min;
}
void dv(vector<long long int>& a, int i, int val)
{
    a[ i ] = val;
    while( i > 1 && a[ i/2 ] > a[ i ]) // swap with parent if new value is larger
    {
        swap(a[ i/2 ],a[ i ]);
        i = i/2;
    }
}
void insert_value (vector<long long int>& a, int val)
{
        a.push_back(val);
        dv (a, a.size()-1, val);
}
int main()
{
   int n,i,j,ans=0;
   cin >> n;
   vector<long long int> a(n+1,0);
   return 0;
}
