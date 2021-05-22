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
		int n, x, y;
		cin >> n;
		int arr[n + 1] = {0}, fl = 0, cv = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			fl = 0;
			for (int j = 0; j < x; j++)
			{
				cin >> y;
				if (arr[y] == 0 && fl == 0) arr[y] = 1, fl = 1;

			}
			if (!fl) cv = i + 1;
		}
		if (cv == -1) cout << "OPTIMAL\n";
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (!arr[i])
				{
					cout << "IMPROVE\n";
					cout << cv << " " << i << '\n';
					break;
				}
			}
		}
	}
	return 0;
}