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
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(n);
		for (auto &i : a) cin >> i;
		sort(all(a));
		for (auto &i : b) cin >> i;
		sort(all(b), greater<int>());
		ll sm = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > b[i]) sm += a[i];
			else
			{
				if (k > 0)
				{
					sm += b[i];
					k--;
				}
				else sm += a[i];
			}

		}
		cout << sm << "\n";
	}
	return 0;
}