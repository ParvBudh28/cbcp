#include<iostream>
#include<vector>
#define ll long long 
#define mod 1000000000

using namespace std;


vector<vector<ll> > multiply(vector<vector<ll> > a1,vector<vector<ll> > a2,int size){
	vector<vector<ll> > ans(size,vector<ll>(size));
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			ll sum=0;
			for(int k=0;k<size;k++){
				sum+=(a1[i][k]%mod)*(a2[k][j]%mod);
				sum%=mod;
			}
			ans[i][j]=sum;
		}
	}
	return ans;
}

vector<vector<ll> > pow(vector<vector<ll> > t,ll n,int size){
	// if(n==1)
	if(n==1){
		return t;
	}
	vector<vector<ll> > temp(size,vector<ll>(size));
	// if n is odd
	if(n&1){
		temp=pow(t,n-1,size);
		temp=multiply(temp,t,size);
		return temp;
	}
	// if n is even
	else{
		temp=pow(t,n/2,size);
		temp=multiply(temp,temp,size);
		return temp;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin>>test;
	while(test--){
		int k;
		cin>>k;
		vector<ll> b(k);
		vector<ll> c(k);
		for(int i=0;i<k;i++){
			cin>>b[i];
		}
		for(int i=0;i<k;i++){
			cin>>c[i];
		}

		ll n;
		cin>>n;

		vector<vector<ll> > t(k,vector<ll>(k));
		for(int i=0;i<k-1;i++){
			t[i][i+1]=1;
		}

		for(int i=0;i<k;i++){
			t[k-1][i]=c[k-i-1];
		}

		vector<vector<ll> > power(k,vector<ll>(k));
		power=pow(t,n-1,k);

		ll sum=0;
		for(int i=0;i<k;i++){
			sum+=(power[0][i]%mod)*(b[i]%mod);
			sum%=mod;
		}

		cout<<sum<<endl;

		// for(ll i=0;i<k;i++){
		// 	for(ll j=0;j<k;j++){
		// 		cout<<t[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

	}

	return 0;
}