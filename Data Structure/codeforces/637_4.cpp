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
int dp[2005][2005][11];
int change[2005][10];
int n,k;
string res="";
int filldp(int id,int sum,int d)
{
	if (id == n)
	{
    	if (sum == 0)  return dp[id][sum][d] = 1;
        return dp[id][sum][d] = 0;
    }
	if(dp[id][sum][d]!=-1) return dp[id][sum][d];
	int mx=0;
	for(int i=9;i>=0;i--)
	{
		if(change[id][i]!=-1&&change[id][i]<=sum)
		{
			mx=max(mx,filldp(id+1,sum-change[id][i],i));
		}
	}
	return dp[id][sum][d]=mx;
}
void ans(int id,int sum)
{
	if(id==n) return;
	for(int i=9;i>=0;i--)
	{
		if(change[id][i]!=-1&&change[id][i]<=sum && dp[id+1][sum-change[id][i]][i]==1)
		{
			res+=to_string(i);
			ans(id+1,sum-change[id][i]);
			return;
		}
	}
}
int main(void)
{
	FIO	
	cin>>n>>k;
	vector<string> arr(n);
	for(auto &j: arr) cin>>j;
	memset(dp,-1,sizeof(dp));
	string s[10]={ "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
	for(int i=0;i<n;i++)
	{
		for(int j=9;j>=0;j--)
		{
			change[i][j]=0;
			for(int k=0;k<=6;k++)
			{
				if(arr[i][k]=='1'&&s[j][k]=='0')
				{
					change[i][j]=-1;
					break;
				}
				else if(arr[i][k]=='0'&&s[j][k]=='1') change[i][j]++;
			}		
		}
	}
	filldp(0,k,0);
	ans(0,k);
	if(res.size()==0) cout<<"-1"<<"\n";
	else cout<<res<<"\n";
	return 0;
}