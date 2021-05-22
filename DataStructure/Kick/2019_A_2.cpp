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
const int mxn = 250;
int val[mxn][mxn];
string s[mxn];
int r, c;
void dfs(int i, int j, int v)
{
	if (i < 0 || i >= r || j < 0 || j >= c || (val[i][j] != -1 && val[i][j] < v)) return;
	val[i][j] = v;
	dfs(i + 1, j, v + 1);
	dfs(i, j + 1, v + 1);
	dfs(i - 1, j, v + 1);
	dfs(i, j - 1, v + 1);

}
void solve(void)
{
	cin >> r >> c;
	// memset(val, -1, r * c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) val[i][j] = 1000;
	}
	for (int i = 0; i < r; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (s[i][j] == '1')
			{
				dfs(i, j, 0);
			}
		}
	}
	int x = 0, y = 0, ans = 0, mx = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			// cout << val[i][j] << " ";
			if (val[i][j] > mx)
			{
				mx = val[i][j];
				x = i, y = j;
			}
		}
		// cout << "\n";
	}
	dfs(x, y, 0);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) ans = max(ans, val[i][j]);
	}
	cout << ans << "\n";

}
int main(void)
{
	FIO
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}