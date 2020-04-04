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
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a>>b>>c;
		int fl=0;
		for(int i=0;i<(int)a.size();i++)
		{
			if(a[i]==b[i])
			{
				if(a[i]!=c[i]){
				fl=1;
				break;}
				else continue;
			}
			else if(a[i]!=b[i]&&(a[i]==c[i]||b[i]==c[i])) continue;
			else { fl=1; break;}
		}
		if(fl) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}