#include<bits/stdc++.h>
using namespace std;
	int l[10000][10000],p[10000][10000];
	main()
	{
	
	memset(l,0x3f,sizeof(l));
	memset(p,0x3f,sizeof(p));
	int n,m,as=0,w;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{  
    int v,u;
    cin>>v>>u;
	l[u][v]=l[v][u]=1;
	}
	for(int k=1;k<=n;k++)
	{
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
	{
		if(l[i][j]=1&&p[i][j]!=1)
    {   if(p[i][k]+p[k][j]!=2)
    {p[i][j]=1;
	}
	else
	{
   	for(int b=1;b<=2;b++)
   	{
		if(b=1)
		p[i][j]=1;
    
	}
	
	}
	}		
		
		}}
		
	as++;}
		
	

printf("d%",as);
	
	
	fclose(stdin);
	fclose(stdin);
	return 0;
	}
