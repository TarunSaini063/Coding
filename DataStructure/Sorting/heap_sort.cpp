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
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
int arr[10000];
int size=0;
void swap(int &a,int &b)
{
	a+=b;
	b=a-b;
	a=a-b;
}
int getmin()
{
	if(size==0) return -1;
	return arr[0];
}
void decrease(int id,int new_val)
{
	arr[id]=new_val;
	while(id>0&&arr[(id-1)/2<arr[id]])
	{
		swap(arr[(id-1)/2],arr[id]);
		id=(id-1)/2;
	}
}

void heapify(int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int small=i;
	if(l<size&&arr[l]<arr[small]) small=l;
	if(r<size&&arr[r]<arr[small]) small=r;
	if(small!=i)
	{
		swap(arr[small],arr[i]);
		heapify(small);
	}
}
int extract_min()
{
	if(size==0) return -1;
	int val=arr[0];
	arr[0]=arr[size-1];
	size--;
	heapify(0);
	return val;
}
void del(int id)
{
	decrease(id,INT_MIN);
	extract_min();
}
void insert(int i)
{
	size++;
	arr[size-1]=i;
	i=size-1;
	while(i>0&&arr[(i-1)/2]>arr[i]) swap(arr[i],arr[(i-1)/2]),i=(i-1)/2;
}
int main(void)
{
	FIO	
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	for(auto j : arr) insert(j);
	for(int i=0;i<n;i++)
	cout<<extract_min()<<" ";
	return 0;
}