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
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
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
		cout<<root->key<<" ";
	}
}

 void itr_postorder(node *A)
 {
     if(A==NULL) return;
     stack<node*> st;
    while(true)
    {
        while(A!=NULL)
        {
            st.push(A);
            st.push(A);
            A=A->left;
        }
        if(st.empty()) return;
        A=st.top();
        st.pop();
        if(!st.empty()&&st.top()==A) A=A->right;
        else
        {
            cout<<A->key<<" ";
            A=NULL;
        }
    }
 }
node* insert(int val,node *root)
{
	if(root==NULL) return newNode(val);
	if(root->key>val) root->left=insert(val,root->left);
	else if(root->key<val) root->right=insert(val,root->right);
	return root;
}
node* del(node *root,int val)
{
	if(root==NULL) return root;
	if(root->key>val){root->left=del(root->left,val);return root;}
	if(root->key<val) {root->right=del(root->right,val);return root;}
	if(root->left==NULL)
	{
		node* tmp=root->right;
		free(root);
		return tmp;
	} 
	if(root->right==NULL)
	{
		node* tmp=root->left;
		free(root);
		return tmp;
	}
	node *pr=root;
	node *succ=root->right;
	while(succ->left!=NULL)
	{
		pr=succ;
		succ=succ->left;
	}
	if(pr==root) pr->right=succ->right;
	else pr->left=succ->right;
	root->key=succ->key;
	free(succ);
	return root;
}
int main(void)
{
	FIO	
	node *root=NULL;
	root=insert(50,root);insert(30, root);insert(20, root);
    insert(40, root);insert(60, root);  insert(10, root); 
    inorder(root);cout<<"\n";
    preorder(root);cout<<"\n";
    postorder(root);cout<<"\n";
    del(root,20);
    inorder(root);cout<<"\n";
    preorder(root);cout<<"\n";
    itr_postorder(root);cout<<"\n";
	return 0;
}