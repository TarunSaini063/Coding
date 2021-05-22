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
//#ifndef ONLINE_JUDGE
//	freopen("input1.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
//#endif
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (auto &i : a) cin >> i;
		for (auto &i : b) cin >> i;
		int mx = -2, mn = 2;
		int fl = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				ll dif = b[i] - a[i];
				if ((dif < 0 && mn != -1) || (dif > 0 && mx != 1))
				{
					fl = 1;
					break;
				}
			}
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
		}
		if (fl) cout << "NO" << '\n';
		else cout << "YES" << '\n';

	}
	return 0;
}