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
	int n;
	cin >> n;
	int arr[n];
	for (auto &i : arr) cin >> i;
	int ans = 0, res = 0;
	for (int i = 1; i <= 30; i++)
	{
		res = 0;
		for (auto x : arr)
		{
			res += x;
			if (x > i) res = 0;
			res = max(res, 0);
			ans = max(ans, res - i);
		}
	}
	cout << ans << '\n';
	return 0;
}