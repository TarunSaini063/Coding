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
struct tree
{
	vector<int> bit;
	int n;
	tree(int n) {
		this->n = n + 1;
		bit.assign(n + 1, 0);
	}
	tree(vector<int> arr) : tree(arr.size()) {
		for (int i = 0; i < (int)arr.size(); i++) {
			upd(i, arr[i]);
		}
	}
	void upd(int c, int val) {
		for (c++; c <= n; c += c & -c) {
			bit[c] += val;
		}
	}
	int sum(int x) {
		int sm = 0;
		for (x++; x > 0; x -= x & -x) {
			sm += bit[x];
		}
		return sm;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

};


int main(void)
{
	FIO
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &i : arr)cin >> i;
	struct tree b1 = tree(arr);
	while (true) {
		int x, i;
		cin >> x;
		if (x == -1) break;
		else if (x == 1) {
			cin >> i >> x;
			b1.upd(i, x - arr[i]);
			arr[i] = x;
		}
		else if (x == 0) {
			cin >> x >> i;
			cout << b1.sum(x, i) << "\n";
			cout.flush();
		}
	}
	return 0;
}

