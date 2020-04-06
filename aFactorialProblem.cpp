#include<iostream>
#include<unordered_map>
#include<climits>
#define ll long long
using namespace std;

bool isPrime(int n){

	if(n==1){
		return false;
	}

	bool prime=true;

	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			prime =false;
			break;
		}
	}
	return prime;
}

ll legendreFunction(int n,int k){

	ll ans=0;
	n=n/k;
	while(n>0){
		ans+=n;
		n=n/k;
	}
	return ans;
}

unordered_map<int,int> factors;
void primeFactors(int n){
	while(n>1){
		for(int i=2;i<=n;i++){
			if(n%i==0){
				if(!factors.count(i)){
					factors.insert(make_pair(i,1));
				}
				else{
					factors[i]++;
				}
				n=n/i;
				break;
			}
		}
	}
	return;
}

int main(){

	int t;
	cin>>t;
	while(t--){
		factors.clear();
		int n;
		int k;

		cin>>n>>k;

		// if n is prime
		if(isPrime(k)){
			cout<<legendreFunction(n,k)<<endl;
		}
		else{
			ll ans=INT_MAX;
			primeFactors(k);
			for(auto a:factors){
				ans=min(legendreFunction(n,a.first)/a.second,ans);
			}
			cout<<ans<<endl;

	}

	return 0;	
}