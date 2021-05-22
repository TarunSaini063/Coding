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
int get(int cnt)
{
	int ans = cnt / 3;
	cnt %= 3;
	ans += cnt / 2;
	cnt %= 2;
	ans += cnt;
	return ans;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		ll a, b;
		cin >> a >> b;
		if (a == b) cout << 0 << '\n';
		else if (a > b)
		{
			int cnt = 0;
			while (a > b && a % 2 == 0)
			{
				a >>= 1;
				cnt++;
			}
			if (a != b) cout << -1 << '\n';
			else cout << get(cnt) << '\n';

		}
		else
		{
			int cnt = 0;
			while (a < b && cnt <= 70)
			{
				a <<= 1;
				cnt++;
			}
			if (a != b) cout << -1 << '\n';
			else cout << get(cnt) << '\n';
		}
	}
	return 0;
}