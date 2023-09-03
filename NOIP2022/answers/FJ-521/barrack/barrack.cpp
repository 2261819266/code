#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	freopen("barrack.out","w",stdout);
	srand(114514);
	int a=rand();
	srand(1919810);
	int b=rand();
	cout << b%a%int(1e9+7);
}
