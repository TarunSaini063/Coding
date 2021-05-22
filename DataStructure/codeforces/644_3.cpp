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
		int n, e = 0, o = 0;
		cin >> n;
		vector<int> arr(n);
		for (auto &i : arr) {
			cin >> i;
			if (i & 1) o++;
			else e++;
		}
		e %= 2;
		o %= 2;
		sort(all(arr));
		if (e == 0 && o == 0)
		{
			cout << "YES" << '\n';
		}
		else if (e ^ o)
		{
			cout << "NO" << '\n';
		}
		else
		{
			int fl = 0;
			for (int i = 0; i < n; i++)
			{
				if (arr[i] & 1)
				{
					if (binary_search(all(arr), arr[i] + 1) || binary_search(all(arr), arr[i] - 1))
					{
						fl = 1;
						break;
					}
				}
			}
			if (fl) cout << "YES" << '\n';
			else cout << "NO" << '\n';

		}

	}
	return 0;
}