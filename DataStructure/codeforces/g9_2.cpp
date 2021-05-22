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
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, fl = 0;
		cin >> n >> m;
		int arr[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				int cnt = 4;
				if (i == 0 || i == n - 1)cnt--;
				if (j == 0 || j == m - 1)cnt--;
				if (arr[i][j] > cnt)fl = 1;
				arr[i][j] = cnt;
			}
		}
		if (fl)cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					cout << arr[i][j] << " \n"[j == m - 1];
		}
	}
	return 0;
}