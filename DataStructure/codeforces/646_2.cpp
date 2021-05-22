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
		string s;
		cin >> s;
		int n = (int)s.size();
		if (n <= 2 || s == "000" || s == "111") cout << 0 << "\n";
		else if (s == "101" || s == "010") cout << 1 << '\n';
		else
		{
			vector<int> z(n + 1, 0), o(n + 1, 0);
			z[0] = (s[0] == '0');
			o[0] = (s[0] == '1');
			for (int i = 1; i < n; i++)
			{
				z[i] = z[i - 1] + (s[i] == '0');
				o[i] = o[i - 1] + (s[i] == '1');
			}
			int ans = INT_MAX;
			for (int i = 0; i <= n; i++)
			{
				if (i == 0) {
					ans = min(z[n - 1], o[n - 1]);
					continue;
				}

				ans = min({ans, z[i - 1] + (o[n - 1] - o[i - 1]), o[i - 1] + z[n - 1] - z[i - 1]});
			}
			cout << ans << "\n";
		}
	}
	return 0;
}