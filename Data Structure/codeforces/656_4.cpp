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
int ans, n;
string s;
void solve(int l, int r, char c, int curr) {
	if (l == r) {
		curr += s[l] != c;
		ans = min(ans, curr);
		return;
	}
	int md = (l + r) / 2;
	char nx = c;
	nx++;
	int lf = 0, rf = 0;
	for (int i = l; i <= md; i++) {
		lf += s[i] != c;
	}
	for (int i = md + 1; i <= r; i++) {
		rf += s[i] != c;
	}
	solve(md + 1, r, nx, curr + lf);
	solve(l, md, nx, curr + rf);


}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		s.clear();
		ans = INT_MAX;
		cin >> n >> s;
		solve(0, n - 1, 'a', 0);
		cout << ans << "\n";
	}
	return 0;
}