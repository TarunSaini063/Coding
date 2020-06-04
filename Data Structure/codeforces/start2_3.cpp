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
	int n, m, d;
	cin >> n >> m >> d;
	int arr[m], ans[n] = {0}, sm = 0;
	for (auto &i : arr)cin >> i, sm += i;
	int curr = 0;
	for (int i = 0; i < m; i++)
	{
		int left = n + 1 - sm;
		if (curr + d >= left)
		{
			for (int i1 = left; i1 <= left + arr[i]; i1++)
			{
				ans[i1 - 1] = (i + 1);
			}
			curr = left + arr[i];

		}
		else
		{
			for (int i1 = curr + d; i1 < curr + d + arr[i]; i1++)
			{
				ans[i1 - 1] = (i + 1);
			}
			curr += d - 1 + arr[i];
		}
		// cout << curr << "  ";
		sm -= arr[i];
	}
	if (curr + d >= n + 1)
	{
		cout << "YES" << '\n';
		for (auto i : ans) cout << i << ' ';
		cout << '\n';
	}
	else cout << "NO\n";
	return 0;
}