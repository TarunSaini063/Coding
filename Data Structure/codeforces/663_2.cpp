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
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		for (auto &i : s)cin >> i;
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			ans += s[i][m - 1] == 'R';
		}
		for (int i = 0; i < m - 1; i++) {
			ans += s[n - 1][i] == 'D';
		}
		cout << ans << "\n";
	}
	return 0;
}