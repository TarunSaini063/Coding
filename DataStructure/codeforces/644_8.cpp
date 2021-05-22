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
		if (n <= 3) {
			cout << "-1\n";
		}
		else {
			deque<int> q;
			q.push_back(3);
			q.push_back(1);
			q.push_back(4);
			q.push_back(2);
			for (int i = 5; i <= n; i++) {
				if (i % 2) q.push_back(i);
				else q.push_front(i);
			}
			while (!q.empty()) {
				cout << q.front() << " ";
				q.pop_front();
			}
			cout << "\n";
		}
	}
	return 0;
}