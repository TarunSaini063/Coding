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
		vector<vector<int>> arr(9,vector<int> (9));
		int ch[]={0,3,6},x=-1;
		string s;
		for(int i=0;i<9;i++)
		{
			cin>>s;
			for(int j=0;j<9;j++) arr[i][j]=s[j]-'0';
			// cout<<s<<"\n";
		}
		for(int i=0;i<9;i++)
		{
			if(i%3==0) x++;
			int p=arr[i][ch[i%3]+x];
			// cout<<i<<" "<<ch[i%3]+x<<"\n";
			if(p<9) p++;
			else if(p==9) p--;
			arr[i][ch[i%3]+x]=p;
		}
		cout<<"\n";
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++) cout<<arr[i][j];
			cout<<"\n";
		}
	}
	return 0;
}