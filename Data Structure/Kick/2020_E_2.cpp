#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
int n, a, b, c;
void solve(void)
{
	cin >> n >> a >> b >> c;
	if (a + b - c > n || c > b || c > a || c == 0 || c > a + b) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	if (c == 1) {
		if (a == 1 && b == 1) {
			if (n == 1) {
				cout << "1\n";
				return;
			}
			cout << "IMPOSSIBLE\n";
			return;
		}
	}
	int arr[n] = {0}, k1 = 0, val = 0;
	int tpa = a - c;
	int tpb = b - c;
	val = n - tpa ;
	// cout << val << " " << tpa << " " << tpb << "\n";
	while (tpa--) {
		arr[k1++] = val;
	}
	int k2 = n - 1;
	val = n - tpb ;
	while (tpb--) {
		arr[k2--] = val;
	}
	if (a < b) {
		while (c > 0) {
			arr[k1++] = n;
			c--;
			if (c == 0) break;
			arr[k2--] = n;
			c--;
			if (c == 0) break;
		}
	}
	else {
		while (c > 0) {
			arr[k2--] = n;
			c--;
			if (c == 0) break;
			arr[k1++] = n;
			c--;
			if (c == 0) break;

		}
	}
	while (k1 <= k2) {
		arr[k1++] = 1;
	}
	for (int i : arr) cout << i << " ";
	cout << "\n";
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}