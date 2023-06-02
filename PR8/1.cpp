#include <iostream>
using namespace std;

int extended_gcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int gcd = extended_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return gcd;
}

int main() {
	int a = 35, b = 15, x, y;
	int gcd = extended_gcd(a, b, x, y);
	cout << "GCD(" << a << ", " << b << ") = " << gcd << endl;
	cout << "x = " << x << ", y = " << y << endl;
	return 0;
}
