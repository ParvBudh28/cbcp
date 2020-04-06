#include<iostream>
#include<math.h>
#define ll long long
using namespace std;


int main(){

	string s;
	cin>>s;

	int ans;
	ans=(2*(pow(2,s.length()-1)-1));

	int bits[s.length()];
	for(int i=0;i<s.length();i++){
		if(s[i]=='7'){
			bits[i]=1;
		}
		else{
			bits[i]=0;
		}
	}

	// cout<<ans<<endl;

	for(int i=0;i<s.length();i++){
		// cout<<bits[i];
		if(bits[i]){
			ans+=pow(2,s.length()-i-1);
		}
	}

	cout<<(ans+1)<<endl;

	return 0;
}