#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define sz(v) (int)v.size();
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
const int mxn = 1e3+1;
ll H[mxn][mxn][2];
ll V[mxn][mxn][2];
ll mat[mxn][mxn];
int m,n;

int hoz(int i,int j,int curr){
	if(i>=n||j>=m||i<0||j<0) return 0;
	if(mat[i][j]==0) return 0;
	H[i][j][0] = curr;
	return H[i][j][1] = 1+hoz(i,j+1,curr+1);

}

int vir(int i,int j,int curr){
	if(i>=n||j>=m||i<0||j<0) return 0;
	if(mat[i][j]==0) return 0;
	V[i][j][0] = curr;
	return V[i][j][1] = 1+vir(i+1,j,curr+1);

}

int main(void){
	FIO	
	int T;
	cin>>T;
	for(int t = 1; t<=T; t++){
		cin>>n>>m;
		for(int i= 0;i<n;i++){
			for(int j =0;j<m;j++){
				cin>>mat[i][j];
				for(int k=0;k<2;k++){
					V[i][j][k]= H[i][j][k] = 0;
				}
			}
		}
		for(int i = 0 ; i<n;i++){
			for(int j = 0 ;j<m;j++)
			{
				if(mat[i][j]==1){
					if(H[i][j][0]==0) hoz(i,j,1);
					if(V[i][j][0]==0) vir(i,j,1);
				}
			}
		}
		ll res = 0;
		
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				for(int k =0 ;k<2;k++){
					for(int l =0; l<2;l++){
						res+=max(0ll,min(V[i][j][k],H[i][j][l]/2)-1)+max(0ll,min(V[i][j][k]/2,H[i][j][l])-1);
					}
				}
			}
		}
		cout<<"Case #"<<t<<": "<<res<<"\n";
	}
	return 0;
}