#include<bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}
int mod = 1000000007;
ll x, y;
void extendedEuclid(int a, int b) {

	if (b == 0) {
		x = 1ll; y = 0ll;
		return;
	}

	extendedEuclid(b, a % b);
	ll cX = y;
	ll cY = x - ((a / b) * y);
	x = cX;
	y = cY;
}

int findInverse(int n) {
	extendedEuclid(n, mod);
	long long int ans = (x + mod);
	int finalAns = ans % mod;
	return finalAns;
}

int main() {

	fastIO();

	int n;
	cin >> n;

	cout << findInverse(n) << endl;

	return 0;
}