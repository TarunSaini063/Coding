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
	int t = 1;
	// cin>>t;
	while (t--)
	{
		int x, y, a, b, c;
		cin >> x >> y >> a >> b >> c;
		int red[a], green[b], cless[c];
		for (auto &i : red) cin >> i;
		for (auto &i : green) cin >> i;
		for (auto &i : cless) cin >> i;
		sort(red, red + a, greater<int>());
		sort(green, green + b, greater<int>());
		vector<int> fin;
		for (int i = 0; i < x; i++) fin.pb(red[i]);
		for (int i = 0; i < y; i++) fin.pb(green[i]);
		for (auto i : cless) fin.pb(i);
		sort(all(fin), greater<int>());
		ll sm = 0, req = x + y;
		for (auto i : fin) {
			sm += i;
			req--;
			if (!req) break;
		}
		cout << sm << "\n";
	}
	return 0;
}