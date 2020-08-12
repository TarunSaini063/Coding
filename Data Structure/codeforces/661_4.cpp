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
		int n;
		cin >> n;
		int ans[n];
		set<int> one, ze;
		string s;
		cin >> s;
		if (s[0] == '0') ze.insert(1);
		else one.insert(1);
		ans[0] = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] == '0') {
				if (!one.empty()) {
					ans[i] = *(one.begin());
					one.erase(ans[i]);
					ze.insert(ans[i]);
				}
				else {
					ans[i] = (*ze.rbegin()) + 1;
					ze.insert(ans[i]);
				}
			}
			else {
				if (!ze.empty()) {
					ans[i] = *(ze.begin());
					one.insert(ans[i]);
					ze.erase(ans[i]);
				}
				else {
					ans[i] = (*one.rbegin()) + 1;
					one.insert(ans[i]);
				}
			}
		}
		int mx = *max_element(ans, ans + n);
		cout << mx << '\n';
		for (int i : ans) cout << i << ' ';
		cout << '\n';

	}
	return 0;
}