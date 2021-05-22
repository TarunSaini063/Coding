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
		int n;
		int mxn = 1e6 + 1;
		cin >> n;
		int arr[mxn] = {0};
		arr[0] = 0;
		arr[1] = 1;
		for (int i = 2; i < mxn; i++) {
			if (arr[i] == 0) {
				for (int j = i; j <= mxn; j += i) {
					if (arr[j] == 0)
						arr[j] = i;
				}
			}
		}
		int v[n], freq[mxn] = {0};
		for (int &i : v) cin >> i;
		int gd = 0, fl = 0;
		for (int i = 0; i < n; i++) {
			int tmp = v[i];
			set<int> primes;
			while (tmp > 1 ) {
				primes.insert(arr[tmp]);
				tmp /= arr[tmp];
			}
			for (int j : primes) {
				if (freq[j]) {
					fl = 1;
				}
				// cout << j << " ";
				freq[j]++;
			}
			// cout << "\n";
			gd = __gcd(gd, v[i]);
		}
		if (fl == 0) cout << "pairwise coprime\n";
		else if (gd == 1) cout << "setwise coprime\n";
		else cout << "not coprime\n";
	}
	return 0;
}