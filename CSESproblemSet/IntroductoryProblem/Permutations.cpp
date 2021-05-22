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
		int n;
		cin >> n;
		if (n <= 3 && n != 1) cout << "NO SOLUTION\n";
		else if (n == 1) cout << 1 << "\n";
		else {
			vector<int> arr;
			for (int i = 1; i <= (n + 1) / 2; i++) {
				arr.pb(n - i + 1);
				arr.pb(i);
			}
			int x = arr.back();
			arr.pop_back();
			if (n % 2 == 1) arr.pop_back();
			cout << x << " ";
			for (auto i : arr) cout << i << " ";
		}
	}
	return 0;
}