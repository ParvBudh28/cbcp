#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
using namespace std;

int cnt[100005] = {0};
int sum[100005] = {0};

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

void calculateSum() {

	for (int i = 2; i <= 100000; i++) {
		for (int j = i; j <= 100000; j += i) {
			sum[i] += cnt[j];
		}
	}
}


int32_t main() {

	fastIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		cnt[data]++;
	}

	calculateSum();
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;
		if (query == 1) {
			cout << n << endl;
		}
		else
			cout << sum[query] << endl;
	}

	return 0;
}