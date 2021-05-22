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
		int n, k, l;
		cin >> n >> k >> l;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];
		int time = 0, fl = 1;
		for (int i = 0; i < n; i++) {
			if (arr[i] > l) {
				fl = 0;
				break;
			}
			if (arr[i] + k <= l) {
				time = 0;
			}
			int dth = abs(k - time);
			if (dth + arr[i] <= l) {
				time++;
			}
			else {
				if (time >= k) {
					fl = 0;
					break;
				}
				else {
					int req = l - arr[i];
					req = k - req;
					time = req + 1;
				}
			}
		}
		if (fl) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}