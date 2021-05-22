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
		string s;
		cin >> s;
		string mx = "1", mn = "1";
		for (int i = 1; i < n; i++)
		{
			if (fl) mn += s[i], mx += '0';
			else
			{
				if (s[i] == '1') {
					mx += "1";
					mn += "0";
					fl = 1;
				}
				else if (s[i] == '0')
				{
					mx += "0";
					mn += "0";
				}
				else
				{
					mx += "1";
					mn += "1";
				}
			}
		}
		cout << mx << "\n" << mn << '\n';
	}
	return 0;
}