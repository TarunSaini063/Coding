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
	int t, cnt = 2;
	cin >> t;
	int arr[63250];
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < 63244; i += 2) {
		arr[i] = cnt * cnt;
		arr[i + 1] = cnt * (cnt + 1);
		cnt++;
	}
	while (t--)
	{
		int n;
		cin >> n;
		int ans = lower_bound(arr, arr + 63244, n) - arr;
		cout << ans << "\n";
	}
	return 0;
}