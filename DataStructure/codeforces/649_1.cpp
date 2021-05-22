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
		int n, x, i, j;
		cin >> n >> x;
		int arr[n];
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		i = 0; j = n - 1;
		while (i <= j && arr[i] % x == 0) i++;
		while (j >= i && arr[j] % x == 0) j--;
		if (i > j) cout << "-1\n";
		else if (sum % x != 0) cout << n << '\n';
		else cout << max({i + 1, n - j, n - i - 1, j}) << '\n';
	}

	return 0;
}