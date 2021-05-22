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
int h,w,a,b;
int used[16][16];
int solve(int r,int c,int A,int B){
	if(A<0||B<0)return 0;

	if(c>=w){
		c=0;
		r++;
	}
	if(r==h) return 1;

	if(used[r][c]) return solve(r,c+1,A,B);

	used[r][c] = 1;

	int ans = solve(r,c+1,A,B-1);

	if(c+1<w&&!used[r][c+1]){
		used[r][c+1] = 1;
		ans += solve(r,c+2,A-1,B);
		used[r][c+1] = 0;
	}
	if(r+1<h&&!used[r+1][c]){
		used[r+1][c] = 1;
		ans += solve(r,c+1,A-1,B);
		used[r+1][c] = 0;
	}
	used[r][c]=0;
	return ans;
}
int main(void)
{
	FIO	
	cin>>h>>w>>a>>b;
	cout<<solve(0,0,a,b)<<"\n";
	return 0;
}