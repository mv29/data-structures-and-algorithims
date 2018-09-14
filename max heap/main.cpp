
#include <bits/stdc++.h>
using namespace std;
void max_heapify (vector<long long int>& a, int i, int n)
{
        int left = 2*i ;                  //left child
        int right = 2*i +1; //right child
        int largest;
        if(left<= n and a[left] > a[i] )
              largest = left;
        else
             largest = i;
        if(right <= n and a[right] > a[largest] )
            largest = right;
        if(largest != i )
        {
            swap (a[i] ,a[largest]);
            max_heapify (a, largest,n);
        }
}
void build_maxheap (vector<long long int>& a,int n)
{
        for(int i = n/2 ; i >= 1 ; i-- )
        {
            max_heapify (a,i,n) ;
        }
}
int maximum(vector<long long int>& a)
{
  return a[ 1 ];  //as the maximum element is the root element in the max heap.
}
int extract_maximum (vector<long long int>& a)
{
        int max = a[1];
        a[1] = a[a.size()-1];
        max_heapify(a,1,a.size()-1);
        return max;
}
void increase_value (vector<long long int>& a, int i, int val)
{
    a[ i ] = val;
    while( i > 1 && a[ i/2 ] < a[ i ])
    {
        swap(a[ i/2 ],a[ i ]);
        i = i/2;
    }
}
void insert_value (vector<long long int>& a, int val)
{
        a.push_back(val);
        increase_value (a, a.size()-1, val);
}
int main()
{
   int n,i,j,ans=0;
   cin >> n;
   vector<long long int> a(n+1,0);
   for(i=1;i<n+1;i++)
   scanf("%d",&a[i]);
   build_maxheap (a,n);
  int q;
   cin >> q;
   while(q--)
   {
       long long int x,y;
       scanf("%d",&x);
       if(x==1)
       {
       scanf("%d",&y);
       insert_value (a, y);
       }
       else
       {
           cout << maximum(a) << " \n";
       }
   }
    return 0;
}
