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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		ll k;
		cin >> n >> k;
		string s, ans = "";
		bool fl = false;
		cin >> s;
		ll cnt = 0;
		vector<int> arr(n, -1);
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1') cnt++;
			else
			{
				if (cnt <= k)
				{
					ans += "0";
					k -= cnt;
				}
				else
				{
					ans += string(cnt - k, '1');
					ans += "0";
					ans += string(k, '1');
					ans += s.substr(i + 1);
					fl = true;
					break;
				}
			}
		}
		if (!fl)
		{
			ans += string(cnt, '1');
		}
		cout << ans << "\n";
	}
	return 0;
}