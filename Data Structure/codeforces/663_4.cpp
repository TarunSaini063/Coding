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
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<string> arr(n);
		for (auto &i : arr)cin >> i;
		if (n >= 4 && m >= 4) cout << -1 << '\n';
		else {
			if (n <= 1 || m <= 1) cout << 0 << '\n';
			else {
				int ans = 0;
				int first = 0;
				for (int i = 0; i + 2 <= n; i++) {
					for (int j = 0; j + 2 <= m; j++) {
						int odd = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] - 4 * ('0');
						first++;
						if (odd % 2 == 0) {
							if (first == 1) {
								ans++;
							}
							else {
								int lastn = -1, lastm = -1;
								if (i != 0) {
									lastn = arr[i][0] + arr[i][1] - 2 * ('0');
								}
								if (j != 0) {
									lastm = arr[0][j] + arr[1][j] - 2 * ('0');
								}
								if (lastn == -1 || lastm == -1) ans += 1;
							}
						}
					}
				}
				cout << ans << '\n';
			}
		}
	}
	return 0;
}