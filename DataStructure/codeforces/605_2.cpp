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
		string s;
		cin >> s;
		int l = 0, r = 0, u = 0, d = 0;
		for (auto i : s) {
			switch (i) {
			case 'L': l++;
				break;
			case 'R': r++;
				break;
			case 'D': d++;
				break;
			case 'U': u++;
			}
		}
		l = min(l, r);
		d = min(d, u);
		if (l == 0) {
			if (d != 0) {
				cout << "2\n" << "UD\n";
			}
			else cout << "0\n";
		}
		else if (d == 0) {
			if (l != 0) {
				cout << "2\n" << "LR\n";
			}
			else cout << "0\n";
		} else {
			cout << 2 * l + 2 * d << "\n";
			for (int j = 0; j < l; j++) cout << 'L';
			for (int j = 0; j < d; j++) cout << 'U';
			for (int j = 0; j < l; j++) cout << 'R';
			for (int j = 0; j < d; j++) cout << 'D';
			cout << "\n";
		}
	}
	return 0;
}