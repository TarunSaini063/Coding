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

typedef struct trie
{
	struct trie* character[26];
	bool eof;
}trie;


trie* newtrie(void)
{
	trie* tp=(trie*)malloc(sizeof(trie));
	for(int i=0;i<26;i++) tp->character[i]=NULL;
	tp->eof=false;
	return tp;
}

void insert(string key,trie* root)
{
	for(int i=0;i<(int)key.size();i++)
	{
		int id=key[i]-'a';
		if(root->character[id]!=NULL) root->character[id]=newtrie();
		root=root->character[id];
	}
	root->eof=true;
}


bool search(trie *root,string key)
{
	for(int i=0;i<(int)key.size();i++)
	{
		if(root->character[key[i]-'a']==NULL) return false;
		root=root->character[key[i]-'a'];
	}
	if(root!=NULL) return root->eof;
	return false;
}

bool isempty(trie *root)
{
	for(int i=0;i<26;i++)
	{
		if(root->character[i]!=NULL) return false;
	}
	return true;
}

trie* del(trie *root,string key,int depth)
{
	if((int)key.size()==depth)
	{
		if(root->eof==true) root->eof=false;
		if(isempty(root))
		{
			free(root);
			root=NULL;
		}
		return root;
	}
	int id = key[depth] - 'a';
	root->character[id]=del(root->character[id],key,depth+1);
	if(isempty(root)&&root->eof==false)
	{
		free(root);
		root=NULL;
	}
	return root;
}


int main(void)
{
	FIO	
	 string keys[] = { "the", "a", "there", "answer", "any", "by", "bye", "their", "hero", "heroplane" }; 
    trie *root=newtrie();
    for(auto j : keys) insert(j,root);
    search(root, "the") ? cout << "Yes\n" : cout << "No\n"; 
	search(root, "these") ? cout << "Yes\n" : cout << "No\n"; 
	del(root, "heroplane",0); 
	search(root, "hero") ? cout << "Yes\n" : cout << "No\n"; 
	return 0;
}