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
const int mxn = 1e5 + 1;
int arr[mxn], inc[mxn], ans[mxn];
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		memset(ans, -1, sizeof(ans));
		for (int i = 1; i <= n; i++) {
			if (arr[i] != arr[i - 1]) {
				ans[i] = arr[i - 1];
				inc[ans[i]] = 1;
			}
		}
		int m = 0;
		inc[arr[n]] = 1;
		for (int i = 1; i <= n; i++) {
			while (inc[m] == 1)m++;
			if (ans[i] == -1) {
				ans[i] = m;
				inc[m] = 1;
			}
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}