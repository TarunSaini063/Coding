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
ll invmod(ll a) {return power(a, mod - 2);};
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int arr[n + 1];
		for (int i = 0; i < n; i++) {
			cin >> arr[i + 1];
		}
		ll mat[n + 1][n + 1];
		memset(mat, 0, sizeof(mat));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mat[i][j] = arr[i] + arr[j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << mat[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
				cout << mat[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		ll ans = 0;
		for (int sz = 1; sz <= n; sz++) {
			for (int i = 1; i <= n - sz + 1; i++) {
				for (int j = 1; j <= n - sz + 1; j++) {
					int i1 = i + sz - 1;
					int j1 = j + sz - 1;
					ll req = mat[i1][j1] - mat[i1][j - 1] - mat[i1 - 1][j1] + mat[i][j];
					cout << i << " " << j << " " << i1 << " " << j1 << " " << req << "\n";
					if (req == x)ans++;
				}
			}
		}
		// cout << ans << "\n";
	}
	return 0;
}