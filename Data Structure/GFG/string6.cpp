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
int main(void)
{
	FIO	
	int t;
	unordered_map<char,int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
	cin>>t;
	while(t--)
	{
		string s;
		int ans=0;
		cin>>s;
		for(int i=0;i<(int)s.size();i++)
		{
			if(m[s[i]]<m[s[i+1]])
			{
				ans+=m[s[i+1]]-m[s[i]];
				i++;
			}
			else ans+=m[s[i]];
		}
		cout<<ans<<"\n";
	}
	return 0;
}