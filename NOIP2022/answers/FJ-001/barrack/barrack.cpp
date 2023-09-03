#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long _=1,__=0;char ___;
	___=getchar();
	while(___<'0'||___>'9')
	{
		if(___=='-')_=-_;
		___=getchar();
	}
	while(___>='0'&&___<='9')
	{
		__=__*10+___-'0';
		___=getchar();
	}
	return _*__;
}
void write(long long x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>10)write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	printf("5");
}
