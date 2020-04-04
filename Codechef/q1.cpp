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
int check(string s,int k,char c)
{
	if(k==s.size()-1&&s[k-1]==c) return -1;
	else if(k==0&&s.size()>1&&s[1]==c) return 1;
	return 0;

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
		string ans="";
		vector<int> arr(26,0);
		int x=0,len=-1;
		for(int i=0;i<s.size();i++)
		{
			if(arr[s[i]-'a']==0)
			{
				if(ans.size()==0) ans+=s[i],len++;
				else 
				{
					int p=check(ans,len,s[i]);
					if(p==0&&len!=ans.size()) //break
				}
			}
		}
	}
	return 0;
}