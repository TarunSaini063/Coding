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
	int q, x;
	cin >> q >> x;
	vector<int> mods(x,0);
	
	set<pair<int, int>> vals;
	for (int i = 0; i < x; ++i) {
		vals.insert(make_pair(mods[i], i));
	}
	
	for (int i = 0; i < q; ++i) {
		int cur;
		cin >> cur;
		cur %= x;
		vals.erase(make_pair(mods[cur], cur));
		++mods[cur];
		vals.insert(make_pair(mods[cur], cur));
		cout << vals.begin()->first <<" "<<vals.begin()->second << endl;
	}
	
	return 0;

	return 0;
}