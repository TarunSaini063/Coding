#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
typedef struct node
{
	int key;
	struct node *left,*right;
} node;
node* newNode(int val)
{
	node *tmp=(node*)malloc(sizeof(struct node));
	tmp->key=val;
	tmp->left=tmp->right=NULL;
	return tmp;
}

node* insert(int val,node *root)
{
	if(root==NULL) return newNode(val);
	if(root->key>val) root->left=insert(val,root->left);
	else if(root->key<val) root->right=insert(val,root->right);
	return root;
}

void inorder(vector<int> &v,node *root)
{
	node *gd;
	while(root!=NULL)
	{
		if(root->left!=NULL)
		{
			gd=root->left;
			while(gd->right!=NULL&&gd->right!=root)
			{
				gd=gd->right;
			}
			if(gd->right==NULL)
			{
				gd->right=root;
				root=root->left;
			}
			else
			{
				v.pb(root->key);
				gd->right=NULL;
				root=root->right;
			}
			
		}else
		{
			v.pb(root->key);
			root=root->right;
		}
	}
}


int main(void)
{
	FIO	
	node *root=NULL;
	root=insert(50,root);insert(30, root);insert(20, root);//                 50
    insert(40, root);insert(60, root);  insert(70, root); //				/	 \																;
    													 //				   30	  60
    													//				  /  \     \																						;
    													//				 20   40    70
    vector<int> v;
    inorder(v,root);
    for(auto j: v) cout<<j<<" ";
	return 0;
}