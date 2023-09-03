#include<bits/stdc++.h>
using namespace std;
	int a[100000],b[100000],r[100000],l[100000],w[100000],bm[100000],am[100000];
	main()
	{
		freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	long long T,n,Q;
	cin>>T>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	w[i]=0;
	am[i]=0;
	bm[i]=0;
    }
    for(int i=1;i<=n;i++)
	{
	cin>>b[i];
    }
	cin>>Q;
	 for(int i=1;i<=Q;i++)
	{
	cin>>l[i]>>r[i];
    }
    
    
    for(int i=1;i<=Q;i++)
    {
    	for(int p=l[i];p<=r[i];p++)
	{
	for(int q=r[i];q>p;q--)
    {
    	int x=0;
    	for(int k=p;k<=q;k++)
    	{
    		
    		am[k]=max(am[k-1],a[k]);
    		bm[k]=max(bm[k-1],b[k]);
    		x=am[k]*bm[k];
		}
    	w[i]=w[i]+x;
	}
	}
	}
	
	for(int i=1;i<=Q;i++)
	{
		
	cout<<w[i] <<endl;
	}
	
	fclose(stdin);
	fclose(stdin);
	return 0;
	}

