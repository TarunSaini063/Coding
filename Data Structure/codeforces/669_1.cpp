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
		int arr[n];//, o = 0, z = 0;
		for (int &i : arr) {
			cin >> i;
		}
		if (n == 2) {
			if (arr[0] == 0 || arr[1] == 0)
			{	cout << "1\n";
				cout << 0 << "\n";
				continue;
			}
			else {
				cout << "2 \n";
				cout << "1 1\n";
				continue;
			}
		}
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				ans.pb(0);
			}
			else
			{
				if (i + 1 < n && arr[i + 1] == 1) {
					ans.pb(1);
					ans.pb(1);
					i++;
				}
			}
		}
		cout << sz(ans) << "\n";
		for (int i : ans) cout << i << " ";
		cout << "\n";
	}
	return 0;
}