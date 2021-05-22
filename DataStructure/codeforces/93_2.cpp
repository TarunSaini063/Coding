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
		string s;
		cin >> s;
		vector<int> arr;
		int i = 0, n = sz(s);
		while (i < n) {
			int j = i;
			if (s[i] == '1') {
				while (j < n && s[j] == '1')j++;
			}
			arr.pb(j - i);
			i = j + 1;
		}
		sort(all(arr), greater<int>());
		ll ans = 0;
		n = sz(arr);
		for (int i = 0; i < n; i += 2) {
			ans += arr[i];
		}
		cout << ans << "\n";
	}
	return 0;
}