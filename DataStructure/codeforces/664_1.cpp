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
		vector<ll> arr;
		int e = 0, x;
		for (int i = 0; i < 4; i++) {
			cin >> x;
			if (x % 2 == 0)e++;
			arr.pb(x);
		}
		if (e >= 3) cout << "YES\n";
		else {
			ll mn = INT_MAX;
			for (int i = 0; i < 3; i++) mn = min(mn, arr[i]);
			if (mn == 0)cout << "NO\n";
			else {
				arr.back() = arr.back() + 3;
				for (int i = 0; i < 3; i++) {
					arr[i] -= 1 ;
				}
				e = 0;
				for (ll i : arr) {
					if (i % 2 == 0) e++;
				}
				if (e >= 3) cout << "YES\n";
				else cout << "NO\n";
			}
		}

	}
	return 0;
}