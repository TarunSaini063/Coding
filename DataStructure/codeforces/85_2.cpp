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
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		vector<ll>arr(n);
		for (auto &j : arr) cin >> j;
		sort(all(arr), greater<ll>());
		ll mx = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			// cout << mx << cnt << "\n";
			if (arr[i] >= x)
			{
				cnt++;
				mx += arr[i] - x;
			}
			else
			{
				while (i < n && mx + arr[i] >= x)
				{
					cnt++;
					mx -= (x - arr[i]);
					i++;
					// cout << mx << " " << cnt << "\n";
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}