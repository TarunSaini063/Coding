#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
ll arr[100][100], tmp[100][100], n, m;
ll getmid(vector<ll> vi) {
	sort(all(vi));
	ll ans = 0;
	int mid = 1;
	for (ll i : vi) {
		ans += abs(vi[mid] - i);
	}
	return ans;
}
ll getmid1(vector<ll>v) {
	ll ans = 0;
	int n = sz(v);
	for (int i = 0; i < n / 2; i++) {
		ans += abs(v[i] - v[n - i - 1]);
	}
	return ans;
}
ll solve(int i, int j) {
	if (j >= m / 2) return 0;
	ll ans = 0;
	// cout << i << " " << j << "\n";
	// cout << i << " " << m - j - 1 << "\n";
	// cout << n - i - 1 << " " << j << "\n";
	// cout << n - i - 1 << " " << m - j - 1 << "\n";
	ans +=  getmid({arr[i][j], arr[i][m - j - 1], arr[n - i - 1][j], arr[n - i - 1][m - j - 1]}) + solve(i, j + 1);
	return ans;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<ll> row, col, oth;
		memset(arr, 0, sizeof(arr));
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> tmp[i][j];
			}
		}
		int k = 0, l = 0;
		for (int i = 0; i < n; i++) {
			if (n % 2 == 1 && i == n / 2) {
				for (int j = 0; j < m; j++) row.pb(tmp[i][j]);
				continue;
			}
			k = 0;
			for (int j = 0; j < m; j++) {
				if (m % 2 == 1 && j == m / 2) {
					col.pb(tmp[i][j]);
					continue;
				}
				arr[l][k] = tmp[i][j];
				k++;
			}
			l++;
		}
		if (n % 2)n--;
		if (m % 2)m--;
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < m; j++) cout << arr[i][j] << " ";
		// 	cout << "\n";
		// }
		ll ans = 0;
		for (int i = 0; i < n / 2; i++) {
			ll tp = solve(i, 0);
			// cout << "\ntp= " << tp << "\n";
			ans += tp;
		}
		ans += getmid1(row);
		ans += getmid1(col);
		cout << ans << "\n";
	}
	return 0;
}