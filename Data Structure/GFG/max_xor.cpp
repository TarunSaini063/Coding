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
const int size = 20;
int ans;
struct node {
	node * left, *right;
	int num;
	node() {
		right = left = NULL;
		child = 1;
	}
};
node *insert(node *root, int val, int lev) {
	if (lev == -1) return NULL;
	int dig = val & (1 << lev);
	if (root == NULL) {
		node *tmp = new node();
		return tmp;
	}
	if (dig == 0) {
		root->left = insert(root->left, val, lev - 1);
	}
	else {
		root->right = insert(root->right, val, lev - 1);
	}
	int num = 0;
	if (root->left) num += root->left->num;
	if (root->right) num += root->right->num;
	root->num = num;
	return root;
}
void solve(node *root, int lev, int k, int val) {
	if (lev == -1) return;
	int valk = k & (1 << lev);
	int valv = val & (1 << lev);
	if (valv == 1) {
		if (valk == 1) {
			if (root->right) ans += root->right->num;
			solve(root->left, lev - 1, k, val);
		}
		else {
			solve(root->right, lev - 1, k, val);
		}
	}
	else {
		if (valk == 1) {
			if (root->left) ans += root->left->num;
			solve(root->right, lev - 1, k, val);
		}
		else {
			solve(root->left, lev - 1, k, val);
		}
	}
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, val = 0;
		cin >> n;
		ans = 0;
		vector<int>arr(n);
		for (int &i : arr) cin >> i;
		node *root = new node();
		root = insert(root, 0, size);
		for (int i = 0; i < n; i++) {
			val ^= arr[i];
			// solve(root, size, k, val);
			root = insert(root, val, size);
		}
		int l = 1, r = (1 << 22);
	}
	return 0;
}