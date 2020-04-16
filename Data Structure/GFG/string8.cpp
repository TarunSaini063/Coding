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
	cin.ignore();
	while(t--)
	{
		string s;
		getline(cin,s);
		vector<int> arr(256,0);
		int n=s.size();
		for(int i=0;i<n;i++) arr[int(s[i])]++;
		string s1="";
		for(int i=n-1;i>=0;i--)
		{
			if(arr[int(s[i])]>0)
			{
				s1=s[i]+s1;
				arr[int(s[i])]=0;
			}
		}
		cout<<s1<<"\n";
	}
	return 0;
}