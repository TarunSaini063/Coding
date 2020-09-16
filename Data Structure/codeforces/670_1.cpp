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
		int n, x;
		cin >> n;
		vector<int>arr1(102, 0), arr2(102, 0);
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (arr1[x] == 0) arr1[x] = 1;
			else arr2[x] = 1;
		}
		int ans = 0;
		x = 2;
		while (x--) {
			while (true) {
				int mx1, mx2;
				for (int i = 0; i <= 101; i++) {
					if (arr1[i] == 0) {
						mx1 = i;
						break;
					}
				}
				for (int i = 0; i <= 101; i++) {
					if (arr2[i] == 0) {
						mx2 = i;
						break;
					}
				}
				ans = max(ans, mx1 + mx2);
				int fl = 0;
				for (int i = 0; i <= 100; i++) {
					if (arr1[i] == 0 && arr2[i] == 1) {
						arr2[i] = 0;
						arr1[i] = 1;
						fl = 1;
						break;
					}
				}
				if (fl == 0) break;
			}
			arr1.swap(arr2);
		}
		cout << ans << "\n";
	}
	return 0;
}