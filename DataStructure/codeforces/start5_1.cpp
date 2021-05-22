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
		int n, fl = 1;
		cin >> n;
		set<int> s;
		int arr[n], brr[n];
		for (auto &i : arr) cin >> i;
		for (auto &i : brr)cin >> i;
		for (int i = 0; i < n; i++)brr[i] -= arr[i];
		for (int i = 0; i < n; i++)
		{
			if (brr[i] != 0)
			{
				int num = brr[i];
				if (num < 0) {
					fl = 0;
					break;
				}
				while (i < n && brr[i] == num) i++;
				if (i == n) break;
				for (int j = i; j < n; j++)
				{
					if (brr[j] != 0) {
						fl = 0;
						break;
					}
				}
			}
		}
		if (fl == 0) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}