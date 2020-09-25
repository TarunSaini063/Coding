#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxn = 1e3;
ll arr[mxn], n, x;
int main(void)
{
	cin >> n >> x;
	unordered_map<int, ar<int, 2>> mp;
	mp.reserve(1 << 20);
	for (int i = 0; i < n; i++)cin >> arr[i];
	int mn = *min_element(arr, arr + n);
	if (x < 4 * mn) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];
			if (mp.find(x - sum) != mp.end()) {
				ar<int, 2> tmp = mp[x - sum];
				cout << i + 1 << " " << j + 1 << " " << tmp[0] << " " << tmp[1] << '\n';
				return 0;

			}
		}
		for (int j = 0; j < i; j++) {
			mp[arr[i] + arr[j]] = {i + 1, j + 1};
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}