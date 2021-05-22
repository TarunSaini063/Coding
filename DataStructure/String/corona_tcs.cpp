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
vector<string> arr(9);
vector<pair<int, int>> dir, ans;
int row = 9, col = 20, cnt = 0;
void get(int &x, int &y, int &mov) {
	int nx = x + dir[mov].ff;
	int ny = y + dir[mov].ss;
	if (x >= 0 && x < 20 && y >= 0 && y <= 9 ) {
		x = nx;
		y = ny;
		return;
	}
	cnt++;
	if (nx == 19) {
		nx--;
		if (mov == 0) ny++, mov++;
		else if (mov == 3)ny--, mov--;
	}
	else if (ny == 9) {
		ny--;
		if (mov == 0) nx++, mov = 3;
		else if (mov == 1)nx--, mov = 2;
	}
	else if (nx == 0) {
		nx++;
		if (mov == 1) ny++, mov = 0;
		else if (mov == 2) ny--, mov = 3;
	}
	else if (ny == 0) {
		ny++;
		if (mov == 2) nx--, mov = 1;
		else if (mov == 3)nx++, mov = 0;
	}
	x = nx, y = ny;
}
void fun(int x, int y, int mov) {
	cout << x << " " << y << '\n';
	if (cnt >= 2) return;
	ans.pb(mk(y, x));
	if (arr[y][x] == 'a')mov = (mov + 1) % 4, arr[y][x] = 'I';
	else if (arr[y][x] == 'c') mov = (mov + 3) % 4, arr[y][x] = 'I';
	get(x, y, mov);
	fun(x, y, mov);
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		for (int i = 9; i >= 0; i--) cin >> arr[i];
		dir.pb(mk(1, 1));
		dir.pb(mk(-1, 1));
		dir.pb(mk(-1, -1));
		dir.pb(mk(1, -1));
		fun(0, 0, 1);
		for (auto i : ans) {
			cout << i.ff << " " << i.ss << '\n';
		}
	}
	return 0;
}