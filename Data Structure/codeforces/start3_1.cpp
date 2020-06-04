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
	int k;
	cin >> k;
	while (k--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (auto &i : arr) cin >> i;
		sort(arr, arr + n, greater<int>());
		int mn = INT_MAX, ans = 1;
		for (int i = 0; i < n; i++)
		{
			mn = min(mn, arr[i]);
			if (mn >= (i + 1)) ans = i + 1;
			else break;
		}
		cout << ans << "\n";
	}
	return 0;
}