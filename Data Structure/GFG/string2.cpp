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
vector<string> arr;
void permute(string s,int id)
{
	if(id==(int)s.size()) arr.pb(s);
	for(int i=id;i<(int)s.size();i++)
	{
		swap(s[i],s[id]);
		permute(s,id+1);
		swap(s[i],s[id]);
	}
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
		permute(s,0);
		sort(all(arr));
		for(auto j : arr) cout<<j<<" ";
		arr.clear();
	}
	return 0;
}