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

int augment(node *root,map<int,int> &mp)
{
	if(root==NULL) return 0;
	if(root->left==NULL&&root->right==NULL)
	{
		return mp[root->key]=1;
	}
	mp[root->key]=1+augment(root->left,mp)+augment(root->right,mp);
	return mp[root->key];
}

int find(node *root,int k,map<int,int> mp)
{
	if(root==NULL||mp[root->key]<k) return -1;
	int id=root->left==NULL?1:mp[root->left->key]+1;
	if(id==k) return root->key;
	if(id>k) return find(root->left,k,mp);
	return find(root->right,k-id,mp);
}
int main(void)
{
	FIO	
	node *root=NULL;
	root=insert(50,root);insert(30, root);insert(20, root);//                 50
    insert(40, root);insert(60, root);  insert(70, root); //				/	 \
    cout<<"Enter kth element ";int k;					 //				   30	  60
    cin>>k;												//				   /  \     \
    map<int,int> mp;									//				 20   40     70
	augment(root,mp);									//
    cout<<"\n"<<find(root,k,mp);
	return 0;
}