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
vector<vector<char>> arr;
vector<vector<bool>> visited;
int ans=0;
bool valid(int h,int w,int i,int j)
{
	if(i<h&&j<w&&i>=0&&j>=0&&arr[i][j]!='#') return true;
	return false;
}
void fun(int i,int j,int h,int w)
{
	if(visited[i][j]) return;
	visited[i][j]=true;
	if(arr[i][j]=='*') ans++;
	if(valid(h,w,i+1,j)) fun(i+1,j,h,w);
	if(valid(h,w,i-1,j)) fun(i-1,j,h,w);
	if(valid(h,w,i,j+1)) fun(i,j+1,h,w);
	if(valid(h,w,i,j-1)) fun(i,j-1,h,w);
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		int w,h;
		cin>>w>>h;
		arr=vector<vector<char>> (h);
		visited=vector<vector<bool>> (h);
		for(int i=0;i<h;i++)
		{
			arr[i]=vector<char> (w);
			visited[i]=vector<bool> (w,false);
			for(int j=0;j<w;j++) cin>>arr[i][j];
		}
		fun(0,0,h,w);
		cout<<ans<<endl;
	}
	return 0;
}