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
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll cnt = 0, num = 0;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				ll curr = 0, tmp = n;
				while (tmp % i == 0) {
					tmp /= i;
					curr++;
				}
				if (cnt <= curr) {
					cnt = curr;
					num = i;
				}
			}
		}
		if (cnt == 0) {
			cout << "1\n";
			cout << n << '\n';
			continue;
		}
		cout << cnt << "\n";
		for (int i = 0; i < cnt - 1; i++) {
			cout << num << " ";
		}
		while (n % num == 0) n /= num;
		cout << n*num << "\n";
	}
	return 0;
}