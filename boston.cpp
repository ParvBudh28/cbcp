#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

vector<int> factors;

bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

void calculateFactors(int n){
	if(n<=1){
		return;
	}

	for(int i=2;i<=n;i++){
		if(n%i==0){
			factors.push_back(i);
			calculateFactors(n/i);
			break;
		}
	}
	return;
}

int digitSum(int n){
	int ans=0;
	while(n>0){
		ans+=(n%10);
		n/=10;
	}
	return ans;
}

int main(){

	int n;
	cin>>n;

	calculateFactors(n);
	if(!isPrime(n)){
		int factorSum=0;
		for(int i=0;i<factors.size();i++){
			factorSum+=digitSum(factors[i]);
			// cout<<factors[i]<<" ";
		}
		// cout<<endl;
		// cout<<"factorSum: "<<factorSum<<endl;

		int sum=digitSum(n);
		// cout<<"digitSum: "<<sum<<endl;
		if(sum==factorSum){
			cout<<"1"<<endl;
		}
		else{
			cout<<"0"<<endl;
		}
	}
	else{
		cout<<"0"<<endl;
	}
	

	return 0;
}