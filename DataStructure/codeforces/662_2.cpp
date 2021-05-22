#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int mxn = 1e5 + 1;
int main(void)
{
	FIO
	int t = 1;
	while (t--)
	{
		map<int, int>mp;
		int n, x, q;
		cin >> n;
		int freq[mxn];
		memset(freq, 0, sizeof(freq));
		for (int i = 0; i < n; i++) {
			cin >> x;
			freq[x]++;
		}
		for (int i = 0; i < mxn; i++) {
			if (freq[i] != 0)
				mp[freq[i]]++;
		}
		cin >> q;
		while (q--) {
			int sq = 0, tot = 0;
			char c;
			cin >> c >> x;
			if (mp.find(freq[x]) != mp.end()) {
				mp[freq[x]]--;
				if (mp[freq[x]] == 0) mp.erase(freq[x]);
			}
			if (c == '+')freq[x]++;
			else freq[x]--;
			mp[freq[x]]++;
			auto it = mp.lower_bound(2), j = mp.end();
			while (it != j) {
				int s = it->ss;
				// cout << it->ff << " sz= " << s << '\n';
				if (sq == 0 && it-> ff >= 4) sq = 1, tot += (it->ff / 2) * (s - 1) + (it->ff - 4) / 2;
				else tot += (it->ff / 2) * s;
				if (sq == 1 && tot >= 2) break;
				it++;
			}
			// cout << sq << " " << tot << '\n';
			if (sq == 1 && tot >= 2) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}