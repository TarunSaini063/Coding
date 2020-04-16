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
		string s1,s2;
		cin>>s1>>s2;
		int ans=1;
		int n1=s1.size();
		int n2=s2.size();
		if(n1==n2)
		{
		   
			for(int i=0;i<n1;i++)
			{
				if(s2[i]!=s1[(i+2)%n1])
				{
					ans=0;
					break;
				}
			}
			if(ans==0){
    			ans=1;
    			for(int i=0;i<n1;i++)
    			{
    				if(s1[i]!=s2[(i+2)%n1])
    				{
    					ans=0;
    					break;
    				}
    			}
			}
		}else ans=0;
		cout<<ans<<"\n";
	}
	return 0;
}