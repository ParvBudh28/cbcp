#include<bits/stdc++.h>
#define int long long
#define w(t) int t;cin>>t; while(t--)
using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

bitset<1000005> prime;
void makeSieve() {

	for (int i = 3; i < 1000005; i += 2) {
		prime.set(i);
	}

	for (int i = 3; i * i < 1000005; i += 2) {
		if (prime[i]) {
			for (int j = i * i; j < 1000005; j += i) {
				prime.reset(j);
			}
		}
	}

	prime.set(2);
	return;
}

void createTPrimeMap() {

	makeSieve();
	return;
}


int32_t main() {

	fastIO();

	createTPrimeMap();

	w(t) {
		int n;
		cin >> n;

		double root = sqrt(n);
		int floorVal = floor(root);
		int ceilVal = ceil(root);
		if (floorVal != ceilVal)
			cout << "NO\n";
		else {
			if (prime[floorVal]) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}