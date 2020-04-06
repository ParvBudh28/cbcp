#include<bits/stdc++.h>
#define w(t) int t;cin>>t;while(t--)
#define int long long int
using namespace std;

bitset<1000005> prime;
int maxSize = 1000000;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

void makeSieve() {


	for (int i = 3; i < maxSize; i += 2) {
		prime.set(i);
	}

	for (int i = 3; i * i < maxSize; i += 2) {
		if (prime[i]) {
			for (int j = i * i; j < maxSize; j += i) {
				prime.reset(j);
			}
		}
	}

	prime.set(2);

}

// segmented Sieve
void makeSegmentedSieve(int a, int b) {
	int size = (b - a) + 1;
	bitset<1000000> segSieve;

	for (int i = 0; i < size; i++) {
		int currNumber = (a + i);
		bool broken = false;
		if (currNumber >= maxSize) {
			for (int j = 2; j * j <= currNumber; j++) {
				if (prime[j]) {
					if (currNumber % j == 0) {
						broken = true;
						break;
					}
				}
			}

			if (!broken) {
				cout << currNumber << endl;
			}
		}
		else {
			if (prime[currNumber]) {
				cout << currNumber << endl;
			}
		}
	}

}

int32_t main() {

	fastIO();

	makeSieve();

	w(t) {

		int a, b;
		cin >> a >> b;
		if (b < maxSize) {
			for (int i = a; i <= b; i++) {
				if (prime[i]) {
					cout << i << "\n";
				}
			}
		}
		else {

			makeSegmentedSieve(a, b);

		}

		cout << endl;

	}

	return 0;
}