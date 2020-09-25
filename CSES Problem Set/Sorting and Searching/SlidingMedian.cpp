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
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		multiset<int> s;
		int arr[n];
		for (int &i : arr) {
			cin >> i;
		}
		for (int i = 0; i < k; i++) {
			s.insert(arr[i]);
		}
		auto it = s.begin();
		for (int i = 0; i < (k - 1) / 2; i++) it++;
		for (int i = k; i <= n; i++) {
			cout << *it << " ";
			if (i == n) break;
			s.insert(arr[i]);
			if (arr[i] < (*it)) {
				it--;
			}
			if (arr[i - k] <= (*it)) {
				it++;
			}
			s.erase(s.lower_bound(arr[i - k]));
		}

	}
	return 0;
}