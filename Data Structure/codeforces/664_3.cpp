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
		int n, m, c = 0;
		cin >> n >> m;
		vector<int> arr(n), brr(m);
		for (int &i : arr) cin >> i;
		for (int &j : brr) cin >> j;
		for (int i = 0; i < (1 << 9); i++) {
			int fl1 = 1;
			for (int j : arr) {
				int fl = 0;
				for (int k : brr) {
					int c = j & k;
					if ((c | i) == i) {
						fl = 1;
						break;
					}
				}
				if (fl == 0) {
					fl1 = 0;
					break;
				}
			}
			if (fl1) {
				cout << i << "\n";
				return 0;
			}
		}
	}
	return 0;
}