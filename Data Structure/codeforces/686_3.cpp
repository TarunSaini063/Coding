#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
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
		int n;
		cin >> n;
		unordered_map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x].pb(i + 1);
		}
		if (sz(mp) == 1) {
			cout << "0\n";
			continue;
		}
		int ans = INT_MAX;
		for (auto i : mp) {
			int cnt = 0;
			int n1 = sz(i.ss);
			if (n1 == 1) {
				if (i.ss[0] == 1 || i.ss[0] == n) cnt = 1;
				else cnt = 2;
				ans = min(ans, cnt);
				continue;
			}
			for (int j = 0; j < n1 - 1; j++) {
				if (j == 0 && i.ss[j] != 1) cnt = 1;
				if (i.ss[j] + 1 != i.ss[j + 1]) {
					cnt++;
				}
			}
			if (i.ss[n1 - 1] != n) cnt++;
			ans = min(ans, cnt);
		}
		cout << ans << "\n";
	}
	return 0;
}