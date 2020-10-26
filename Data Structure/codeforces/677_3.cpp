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
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int mn = *min_element(arr, arr + n);
		int mx = *max_element(arr, arr + n);
		if (mn == mx) cout << "-1\n";
		else {
			for (int i = 0; i < n; i++) {
				int fl = 0;
				if (arr[i] == mx) {
					if (i - 1 >= 0 && arr[i - 1] < mx) {
						fl = 1;
					}
					if (i + 1 < n && arr[i + 1] < mx) {
						fl = 1;
					}
					if (fl) {
						cout << i + 1 << "\n";
						break;
					}
				}
			}
		}
	}
	return 0;
}