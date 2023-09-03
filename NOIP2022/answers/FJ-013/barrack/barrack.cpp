#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

inline int rd()
{
	int s=0;char x='x';
	while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')s=s*10+(x^48),x=getchar();
	return s;
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
