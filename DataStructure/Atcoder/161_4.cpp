#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
vector<ll> ans;
void dfs(ll num, int dig) {
	if (dig > 10) return;
	int back = num % 10;
	ans.pb(num);
	for (auto i : { -1, 0, 1}) {
		int tmp = back + i;
		if (tmp < 0 || tmp > 9) continue;
		dfs(num * 10 + tmp, dig + 1);
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		for (int i = 1; i <= 9; i++) dfs(i, 1);
		sort(all(ans));
		cout << ans[k - 1] << "\n";
	}
	return 0;
}