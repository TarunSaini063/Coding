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
		int n;
		cin >> n;
		int arr[n], mn[n], mx[n];
		for (auto &i : arr)cin >> i;
		mn[0] = 0;
		mx[n - 1] = n - 1;
		for (int i = 1; i < n; i++) {
			mn[i] = i;
			if (arr[mn[i]] > arr[mn[i - 1]]) {
				mn[i] = mn[i - 1];
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			mx[i] = i;
			if (arr[mx[i]] > arr[mx[i + 1]]) {
				mx[i] = mx[i + 1];
			}
		}
		int fl = 0;
		for (int i = 1; i < n - 1; i++) {
			if (arr[mn[i - 1]] < arr[i] && arr[i] > arr[mx[i + 1]]) {
				cout << "YES\n";
				cout << mn[i - 1] + 1 << " " << i + 1 << " " << mx[i + 1] + 1 << '\n';
				fl = 1;
				break;
			}
		}
		if (fl == 0) cout << "NO\n";
	}
	return 0;
}