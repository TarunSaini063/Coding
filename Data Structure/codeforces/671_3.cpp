#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll int
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		ll n, x, sum = 0, fl = 0;
		cin >> n >> x;
		set<ll> s;
		s.insert(x);
		for (int i = 0; i < n; i++) {
			ll p;
			cin >> p;
			if (p == x) fl = 1;
			sum += x - p;
			s.insert(p);
		}
		if (sz(s) == 1 && sum == 0) cout << "0\n";
		else if (sum == 0 || fl) cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}