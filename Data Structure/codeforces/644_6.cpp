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
int n, m;
vector<string> arr;
int  solve(int col, vector<int> changes, string &s)
{
	int x = -1;
	// cout << col << " " << s << "\n";
	for (auto i : changes)
	{
		if (i >= 2) return -1;
	}
	if (col >= m) return 1;
	// cout << s << " " << col << "\n";
	vector<int> chang;
	int y = -1;
	for (int i = 0; i < n; i++)
	{
		char c = arr[i][col];
		s += c;
		chang = changes;
		for (int j = 0; j < n; j++)
		{
			chang[j] += (c != arr[j][col]);

		}
		x = -1;
		x = solve( col + 1, chang, s);
		if (x == -1) s.pop_back();
		y = max(x, y);
		if (y == 1) return 1;
	}
	// if (y == -1) {s = "-1"; return -1;}
	return -1;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		arr.clear();
		string s = "";
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s;
			arr.pb(s);
		}
		s = "";
		vector<int> changes(n, 0);
		int y = solve(0, changes, s);
		if (y == -1) cout << -1 << "\n";
		else cout << s << '\n';
		cout.flush();
	}
	return 0;
}