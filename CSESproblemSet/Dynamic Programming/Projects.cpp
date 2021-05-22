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
		int n;
		cin >> n;
		ar<ll, 3> arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i][1] >> arr[i][0] >> arr[i][2];
		}
		sort(arr, arr + n);
		set<ar<ll, 2>> s;
		ll mx = 0;
		s.insert({0, 0});
		for (int i = 0; i < n; i++) {
			auto it = s.lower_bound({arr[i][1]});
			it--;
			mx = max(mx, (*it)[1] + arr[i][2]);
			s.insert({arr[i][0], mx});
		}
		cout << mx;
	}
	return 0;
}