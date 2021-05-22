
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
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int i = 1, j = n;
		int  ans[n + 1] = {0}, imodj, jmodi;
		set<int> s;
		for (int i = 1; i <= n; i++) s.insert(i);
		while (i < j) {
			cout << "? " << i << " " << j << "\n";
			cout.flush();
			cin >> imodj;
			cout << "? " << j << " " << i << "\n";
			cout.flush();
			cin >> jmodi;
			if (imodj >= jmodi) {
				ans[i] = imodj;
				s.erase(ans[i]);
				i++;
			}
			else {
				ans[j] = jmodi;
				s.erase(ans[j]);
				j--;
			}
		}
		assert(sz(s) <= 1);
		cout << "! ";
		cout.flush();
		for (int i = 1; i <= n; i++) {
			if (ans[i] != 0) cout << ans[i] << " ";
			else cout << *s.begin() << " ";
			cout.flush();
		}
		cout << "\n";
		cout.flush();

	}

	return 0;
}