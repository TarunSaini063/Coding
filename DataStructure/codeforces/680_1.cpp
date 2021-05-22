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
void solve() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int dec = 0;
	for (int i = n - 2; ~i; i--) {
		if (arr[i] < dec) {
			cout << "NO\n";
			return;
		}
		if (arr[i] < arr[i + 1]) continue;
		dec += arr[i] - arr[i + 1];
	}
	cout << "YES\n";
}
int main(void)
{
	FIO
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}