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
		ll n, x;
		cin >> n >> x;
		vector<ar<int, 2>> arr(n);
		for (int i = 0; i < n; i++) {
			cin	>> arr[i][0];
			arr[i][1] = i + 1;
		}
		sort(all(arr));
		for (int i = 0; i <= n - 3; i++) {
			int j = i + 1, k = n - 1;
			while (j < k) {
				int sum = arr[i][0] + arr[j][0] + arr[k][0];
				if (sum == x) {
					cout << arr[i][1] << " " << arr[j][1] << " " << arr[k][1] << "\n";
					return 0;
				}
				if (sum > x) {
					k--;
				}
				else j++;
			}
		}
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}