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
const int mxn = 1e5 + 1;
int arr[mxn], cnt[mxn];
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			cnt[i] = 1;
			if (arr[i] > arr[i - 1]) cnt[i] = cnt[i - 1] + 1;
		}
		int ans = 0;
		// for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
		for (int i = 1; i <= n; i++) {
			ans = max(ans, min(cnt[i] + 1, n));
			if (arr[i - cnt[i]] + 1 < arr[i - cnt[i] + 2] || arr[i - cnt[i] + 1] - 1 > arr[i - cnt[i] - 1])
				ans = max(ans, cnt[i] + cnt[i - cnt[i]]);
		}
		cout << ans << "\n";
	}
	return 0;
}