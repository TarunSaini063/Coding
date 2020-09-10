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
		string s, t;
		cin >> s >> t;
		int n = sz(s), fl = 0;
		set<char> st;
		for (char c : s) st.insert(c);
		for (char c : t) {
			if (st.count(c) == 0) {
				fl = 1;
				break;
			}
		}
		if (fl) {
			cout << "-1\n";
			continue;
		}
		vector<vector<int>> nxt(26, vector<int>(n + 1, 1e6));
		for (int c = 0; c < 26; c++) {
			int j = 0, nt = 1e6;
			for (int i = j; i < n; i++) {
				if (s[i] == 'a' + c) {
					nt = i;
					for (int k = j; k <= i; k++) nxt[c][k] = i;
					j = i + 1;
				}
			}
		}
		// for (char c : {'t', 'y'}) {
		// 	for (int i = 0; i < n; i++) cout << nxt[c - 'a'][i] << " ";
		// 	cout << "\n";
		// }
		int ans = 1, ends = 0, endt = 0;
		int last = 0, k = 0, lstcheck = 0;
		for (int i = 0; i < sz(t); i++) {
			int nt = nxt[t[i] - 'a'][lstcheck];
			if (nt == 1e6 || nt < lstcheck) {
				ans++;
				i--;
				lstcheck = 0;
			}
			else lstcheck = nt + 1;
			// cout << "nt= " << nt << " " << lstcheck << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}