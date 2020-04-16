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
		string s;
		cin>>s;
		int arr[26];
		for(int i=0;i<26;i++) arr[i]=-1;
		int ans=0,curr=0;
		for(int i=0;i<(int)s.size();i++)
		{
			if(arr[s[i]-'a']==-1)
			{
				arr[s[i]-'a']=i;
				curr++;
				ans=max(ans,curr);
			}
			else
			{
				int tp=arr[s[i]-'a'];
				for(int i=0;i<26;i++)
				{
					if(arr[i]!=-1&&arr[i]<=tp)
					{
						arr[i]=-1;
						curr--;
					}
				}
				arr[s[i]-'a']=i;
				curr++;
			}
			// cout<<curr<<" ";
		}
		cout<<ans<<"\n";
	}
	return 0;
}