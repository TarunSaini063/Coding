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
const int mx = 1e5 + 1;
int sum[2 * mx * 100 + 1];
int arr[mx], n;
int main(void)
{
	FIO
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		cin >> n;
		ll mn = 0, mx = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (arr[i] < 0)
			{
				mn -= arr[i];
			}
			else mx += arr[i];

		}
		sum[mn]++;
		ll sb = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			sb += arr[i];
			for (int j = 0; j * j <= mx; j++)
			{
				if (sb + mn - j * j >= 0)
					ans += sum[sb + mn - j * j];
			}
			sum[sb + mn]++;
		}
		cout << ans << '\n';
		memset(sum, 0, sizeof(sum));

	}
	return 0;
}