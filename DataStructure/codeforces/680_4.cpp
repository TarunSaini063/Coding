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
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ar<ll, 2> arr[n];
		for (int i = 0; i < n; i++) cin >> arr[i][0];
		for (int i = 0; i < n; i++) cin >> arr[i][1];
		sort(arr, arr + n, [](ar<ll, 2> a1, ar<ll, 2> a2) {
			if (a1[0] == a2[0]) return a1[1] < a2[1];
			return a1[0] > a2[0];
		});
		ll curr = 0;
		for (int i = 0; i < n; i++) {
			if (curr + arr[i][1] >= arr[i][0]) {
				curr = max(curr, arr[i][0]);
				break;
			}
			curr += arr[i][1];
		}
		cout << curr << '\n';

	}
	return 0;
}