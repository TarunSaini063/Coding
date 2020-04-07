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
void getzee(string s,vector<int> &arr)
{
	int l,r;
	arr[0]=l=r=0;
	int n=(int)s.size();
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<n&&s[r-l]==s[r]) r++;
			arr[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(arr[k]<r-i+1)
			{
				arr[i]=arr[k];
			}
			else
			{
				l=i;
				while(r<n&&s[r-l]==s[r]) r++;
				arr[i]=r-l;
				r--;
			}
		}
	}
}
int main(void)
{
	FIO	
	string p,t;
	cin>>t>>p;
	int n=t.size()+p.size()+1;
	vector<int> arr(n);
	getzee(p+"$"+t,arr);
	int st=p.size();
	for(int i=0;i<n;i++)
	{
		if(arr[i]==st)
		{
			st=i;
			break;
		}
	}
	cout<<t.substr(st-p.size()-1,p.size())<<" ";
	return 0;
}