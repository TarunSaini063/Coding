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
		priority_queue<int> pq;
		int n, k, x;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> x;
			pq.push(x * 1.0);
		}
		while (k--) {
			x = pq.top();
			cout << setprecision(10) << fixed << x << "\n";
			pq.pop();
			if (x <= 1.0) break;
			int tp = x / 2;
			pq.push(tp);
			pq.push(x - tp);
		}

		x = (pq.top());
		cout << x << "\n";

	}
	return 0;
}