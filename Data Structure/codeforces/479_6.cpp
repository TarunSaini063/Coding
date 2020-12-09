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
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, ans = 0, lst = 0;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			mp[arr[i]] = mp[arr[i] - 1] + 1;
			if (ans < mp[arr[i]]) {
				ans = mp[arr[i]];
				lst = arr[i];
			}
		}
		vector<int> v;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] == lst) {
				v.pb(i + 1);
				lst--;
			}
		}
		cout << sz(v) << "\n";
		reverse(all(v));
		for (int i : v) cout << i << " ";
		cout << "\n";
	}
	return 0;
}