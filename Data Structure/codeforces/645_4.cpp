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
int main(void)
{
	FIO
	ll n, x;
	cin >> n >> x;
	ll pref[2 * n + 1], spref[2 * n + 1], arr[2 * n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) arr[n + i] = arr[i];
	spref[0] = pref[0] = 0;
	for (int i = 1; i <= 2 * n; i++)
	{
		pref[i] = pref[i - 1] + arr[i - 1];
		spref[i] = spref[i - 1] + arr[i - 1] * (arr[i - 1] + 1) / 2;
	}
	// for (int i = 0; i <= 2 * n; i++) cout << pref[i] << " ";
	// cout << '\n';
	ll res = 0;
	for (int i = 2 * n; i > n; i--)
	{
		int l = 1;
		int h = i;
		int ans = i;

		while (l <= h)
		{
			// cout << l << " " << h;
			int mid = (l + h) / 2;
			if ((pref[i] - pref[mid]) < x)
			{
				ans = mid;
				h = mid - 1;
			}
			else l = mid + 1;
			// cout << " pref dif " << pref[i] - pref[mid] << " mid " << pref[mid] << '\n';
		}
		// cout << "ans " << ans << '\n';
		ll tot = spref[i] - spref[ans - 1];
		ll ext = (pref[i] - pref[ans - 1]) - x;
		ll req = tot - ext * (ext + 1) / 2;
		res = max(res, req);
	}
	cout << res << '\n';
	return 0;
}