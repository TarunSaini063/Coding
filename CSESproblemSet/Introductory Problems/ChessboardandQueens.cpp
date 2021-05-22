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
vector<string> arr(8);
int ans = 0;
bool safe(int row, int col) {
	for (int i = col - 1; i >= 0; i--) {
		if (arr[row][i] == '1') return false;
	}
	int c = col, r = row;
	while (true) {
		c--;
		r--;
		if (c < 0 || r < 0) break;
		if (arr[r][c] == '1') return false;
	}
	c = col, r = row;
	while (true) {
		c--;
		r++;
		if (c < 0 || r > 7) break;
		if (arr[r][c] == '1') return false;
	}
	return true;
}
bool solve(int col, int left) {
	if (left == 0 && col == 8) {
		ans++;
		return true;
	}
	if (col == 8) return false;
	for (int i = 0; i < 8; i++) {
		if (safe(i, col) && arr[i][col] != '*') {
			char tmp = arr[i][col];
			arr[i][col] = '1';
			solve(col + 1, left - 1);
			arr[i][col] = tmp;
		}
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		for (auto &i : arr) cin >> i;
		solve(0, 8);
		cout << ans << "\n";
	}
	return 0;
}