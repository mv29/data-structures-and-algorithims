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

struct node
{
    ll key;
    node * left;
    node * right;
};
node* FindMin(node *node)
{
    if(node==NULL)
    {
        /* There is no element in the tree */
        return NULL;
    }
    if(node->left) /* Go to the left sub tree to find the min element */
        return FindMin(node->left);
    else
        return node;
}
node* FindMax(node *node)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(node->right) /* Go to the right sub tree to find the max element */
    return(FindMax(node->right));
    else
    return node;
}
node* isert(node *a,ll value)
{
    if(a==NULL)
    {
        node *temp;
        temp=new node;
        temp -> key = value;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(value >(a->key))
    {
        a->right = isert(a->right,value);
    }
    else if(value <= (a->key))
    {
        a->left = isert(a->left,value);
    }
    return a;
}

node* Delet(node* a, ll data ,node* help)
{
    //clear(temp);
    if(a==NULL)
    return NULL ;
    else if(data < a->key)
    {
        a->left = Delet(a->left, data,help);
    }
    else if(data > a->key)
    {
        a->right = Delet(a->right, data,help);
    }
    else
    {
        /* Now We can delete this node and replace with either minimum element
        in the right sub tree or maximum element in the left subtree */
        if(a->right && a->left)
        {
            /* Here we will replace with minimum element in the right sub tree */
             help = FindMin(a->right);
             a->key = help->key;
            /* As we replaced it with some other node, we have to delete that node */
            a-> right = Delet(a->right,help->key,help);
        }
        else
        {
            /* If there is only one or zero children then we can directly
            remove it from the tree and connect its parent to its child */
             help = a;
            if(a->left == NULL)
            a = a->right;
            else if(a->right == NULL)
            a = a->left;
            //free(temp); /* temp is longer required */
        }
    }
    return a;
}
void inorder(node *a)
{
    if(a==NULL)
    return;
    inorder(a->left);
    cout<< a->key<<" ";
    inorder(a->right);
}
void postorder(node *a)
{
    if(a==NULL)
    return;
    postorder(a->left);
    postorder(a->right);
    cout<< a->key<<" ";
}
void preorder(node *a)
{
    if(a==NULL)
    return;
    cout<< a->key<<" ";
    preorder(a->left);
    preorder(a->right);
}
ll depth(node* node)
{
        if (node==NULL)
            return 0;
        else
        {
             /* compute the depth of each subtree */
              int ldepth = depth(node->left);
              int rdepth = depth(node->right);

              /* use the larger one */
              if (ldepth > rdepth)
                    return(ldepth+1);
              else
                   return(rdepth+1);
       }
}
node* search(node* root, ll key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       {
           flag=1;
           return root;
       }
    // Key is greater than root's key
    if (root->key < key)
       {
            return search(root->right, key);
       }
    // Key is smaller than root's key
    if (root->key > key)
       {
            return search(root->left, key);
       }
}
int main()
{
    ios_base::sync_with_stdio(false);
    node* root =NULL;
    root=isert(root,50);
    isert(root, 30);
    node * k=search(root,30);
    cout << k->key << "\n";
    return 0;
}
