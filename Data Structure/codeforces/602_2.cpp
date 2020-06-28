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
		int n, fl = 0;
		cin >> n;
		int arr[n], fre[n + 1] = {0}, brr[n] = {0};
		for (auto &i : arr)cin >> i;
		brr[0] = arr[0];
		fre[arr[0]] = 1;
		for (int i = 1; i < n; i++)
		{
			if (arr[i] != arr[i - 1]) brr[i] = arr[i], fre[arr[i]] = 1, fl++;
			if (arr[i] < arr[i - 1]) {
				fl = -1;
				break;
			}
		}
		if (fl == -1) {
			cout << "-1\n";
			continue;
		}
		int i = 0, j = 1;
		while (fl < n && j < n && i <= n)
		{
			for (; i < n; i++)
			{
				if (brr[i] == 0)
				{
					break;
				}
			}
			if (i == n) break;
			for (; j <= n; j++)
			{
				if (fre[j] == 0)
				{
					brr[i] = j;
					fre[j] = 1;
					i++;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (brr[i] > arr[i] || brr[i] == 0)
			{
				fl = -1;
				break;
			}
		}
		if (fl == -1) cout << fl << "\n";
		else
		{
			for (auto i : brr) cout << i << " ";
			cout << "\n";
		}
	}
	return 0;
}