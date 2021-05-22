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
	int t = 1;
	while (t--)
	{
		int n, a, b;
		cin >> n;
		vector<ar<int, 3>> v(n);
		vector<int>ans(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> v[i][1] >> v[i][0];
			v[i][2] = i + 1;
		}
		sort(all(v));
		set<ar<int, 2>> s;
		for (int i = 0; i < n; i++) {
			auto it = s.lower_bound({v[i][1]});
			if (it != s.begin()) {
				it--;
				ans[v[i][2]] = (*it)[1];
				s.erase(it);
			}
			else {
				ans[v[i][2]] = sz(s) + 1;
			}
			s.insert({v[i][0], ans[v[i][2]]});
		}
		cout << s.size() << "\n";
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	}
	return 0;
}