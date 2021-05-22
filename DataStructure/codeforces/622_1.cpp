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
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3, greater<int>());
		int ans = 0;
		if (arr[0] >= 1) ans++, arr[0]--;
		if (arr[1] >= 1) ans++, arr[1]--;
		if (arr[2] >= 1) ans++, arr[2]--;
		// sort(arr, arr + 3, greater<int>());
		if (arr[0] >= 1 && arr[1] >= 1) ans++, arr[0]--, arr[1]--;
		if (arr[0] >= 1 && arr[2] >= 1) ans++, arr[0]--, arr[2]--;
		if (arr[1] >= 1 && arr[2] >= 1) ans++, arr[1]--, arr[2]--;
		if (arr[0] >= 1 && arr[1] >= 1 && arr[2] >= 1) ans++;
		cout << ans << "\n";
	}
	return 0;
}