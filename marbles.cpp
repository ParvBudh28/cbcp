#include<iostream>
#define ll long long
using namespace std;

ll nCr(ll n,ll k){
	if(k==0 || n-k==0){
		return 1LL;
	}
	ll maxK=max(k,n-k);
	ll ans=1;
	for(ll i=maxK+1;i<=n;i++){
		ans*=i;
	}
	for(ll i=2;i<=(n-maxK);i++){
		ans/=i;
	}
	return ans;
}	

int main(){

	int t;
	cin>>t;
	while(t--){
		ll n,k;	
		cin>>n>>k;

		// calculate n-1Ck-1 integral number of solutions of the x1+...+xr=n where xi>=1 for all i
		cout<<nCr(n-1,k-1)<<endl;
		// cout<<fact(29)<<endl;
	}
	return 0;
}