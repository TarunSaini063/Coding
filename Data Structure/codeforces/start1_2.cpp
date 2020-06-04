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
		int n, r, p, s, r1 = 0, s1 = 0, p1 = 0;
		cin >> n >> r >> p >> s;
		string s11;
		cin >> s11;
		for (auto i : s11)
		{
			if (i == 'R') r1++;
			if (i == 'P') p1++;
			if (i == 'S') s1++;
		}
		int tp = p, tr = r, ts = s;
		p = min(r1, p) ;
		s = min(p1, s) ;
		r = min(s1, r);
		int mn = p + s + r;
		if (mn < (n + 1) / 2) cout << "NO" << '\n';
		else
		{
			cout << "YES" << '\n';
			string ans;
			for (auto i : s11)
			{
				if (i == 'R' && p) ans += 'P', p--, tp--;
				else if (i == 'P' && s) ans += 'S', s--, ts--;
				else if (i == 'S' && r) ans += 'R', r--, tr--;
				else ans += "-";

			}
			for (auto &i : ans)
			{
				if (i == '-')
				{
					if (tp) i = 'P', tp--;
					else if (tr) i = 'R', tr--;
					else if (ts) i = 'S', ts--;
				}
			}
			cout << ans;
			cout << '\n';
		}
	}
	return 0;
}