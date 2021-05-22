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
int arr[501], n, x;
int solve() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int fl = 0;
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				fl = 1;
				break;
			}
		}
		if (!fl) return ans;
		if (arr[i] > x) {
			swap(arr[i], x);
			ans++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			ans = -1;
			break;
		}
	}
	return ans;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> x;
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << solve() << '\n';
	}
	return 0;
}