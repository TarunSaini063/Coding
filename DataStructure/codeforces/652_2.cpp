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
		int n;
		string s;
		cin >> n >> s;
		vector<int>ids;
		int arr[n] = {0};
		int i = 0;
		while (i < n) {
			if (s[i] == '1') {
				int j = i;
				while (j < n && s[j] != '0')j++;
				if (j == n) break;
				while (j < n && s[j] == '0')j++;
				j--;
				while (i < n && i <= j && arr[i] != -1) arr[i++] = -1;

			}
			else i++;
		}
		for (int i = 0; i < n; i++) {
			if (arr[i] != -1)cout << s[i];
			else {
				cout << 0;
				while (i < n && arr[i] == -1)i++;
				i--;
			}
		}
		cout << '\n';

	}
	return 0;
}