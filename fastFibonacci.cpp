#include<iostream>
#include<vector>
#define ll long long
#define mod 1000000007
using namespace std;


vector<vector<ll> > multiply(vector<vector<ll> > a1,vector<vector<ll> > a2){
	vector<vector<ll> > ans(2,vector<ll>(2));
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			ll sum=0;
			for(int k=0;k<2;k++){
				sum+=(a1[i][k]%mod)*(a2[k][j]%mod);
				sum%=mod;
			}
			ans[i][j]=sum;
		}
	}
	return ans;
}

vector<vector<ll> > pow(vector<vector<ll> > t,ll n){
	// if(n==1)
	if(n==1){
		return t;
	}
	vector<vector<ll> > temp(2,vector<ll>(2));
	// if n is odd
	if(n&1){
		temp=pow(t,n-1);
		temp=multiply(temp,t);
		return temp;
	}
	// if n is even
	else{
		temp=pow(t,n/2);
		temp=multiply(temp,temp);
		return temp;
	}
}

ll finalMultiply(vector<vector<ll> > temp){
	ll ans;
	ans=(temp[0][0]%mod)+(temp[0][1]%mod);
	ans%=mod;
	return ans;
}

ll calculateFibo(vector<vector<ll> >t,ll n){

	if(n==0){
		return 1;
	}

	if(n==1){
		return 1;
	}
	// calculate t^n-1
	vector<vector<ll> > temp(2,vector<ll>(2));
	temp=pow(t,n-1);
	return finalMultiply(temp);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<ll> > t(2,vector<ll>(2));
	t[0][0]=0;
	t[0][1]=1;
	t[1][0]=1;
	t[1][1]=1;

	ll test;
	cin>>test;
	while(test--){

		ll n;
		cin>>n;
		cout<<calculateFibo(t,n)<<endl;

	}

	return 0;
}