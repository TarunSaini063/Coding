#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
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
		string s;
		cin >> s;
		sort(all(s), greater<char>());
		int freq[26] = {0};
		for (auto i : s) freq[i - 'a']++;
		int m;
		cin >> m;
		int arr[m];
		for (auto &i : arr) {
			cin >> i;
		}
		vector<char> ans(m, '.');
		char c = 'z';
		while (true)
		{
			vector<int> zeros;
			for (int i = 0; i < m; i++)
			{
				if (arr[i] == 0) {
					zeros.pb(i);
					arr[i] = -1;
				}
			}
			if ((int)zeros.size() == 0) break;
			while (c >= 'a' && freq[c - 'a'] < (int)zeros.size()) c--;
			for (auto i : zeros)
			{
				ans[i] = c;
			}
			for (int i = 0; i < m; i++)
			{
				for (auto j : zeros)
				{
					arr[i] -= abs(i - j);
				}
			}
			c--;
		}
		for (auto i : ans) cout << i;
		cout << '\n';
	}
	return 0;
}