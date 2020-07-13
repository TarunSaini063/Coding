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
		cin >> n >> x;
		int arr[n];
		for (auto &i : arr)cin >> i;
		sort(arr, arr + n);
		int ans = 0, l = 0, mn = INT_MAX;
		for (int i = n - 1; i >= 0; i--) {
			l++;
			mn = min(mn, arr[i]);
			if (mn * l >= x) {
				ans++;
				l = 0;
				mn = INT_MAX;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}