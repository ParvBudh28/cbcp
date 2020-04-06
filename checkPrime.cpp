#include<iostream>
using namespace std;

bool checkPrime(int n) {
	bool prime = true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		if (checkPrime(n))
			cout << "Prime" << endl;
		else
			cout << "Not Prime\n";
	}

	return 0;
}