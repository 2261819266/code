#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T,n,m,s;
	cin>>T>>n>>m>>s;
	char a[1000];
	for(int k=1;k>=0;k++)
	{
		cin>>a[k];
		if(a[k]>0)
		{
			a++;
			{
	            if(T-m/2*a<=T-n)
	           {
		            cout<<T-n;
	           }
                else
               {
    	           cout<<T-m/2*a;
	           }
	        }
	    }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
