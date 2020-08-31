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
const int mxn = 2e5 + 1;
int arr[mxn], dif[mxn];
void solve(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n - 1; i++) {
		dif[i] = arr[i + 1] - arr[i];
	}
	int ans = 0, cur = 0, i = 0;
	while (i < n - 1) {
		int j = i + 1;
		while (j < n - 1 && dif[j] == dif[i])j++;
		ans = max(ans, j - i + 1);
		i = j;
	}
	cout << ans << "\n";
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