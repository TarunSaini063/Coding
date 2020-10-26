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
int one[32], n;
const int mxn = 1e5;
int arr[mxn];
void solve(int bit) {
	for (int i = 0; i < n; i++) {
		if (arr[i] != -1) {
			if (arr[i] & (1 << bit)) {
				int tmp = arr[i], x = 0;
				cout << tmp << " ";
				while (tmp) {
					if (tmp & 1) one[x]--;
					x++;
					tmp >>= 1;
				}
			}
			arr[i] = -1;
		}
	}
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		memset(one, 0, sizeof(one));
		cin >> n;
		map<ll, ll> mp;
		ll tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			int x = 0;
			while (tmp) {
				x++;
				tmp >>= 1;
			}
			mp[x]++;
		}
		ll ans = 0;
		for (auto i : mp) {
			if (i.ss > 1) {
				ll x = i.ss * (i.ss - 1) ;
				x >>= 1;
				ans += x;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}