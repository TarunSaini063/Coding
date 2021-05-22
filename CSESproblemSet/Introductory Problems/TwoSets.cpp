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
		int n;
		cin >> n;
		ll sm = n * (n + 1);
		if (sm % 4 == 0) {
			cout << "YES\n";
			vector<int> s1, s2;
			if (n % 2 == 0) {
				int x = n / 4, i;
				for (i = 1; i <= x; i++) s1.pb(i);
				for (i = x + 1; i <= n - x; i++) s2.pb(i);
				for (; i <= n; i++) s1.pb(i);
			}
			else {
				int i = 0;
				s1.pb(++i);
				s1.pb(++i);
				s2.pb(++i);
				int x = (n - i) / 4, tp = x;
				while (x--) s1.pb(++i);
				int y = (n - i) - tp;
				while (y--) s2.pb(++i);
				while (i < n) s1.pb(++i);
			}
			cout << sz(s1) << "\n";
			for (auto i : s1) cout << i << " ";
			cout << "\n";
			cout << sz(s2) << '\n';
			for (auto i : s2) cout << i << " ";
		}
		else cout << "NO\n";
	}
	return 0;
}