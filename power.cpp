#include<iostream>
#define ll long long

using namespace std;

ll power(int n,int k){
	if(k==0){
		return 1;
	}
	if(k==1){
		return n;
	}
	// odd k
	if(k&1){
		return n*power(n,k-1);
	}

	// evev k
	else{
		ll ans=power(n,k/2);
		return ans*ans;
	}

}

int main(){

	int n,k;
	cin>>n>>k;

	cout<<power(n,k)<<endl;

	return 0;
}