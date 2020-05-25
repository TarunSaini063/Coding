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
		vector<vector<int>> v(k, vector<int>((n + k - 1) / k, INT_MAX));
		int arr[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 0; i < k; i++)
		{
			int k1 = 0;
			for (int j = i; j < n; j += k)
			{
				v[i][k1] = arr[j];
				k1++;
			}
			sort(all(v[i]));
		}
		int f = 0;
		vector<int> fn;
		for (int i = 0; i < (n - 1 + k) / k && f == 0 ; i++ )
		{
			for (int j = 0; j <  k; j++)
			{
				if (v[j][i] != INT_MAX) fn.pb(v[j][i]);
			}
		}
		int lst = 0;
		for (auto i : fn)
		{
			if (i < lst)
			{
				f = 1;
				break;
			}
			else lst = i;
		}
		if (f)cout << "no" << '\n';
		else cout << "yes" << '\n';
	}
	return 0;
}