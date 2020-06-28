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
	ll x, bits[20] = {0}, ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		for (int j = 0; j < 20; j++)
		{
			if (x & (1 << j)) bits[j]++;
		}
	}
	for (int j = 0; j < n; j++)
	{
		x = 0;
		for (int i = 0; i < 20; i++)
		{
			if (bits[i] > 0)
			{
				x |= (1 << i);
				bits[i]--;
			}
		}
		ans += x * x;
	}
	cout << ans << '\n';
	return 0;
}