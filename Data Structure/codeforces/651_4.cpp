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
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (auto &i : arr) {
		cin >> i;
	}
	int mn = 0, ans;
	int mx = *max_element(arr, arr + n);
	while (mn <= mx)
	{
		int md = mn + (mx - mn) / 2;
		int find = false;
		for (int tn : {0, 1})
		{
			int x = tn;
			int len = 0;
			for (auto p : arr)
			{
				if (!x || p <= md)
				{
					len++;
					x = !x;
				}
			}
			if (len >= k)
			{
				find = true;
			}
		}
		if (find)
		{
			ans = md;
			mx = md - 1;
		}
		else mn = md + 1;
	}
	cout << ans << '\n';
	return 0;

}