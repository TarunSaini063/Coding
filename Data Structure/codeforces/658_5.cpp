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
		int n, cnt = 1;
		cin >> n;
		int arr[2 * n];
		for (auto &i : arr) cin >> i;
		vector<int> v;
		int tmp = arr[0];
		for (int i = 1; i < 2 * n; i++) {
			if (arr[i] < tmp) cnt++;
			else {
				v.pb(cnt);
				cnt = 1;
				tmp = arr[i];
			}
		}
		v.pb(cnt);
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for ( auto i : v )
		{
			for ( int j = n; j - i >= 0; j-- )
				dp[j] |= dp[j - i];
		}
		if (dp[n]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}