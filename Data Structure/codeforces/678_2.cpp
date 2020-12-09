#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
const int mxn = 1e5 + 1;
int prime[mxn];
int main(void)
{
	FIO
	int t;
	vector<int> tot;
	prime[1] = 0;
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i < mxn; i++) {
		if (prime[i] == 0) {
			tot.pb(i);
			for (int j = 2 * i; j < mxn; j += i) prime[j] = 1;
		}
	}
	int mynum = tot.back();
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int tmp = 1;
		vector<int> arr;
		int dig = mynum;
		arr.pb(1);
		dig = mynum - 1;
		while (tmp < n - 1) {
			arr.pb(4);
			tmp++;
			dig -= 4;
		}
		arr.pb(dig);
		int x = sz(arr);
		for (int i = 0; i < n; i++) {
			for (int j = i, len = 0; len < n; len++, j++) cout << arr[j % x] << ' ';
			cout << '\n';
		}
	}
	return 0;
}