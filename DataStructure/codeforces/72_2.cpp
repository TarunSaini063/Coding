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
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		vector<ar<int, 2>>arr;
		for (int i = 0; i < n; i++) {
			int d, h;
			cin >> d >> h;
			arr.pb({d, h});
		}
		int diff = -1, tmp = -1;
		for (auto i : arr) {
			diff = max(diff, i[0] - i[1]);
			tmp = max(tmp, i[0]);
		}
		if (x <= tmp) {
			cout << "1\n";
			continue;
		}
		if (diff <= 0) {
			cout << "-1\n";
			continue;
		}
		else {
			int req = x - tmp;
			int cnt = (req + diff - 1 ) / diff + 1;
			cout << cnt << '\n';
			// cout << cnt << " " << tmp << " " << diff << " " << req << '\n';
		}
	}
	return 0;
}