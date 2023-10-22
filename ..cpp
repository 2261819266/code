#include <iostream>
#include <cmath>

using std::cout;

#define ll long long 

double log(ll x, ll y) {
	return log(y) / log(x);
}

int main() {
	ll y = 1e18, z = y + 1;
	double x = sqrt(y - 1);
	printf("%.100lf\n\n", x);
}