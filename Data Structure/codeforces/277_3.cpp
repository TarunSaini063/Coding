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
bool valid(int n, int sum) {
	return sum >= 0 && sum <= 9 * n;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int m, sum, tp;
		cin >> m >> sum;
		string mn = "", mx = "";
		tp = sum;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j <= 9; j++) {
				if ((i > 0 || j > 0 || (j == 0 && m == 1)) && valid(m - i - 1, tp - j)) {
					tp -= j;
					mn += to_string(j);
					break;
				}
			}
		}
		tp = sum;
		for (int i = 0; i < m; i++) {
			for (int j = 9; j >= 0; j--) {
				if ((i > 0 || j > 0 || (j == 0 && m == 1)) && valid(m - i - 1, tp - j)) {
					tp -= j;
					mx += to_string(j);
					break;
				}
			}
		}
		if (mn == "" || sz(mn) != m) mn = "-1";
		if (mx == "" || sz(mx) != m) mx = "-1";
		cout << mn << " " << mx << "\n";
	}
	return 0;
}