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
		int arr[n + 1];
		for (int i = 1; i <= n; i++) cin >> arr[i];
		sort(arr + 1, arr + n + 1);
		// int mx = 0;s
		int curr = 0;
		for (int i = 1; i <= n; i++)
		{
			if (arr[i] <= i ) curr = i;
		}
		cout << curr + 1 << '\n';

	}
	return 0;
}