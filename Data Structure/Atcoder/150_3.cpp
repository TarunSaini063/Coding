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
	// cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> arr, brr(n), crr(n);
		for (int i = 1; i <= n; i++) arr.pb(i);
		for (auto &i : brr) cin >> i;
		for (auto &j : crr) cin >> j;
		int a = 0, b = 0, i = 0, j = 0;
		while (1) {
			if (i == 0 && arr != brr) {
				a++;
			}
			else i = 1;
			if (j == 0 && arr != crr) {
				b++;
			}
			else j = 1;
			if (i == 1 && j == 1) break;
			next_permutation(all(arr));
		}
		cout << abs(a - b) << "\n";

	}
	return 0;
}