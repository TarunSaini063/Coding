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
		int n;
		cin >> n;
		ll ans1 = 1 << n;
		ll ans2 = 0;
		ll mx = 1 << n;
		for (int i = 1; i <= n / 2; i++)
		{
			mx /= 2;
			ans2 += mx;
		}
		for (int i = 1; i <= n / 2 - 1; i++)
		{
			mx /= 2;
			ans1 += mx;
		}
		cout << abs(ans2 - ans1) << "\n";
	}
	return 0;
}