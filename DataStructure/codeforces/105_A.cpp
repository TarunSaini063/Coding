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

string s;
bool solve(int a,int b,int c){
	int sum=0;
	for(char C : s){
		if(C=='A') sum+=a;
		else if(C=='B') sum+=b;
		else sum+=c;
		if(sum<0) return false;
	}
	return sum==0;
}

int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		if(solve(1,1,-1)||solve(-1,-1,1)||solve(1,-1,-1)||solve(-1,1,1)||solve(1,-1,1)||solve(-1,1,-1)){
			cout<<"Yes\n";
		}
		else cout<<"No\n";
	}
	return 0;
}
