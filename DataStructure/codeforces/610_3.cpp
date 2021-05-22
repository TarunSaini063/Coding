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
ll invmod(ll a) {return power(a, mod - 2);}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--) {
		int n, p, k;
		cin >> n >> p >> k;
		int arr[n];
		for (auto &I : arr)cin >> I;
		sort(arr, arr + n);
		ll sm = 0, ans = 0;
		vector<pair<int, int>> dp(n);
		for (int i = 0; i < n; i++) {
			ll curr = sm;
			int res = i;
			if (curr > p) break;
			for (int j = i + k - 1; j < n; j += k) {
				curr += arr[j];
				if (curr <= p) {
					res += k;


				} else break;
			}
			ans = max(ans, res);
			sm += arr[i];
		}
		cout << ans << "\n";
	}
	return 0;
}