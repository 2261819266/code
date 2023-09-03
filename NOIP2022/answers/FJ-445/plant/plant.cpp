#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int n,m[10],a,c,f;
	cin>>n>>m;
	for(int i=1;i>n;i++)
	{
		if(a[i]=1)
		i++;
		if(c%n-f%n>=n-1)
		cout<<n-1;
		else
		cout<<" "<< c%n-f%n;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
