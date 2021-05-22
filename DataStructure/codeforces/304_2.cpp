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
const int mxn = 5e6 + 1;
int prime[mxn];
ll comu[mxn];
int main(void)
{
	FIO
	for (int i = 2; i < mxn; i++) {
		if (prime[i] == 0) {
			for (int j = i; j < mxn; j += i) {
				prime[j] = i;
			}
		}
	}
	for (int i = mxn - 1; i >= 2; i--) {
		ll cnt = 0, num = i;
		while (prime[num]) {
			cnt++;
			num /= prime[num];
		}
		comu[i] = cnt;
	}
	for (int i = 3; i < mxn; i++) comu[i] += comu[i - 1];
	int t;
	cin >> t;
	while (t--)
	{
		ll a, b;
		cin >> a >> b;
		cout << comu[a] - comu[b] << "\n";
	}
	return 0;
}