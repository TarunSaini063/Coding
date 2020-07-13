#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
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
		int a[n + 1] = {0};
		for (int i = 1; i <= n; i++)cin >> a[i];
		int c = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i - 1] == i - 1 && a[i] != i)c++;
		}
		if (c == 0)cout << 0;
		else if (c == 1)cout << 1;
		else cout << 2;
		cout << "\n";
	}
	return 0;
}