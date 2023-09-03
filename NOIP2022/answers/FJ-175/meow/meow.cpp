#include <bits/stdc++.h>
using namespace std;
int n,m,k,t,a[2000003];
int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();} 
	return x;
}
void print(long long x)
{
	if(x>9) print(x/10);
	putchar('0'+(x%10));
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read(),m=read(),k=read();
		for(register int i=1;i<=m;i++) a[i]=read();
		if(n==1){
			printf("%d\n",m);
			for(int i=1;i<=m;i++) printf("1 1\n");
			continue;
		}
	}
	fclose(stdin);
    fclose(stdout);
	//system("pause");
	return 0;
}
