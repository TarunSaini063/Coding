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
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int l, int h) //lomuto
{
	int pivot = arr[h], j = l - 1;
	for (int i = l; i < h; i++)
	{
		if (arr[i] < pivot)
		{
			j++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(arr[j + 1], arr[h]);
	return (j + 1);
}
int partition1(int arr, int l, int h) //hoare
{
	int i = l - 1, j = h + 1, pivot = arr[l];
	while (true)
	{
		do
		{
			i++;
		} while (arr[i] < pivot);
		do
		{
			j--;
		} while (arr[j] > pivot);
		if (i >= j) return j;
		swap(arr[j], arr[i]);
	}
}
void quick_sort(int arr[], int l, int h)
{
	if (l < h)
	{
		int k = partition(arr, l, h);
		quick_sort(arr, l, k - 1);
		quick_sort(arr, k + 1, h);
	}
}
void quick_sort1(int arr[], int l, int h)
{
	if (l < h)
	{
		int k = partition1(arr, l, h);
		quick_sort1(arr, l, k);
		quick_sort1(arr, k + 1, h);
	}
}
void less_stack(int arr[], int l, int h)
{
	while (l < h)
	{
		int k = partition(arr, l, h);
		if (k - l < h - l) {less_stack(arr, l, k - 1); l = k + 1;}
		else {less_stack(arr, k + 1, h); h = k - 1;}
	}
}
int main(void)
{
	FIO
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	less_stack(arr, 0, n - 1);
	for (auto j : arr) cout << j << " ";
	cout << "\n";
	return 0;
}