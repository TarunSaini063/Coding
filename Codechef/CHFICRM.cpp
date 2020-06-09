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
		int n, fv = 0, tn = 0;
		cin >> n;
		int arr[n], fl = 0;
		for (auto &i : arr)cin >> i;
		for (auto i : arr)
		{
			if (i == 5) fv++;
			else if (i == 10)
			{
				if (fv == 0)
				{
					fl = 1;
					break;
				}
				else fv--;
				tn++;
			}
			else if (i == 15)
			{
				if (tn != 0) tn--;
				else if (fv >= 2) fv -= 2;
				else {
					fl = 1;
					break;
				}
			}
		}
		if (fl) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}