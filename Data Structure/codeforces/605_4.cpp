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
int arr[200005], dp1[200005], dp2[200005];
int main(void)
{
	FIO
	int n;
	cin >> n;
	ll arr[n];
	for (auto &i : arr) cin >> i;
	vector<int> d1(n, 0), d2(n, 0);
	d1[0] = 1;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) {
			d1[i] = d1[i - 1] + 1;
		}
		else {
			d1[i] = 1;
		}
		ans = max(ans, d1[i]);
	}
	d2[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		if (arr[i] < arr[i + 1])
		{
			d2[i] = d2[i + 1] + 1;
		}
		else
		{
			d2[i] = 1;
		}
		ans = max(ans, d2[i]);
	}
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] < arr[i + 1])
		{
			ans = max(ans, d1[i - 1] + d2[i + 1]);
		}
	}
	cout << ans << endl;
	return 0;

}