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
string path;
int vis[7][7], X[] = {1, -1, 0, 0}, Y[] = {0, 0, 1, -1}, ans = 0;
char turn[] = {'D', 'U', 'R', 'L'};
bool valid(int nx, int ny) {
	if (nx >= 0 && nx < 7 && ny >= 0 && ny < 7 && vis[nx][ny] == 0) return true;
	return false;
}
void solve(int x, int y, int  n) {
	if (x == 6 && y == 0) {
		if (n == 48)ans++;
		return;
	}
	vis[x][y] = 1;
	if (path[n] == '?' || path[n] == 'D') {
		if (x < 6 && valid(x + 1, y)) {
			if (!(!valid(x + 2, y) && valid(x + 1, y - 1) && valid(x + 1, y + 1)))
				solve(x + 1, y, n + 1);
		}
	}
	if (path[n] == '?' || path[n] == 'U') {
		if (x > 0 && valid(x - 1, y)) {
			if (!(!valid(x - 2, y) && valid(x - 1, y - 1) && valid(x - 1, y + 1)))
				solve(x - 1, y, n + 1);
		}
	}
	if (path[n] == '?' || path[n] == 'L') {
		if (y > 0 && valid(x, y - 1)) {
			if (!(!valid(x, y - 2) && valid(x + 1, y - 1) && valid(x - 1, y - 1)))
				solve(x , y - 1, n + 1);
		}
	}
	if (path[n] == '?' || path[n] == 'R') {
		if (y < 6 && valid(x, y + 1)) {
			if (!(!valid(x, y + 2) && valid(x + 1, y + 1) && valid(x - 1, y + 1)))
				solve(x , y + 1, n + 1);
		}
	}
	vis[x][y] = 0;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> path;
		string s = "";
		memset(vis, 0, sizeof(vis));
		solve(0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}