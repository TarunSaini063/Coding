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
	while(t--){
		int a,b,cnt=0,b1=0;
		cin >> a >> b;
		if(a>b) {
			cout << "NO\n";
			continue;
		}
		for(int j=0;j<30;j++) {
			cnt+=((a & (1 << j))>0);
			cnt-=((b & (1 << j))>0);
			b1+=(cnt<0);
		}
		if(b1) cout << "NO\n";
		else cout << "YES\n";
	}
	
	return 0;
}