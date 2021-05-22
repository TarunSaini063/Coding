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

typedef struct node{
	int val;
	struct node *left,*right;
	int height;
}node;

node* newNode(int val)
{
	node *tmp=(node*)malloc(sizeof(node));
	tmp->val=val;
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->height=1;
	return tmp;
}

int ht(node *root)
{
	if(root==NULL)return 0;
	return 1+max(ht(root->left),ht(root->right));
}

int getbal(node *root)
{
	if(root) return ht(root->left)-ht(root->right);
	return 0;
}

int getmin(node *root)
{
	int rt=root->val;
	while(root->left!=NULL)
	{
		rt=root->left->val;
		root=root->left;
	}
	return rt;
}

node* leftrot(node *root)
{
	node *tmp=root->right;
	root->right=tmp->left;
	tmp->left=root;
	return tmp;
}

node* rightrot(node *root)
{
	node *tmp=root->left;
	root->left=tmp->right;
	tmp->right=root;
	return tmp;
}

node* insert(node *root,int val)
{
	if(root==NULL)
	{
		return newNode(val);
	}
	else if(root->val>val)
	{
		root->left=insert(root->left,val);
	}
	else if(root->val<val)
	{
		root->right=insert(root->right,val);
	}
	else return NULL;
	root->height=1+max(ht(root->left),ht(root->right));
	int bal=getbal(root);
	if(bal>1&&val>root->left->val) //LR
	{
		root->left=leftrot(root->left);
		return rightrot(root);
	}
	if(bal>1&&val<root->left->val)
	{
		return rightrot(root);
	}
	if(bal<-1&&val>root->right->val)
	{
		return leftrot(root);
	}
	if(bal<-1&&val<root->right->val)
	{
		root->right=rightrot(root->right);
		return leftrot(root);
	}
	return root;
}

node* del(node* root,int val)
{
	if(root==NULL) return NULL;
	if(root->val>val)
	{
		root->left=del(root->left,val);
	}
	else if(root->val<val)
	{
		root->right=del(root->right,val);
	}
	else
	{
		if(root->left==NULL||root->right==NULL)
		{
			node *tmp=root->left?root->left:root->right;
			if(tmp==NULL)
			{
				tmp=root;
				root=NULL;
			}
			else
			{
				*root=*tmp;
			}
			free(tmp);
		}
		else
		{
			int tmp=getmin(root->right);
			root->val=tmp;
			root->right=del(root->right,tmp);
		}
	}
	if(root==NULL) return NULL;
	root->height=1+max(ht(root->left),ht(root->right));
	int bal=getbal(root);
	if(bal<-1||bal>1) cout<<"bal "<<root->val<<"\n";
	if(bal>1&&getbal(root->left)>=0)
	{
		return rightrot(root);
	}
	if(bal>1&&getbal(root->left)<0)
	{
		root->left=leftrot(root->left);
		return rightrot(root);
	}
	if(bal<-1&&getbal(root->right)<=0)
	{
		return leftrot(root);
	}
	if(bal<-1&&getbal(root->right)>0)
	{
		root->right=rightrot(root->right);
		return leftrot(root);	
	}
	return root;
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->val<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->val<<" ";
	}
}

int main(void)
{
	FIO	
	node *root=NULL;
	root = insert(root, 10); 
 	root = insert(root, 20); 
  	root = insert(root, 30); 
  	root = insert(root, 40); 
  	root = insert(root, 50); 
  	root = insert(root, 25); 
  	inorder(root);cout<<"\n";
    preorder(root);cout<<"\n";
    postorder(root);cout<<"\n";
    root=del(root,30);
    inorder(root);cout<<"\n";
    preorder(root);cout<<"\n";
    postorder(root);cout<<"\n";
	return 0;
}