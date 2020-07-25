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
string s, t;
int ans, fl;
vector<vector<int>> freq;
void dfs(int i) {
	if (sz(freq[i]) == 0 || fl) return;
	ans++;
	char mn = 't';
	for (auto i1 : freq[i]) {
		mn = min(mn, t[i1]);
	}
	if (mn - 'a' < i) {fl = 1; return;}
	for (auto i1 : freq[i]) {
		if (t[i1] != mn)
			freq[mn - 'a'].pb(i1);
		else s[i1] = mn;
	}
	freq[i].clear();
	// dfs(mn - 'a');
}
int main(void)
{
	FIO
	int t1;
	cin >> t1;
	while (t1--)
	{
		int n;
		cin >> n;
		ans = 0, fl = 0;
		cin >> s >> t;
		freq.assign(20, vector<int>());
		for (int i = 0; i < n && fl == 0; i++) {
			if (s[i] > t[i]) fl = 1;
			if (s[i] != t[i]) {
				freq[s[i] - 'a'].pb(i);
			}
		}

		for (int i = 0; i < 20 && fl == 0; i++) {
			dfs(i);
		}
		if (fl) {
			cout << "-1\n";
		}
		else cout << ans << "\n";
	}
	return 0;
}