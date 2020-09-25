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
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, x, X;
		cin >> n >> X;
		vector<pair<int, int>> arr;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			arr.pb(mk(x, i));
		}
		sort(all(arr));
		int i = 0, j = n - 1;
		while (i < j) {
			if (arr[i].ff + arr[j].ff == X) {
				cout << arr[i].ss << " " << arr[j].ss << "\n";
				return 0;
			}
			if (arr[i].ff + arr[j].ff > X)j--;
			else i++;
		}
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}