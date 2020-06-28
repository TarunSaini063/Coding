#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
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
		int m, n;
		cin >> n >> m;
		vector<int> arr(n);
		for (auto &i : arr)cin >> i;
		sort(all(arr));
		int id = lower_bound(all(arr), m - 1) - arr.begin();
		if (id == n || arr[id] != m - 1) {
			cout << "-1\n";
			continue;
		}
		// cout << "id= " << id << '\n';
		while (id < n && arr[id] == m - 1)id++;
		id--;
		int x = 1, i;
		for (i = 0; i <= id; i++)
		{
			if (arr[i] == x)x++;
		}
		if (x != m) cout << -1 << "\n";
		else {
			int tp = id + 1;
			id++;
			while (id < n) {
				if (arr[id] == m) id++;
				else break;
			}
			tp += n - id;
			cout << tp << "\n";
		}
	}
	return 0;
}