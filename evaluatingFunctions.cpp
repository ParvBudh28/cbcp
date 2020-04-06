#include<bits/stdc++.h>
#define int long long int
using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

void revereString(string &a) {
	// reverse the string
	int aLen = a.length();
	for (int i = 0; i < (aLen / 2); i++) {
		swap(a[i], a[aLen - i - 1]);
	}
}

string intToString(int n) {
	string ans = "";
	while (n > 0) {
		int digit = n % 10;
		n /= 10;
		ans += ((char)digit + '0');
	}
	revereString(ans);
	return ans;
}

string stringMultiply(string a, int n) {
	string res = "";
	int carry = 0;
	int len = a.length();
	for (int i = 0; i < len; i++) {

		int product;
		int number = a[len - i - 1] - '0';
		product = number * n + carry;
		carry = product / 10;
		product = product % 10;
		res += (char(product) + '0');
	}

	while (carry > 0) {
		int lastDigit = carry % 10;
		carry /= 10;
		res += ((char)lastDigit + '0');
	}
	// cout << "before reversing: " << res << endl;
	// reverse the string
	revereString(res);
	// cout << "after reversing: " << res << endl;

	return res;
}

void addZeroesFront(string &a, int n) {

	if (n == 0) {
		return;
	}
	revereString(a);
	for (int i = 0; i < n; i++) {
		a += "0";
	}
	revereString(a);
}

string addStringsHelper(string a, string b) {
	// cout << "strings are: " << a << " " << b << endl;
	string ans = "";
	int len = a.length();
	int carry = 0;
	for (int i = 0; i < len; i++) {
		int number1 = a[len - i - 1] - '0';
		int number2 = b[len - i - 1] - '0';

		int add = number2 + number1 + carry;
		carry = add / 10;
		ans += (add % 10) + '0';
	}

	while (carry > 0) {
		ans += (carry % 10) + '0';
		carry /= 10;
	}
	revereString(ans);
	return ans;

}

string addStrings(string a, string b) {
	int aLen = a.length();
	int bLen = b.length();

	if (aLen > bLen) {
		addZeroesFront(b, (aLen - bLen));
		return addStringsHelper(a, b);
	}
	else {
		addZeroesFront(a, (bLen - aLen));
		return addStringsHelper(a, b);
	}
}

string subtractStringsHelper(string a, string b) {

	string ans = "";
	int len = a.length();
	for (int i = 0; i < len; i++) {

		int number1 = a[len - i - 1];
		int number2 = b[len - i - 1];

		if (number2 > number1) {
			number1 += 10;
			int sub = number1 - number2;
			ans += (char)sub + '0';

			int index = len - i - 2;
			while (a[index] == '0') {
				a[index] = '9';
				index--;
			}

			// decrease the value of the digit
			int dec = a[index] - '0';
			dec--;
			a[index] = (char)dec + '0';

		}
		else {
			int sub = number1 - number2;
			ans += (sub) + '0';
		}
	}
	revereString(ans);
	return ans;
}

string subtractStrings(string a, string b) {

	//a>b -> mathematically
	int aLen = a.length();
	int bLen = b.length();

	addZeroesFront(b, (aLen - bLen));
	return subtractStringsHelper(a, b);

}

string twoStringMultiply(string a, string b) {

	// remember b has to be the one with more length
	//i.e. -> a.length()<=b.length()
	string ans = "0";
	int len = a.length();
	for (int i = 0; i < len; i++) {
		int number = a[len - i - 1] - '0';
		string res = stringMultiply(b, number);
		// cout << "after String multiply : " << res << endl;
		for (int j = 0; j < i; j++) {
			res += "0";
		}
		ans = addStrings(ans, res);
	}

	return ans;

}

string fx(string x) {
	// f(x)=3x^2-x+10;

	string ans;

	// 3x^2;
	ans = twoStringMultiply(x, x);
	ans = stringMultiply(ans, 3);

	// 3x^2-x
	ans = subtractStrings(ans, x);


	string ten = intToString(10);

	// 3x^2-x+10
	ans = addStrings(ans, ten);

	// cout << "f(x):" << ans << endl;

	return ans;

}

string gx(string x) {
	// g(x)=4x^3+2x^2-5x+4
	string ans;

	//x^2
	string xsquared;
	ans = twoStringMultiply(x, x);
	xsquared = ans;
	//x^3
	ans = twoStringMultiply(x, xsquared);

	//4x^3
	ans = stringMultiply(ans, 4);
	// cout << "4x^3:" << ans << endl;

	//2x^2
	xsquared = stringMultiply(xsquared, 2);
	// cout << "2x^2:" << xsquared << endl;

	//4x^3+2x^2
	ans = addStrings(ans, xsquared);
	// cout << "4x^3+2x^2" << ans << endl;
	// 5x
	string fivex = stringMultiply(x, 5);

	//4x^3+2x^2-5x
	ans = subtractStrings(ans, fivex);

	string four = intToString(4);

	ans = addStrings(ans, four);

	// cout << "g(x)" << ans << endl;
	return ans;

}

string compute(string x) {
	string ans = addStrings(fx(x), gx(x));
	return ans;
}

int32_t main() {

	fastIO();

	string x;
	cin >> x;
	cout << compute(x);
	// cout << addStrings("8", "42");
	return 0;
}