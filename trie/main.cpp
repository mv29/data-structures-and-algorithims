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
struct tnode
{
   // char data;
    struct tnode* a[26];
    bool last;
};
struct tnode* create()
{
    struct tnode* temp = (struct tnode *)malloc(sizeof(struct tnode));
    temp->last=false; // making the last element flag to false
    int i;
    FOR(i,26) // initializing all the pointers to null
    temp->a[i]=NULL;
    return temp;
};
void insert(struct tnode* root,string s)
{
    struct tnode* temp=root;
    int n=sz(s),i,x;
    FOR(i,n) // here i tells the level
    {
       // cout << s[i] << "\n";
        x=s[i]-'a';
        if(temp->a[x]==NULL)
        {
           temp->a[x]=create();
        }
        temp=temp->a[x];
    }
    temp->last=true;
}

bool srch(struct tnode* root, string s)
{
    struct tnode* temp=root;
    int n=sz(s),i,x;
    FOR(i,n)
    {
        cout << s[i] << "\n";
        x=s[i]-'a';
        if(temp->a[x]==NULL)
        {
           return false;
        }
        temp=temp->a[x];
    }
    return (temp!=NULL && temp->last);
}
int presrch(struct tnode* root, string s)
{
    struct tnode* temp=root;
    int n=sz(s),i,x;
    FOR(i,n)
    {
        x=s[i]-'a';
        if(temp->a[x]==NULL)
        {
           return -1;
        }
        temp=temp->a[x];
        if(i==n-1)
        return temp->w;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    struct tnode* root= create();
    int i,j,x,y,k;
    cin >> x >> y;
    string s;
    FOR(i,x)
    {
        cin >> s ;
        insert(root,s);
    }
    cout << "boob\n";
    FOR(i,y)
    {
        cin >> s;
        if(srch(root,s))
        cout << "yes\n";
        else
        cout << "no\n";
    }
   /* FOR(i,26)
    root->a[i]=NULL;
    insert(root,a);
    */return 0;
}
