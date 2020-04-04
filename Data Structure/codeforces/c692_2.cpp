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
	int n,m;
	cin>>n>>m;
	string s,s1="",s2="";
	string mid="";
	vector<string> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<n;i++)
	{
		if(v[i]=="") continue;
		s=v[i];
		reverse(all(s));
		for(int j=0;j<n;j++)
		{
			if(i!=j&&s==v[j]&&s!="")
			{
				s1+=v[i];
				s2=s+s2;
				v[i]="";
				v[j]="";
			}

		}
	}
	string ans;
	for(int i=0;i<n;i++)
	{
		if(v[i]!="")
		{
			s=v[i];
			reverse(all(s));
			if(v[i]==s)
			{
				mid=s;
				break;
			}
		}
	}
	ans=s1+mid+s2;
	cout<<ans.size()<<endl<<ans<<endl;
	return 0;
}