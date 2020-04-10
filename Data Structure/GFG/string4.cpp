//					SEGMENTATION ERROR
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
void solve(string &s,int i,int len,int j)
{
	if((int)s.size()<=1)return;
	if(j==(int)s.size())
	{
		if(len!=0)
		s.erase(i,len+1);
		return;
	}
	if(j>(int)s.size()) return;
	// cout<<s[i]<<" "<<len<<" "<<j<<"\n";
	if(s[i]==s[j])
	{
		solve(s,i,len+1,j+1);
	}
	else
	{
		if(len!=0)
		s.erase(i,len+1);
		if(i==0&&len!=0)solve(s,i,0,i+1);
		else solve(s,i+1-len,0,i+2-len);
	}
}
bool check(string s)
{
	for(int i=0;i<(int)s.size()-1;i++)
	{
		if(s[i]==s[i+1]) return true;
	}
	return false;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		while(check(s)){
		solve(s,0,0,1);}
		cout<<s<<"\n";
	}
	return 0;
}