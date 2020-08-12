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
	int t = 1;
	// cin>>t;
	while (t--)
	{
		set<int> s;
		int  n;
		cin >> n;
		int z = n % 10;
		if (z != 1 && z != 3 && z != 7 && z != 9) {
			cout << "-1";
			return 0;
		}
		int len = to_string(n).size();
		int num = 0;
		for (int i = 1; i <= len; i++) {
			num = num * 10 + 7;
		}
		int fl = 0;
		while (true) {
			int x = num % n;
			if (x == 0) {
				fl = 1;
				break;
			}
			if (s.find(x) != s.end()) break;
			s.insert(x);
			num = x * 10 + 7;
			len++;
		}
		if (fl) cout << len;
		else cout << -1;
	}
	return 0;
}