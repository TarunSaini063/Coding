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
int n;
vector <int> a;
int solve(vector <int> &c, int bit) {
	if (bit < 0) return 0;
	vector <int> l, r;
	for (auto &i : c) {
		if (((i >> bit) & 1) == 0) l.push_back(i);
		else r.push_back(i);
	}
	if (l.size() == 0) return solve(r, bit - 1);
	if (r.size() == 0) return solve(l, bit - 1);
	return min(solve(l, bit - 1), solve(r, bit - 1)) + (1 << bit);
}
int main(void) {
	FIO
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	cout << solve(a, 30) << endl;
	return 0;
}