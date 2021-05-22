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
		cin >> n;
		vector<string> s(n);
		for (auto &i : s) cin >> i;
		int fl = 1;
		for (int i = 0; i < n && fl; i++)
		{
			for (int j = 0; j < n && fl; j++)
			{
				if (s[i][j] == '1')
				{
					int x = 0;
					if ((i < n - 1 && s[i + 1][j] == '1') || ( j < n - 1 && s[i][j + 1] == '1') || i == n - 1 || j == n - 1)
					{
						x = 1;
					}
					fl = x;
				}
			}
		}
		if (fl) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		cout.flush();
	}
	return 0;
}