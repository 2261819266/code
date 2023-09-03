#include <iostream>
using namespace std;
#define ull unsigned long long 

//高精度加法+区间最值问题 (树状数组/ST表)
 
int A[3005],B[3005];
int C1[3005],C2[3005];//树状数组 
int T,n,Q;
int lowbit(int e)
{
	return e&(-e);
}
int queryA(int e)
{
	int ans = 0;
	for(int k = e;k >= 1;k-=lowbit(k))
		ans = max(ans,C1[k]);
	return ans;
}
int queryB(int e)
{
	int ans = 0;
	for(int k = e;k >=1 ;k-=lowbit(k))
		ans = max(ans,C2[k]);
	return ans;
}
void updateA(int e,int v)
{
	for(int k = e;k <= n;k+=lowbit(k))
	{
		C1[k] = max(C1[k],v);
	}
}
void updateB(int e,int v)
{
	for(int k = e;k <= n;k+=lowbit(k))
	{
		C2[k] = max(C2[k],v);
	}
}
int getAm(int l,int r)
{
	int c = 0;
	for(int i = l;i <= r;i++)
		c = max(c,A[i]);
	return c;
}
int getBm(int l,int r)
{
	int c = 0;
	for(int i = l;i <= r;i++)
		c = max(c,B[i]);
	return c;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>A[i];
	}
	for(int i = 1;i <= n;i++)
		cin>>B[i];
	cin>>Q; 
	for(int q = 1;q <= Q;q++)
	{
		int l,r;
		cin>>l>>r;
		ull ans = 0;
		for(int p = l;p <= r;p++)
		{
			for(int q = p;q <= r;q++)
			{
				ans += getAm(p,q)*getBm(p,q);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

/*
versin 2
#include <iostream>
using namespace std;
#define ull unsigned long long 

//高精度加法+区间最值问题 (树状数组/ST表)
 
int A[3005],B[3005];
int C1[3005],C2[3005];//树状数组 
ull ansa[3005][3005];
int T,n,Q;
int lowbit(int e)
{
	return e&(-e);
}
int queryA(int l,int e)
{
	int ans = 0;
	for(int k = e;k >= 1;k-=lowbit(k))
		ans = max(ans,C1[k]);
	return ans;
}
int queryB(int l,int e)
{
	int ans = 0;
	for(int k = e;k >= 1;k-=lowbit(k))
		ans = max(ans,C2[k]);
	return ans;
}
void updateA(int e,int v)
{
	for(int k = e;k <= n;k+=lowbit(k))
	{
		if(C1[k]<v)
		{
			C1[k] = v;
		}
		else if(C1[k] > v)
		{
			C1[k] = max(queryA(1,k),v);
		}
	}
}
void updateB(int e,int v)
{
	for(int k = e;k <= n;k+=lowbit(k))
	{
		if(C2[k]<v)
		{
			C2[k] = v;
		}
		else if(C2[k] > v)
		{
			C2[k] = max(queryB(1,k),v);
		}
	}
}
int getAm(int l,int r)
{
	int c = 0;
	for(int i = l;i <= r;i++)
		c = max(c,A[i]);
	return c;
}
int getBm(int l,int r)
{
	int c = 0;
	for(int i = l;i <= r;i++)
		c = max(c,B[i]);
	return c;
}
int main()
{
	//freopen("match.in","r",stdin);
	//freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i = 1;i <= n;i++)
	{
		
		cin>>A[i];
		updateA(i,A[i]);
	}
	for(int i = 1;i <= n;i++)
	{ 
		cin>>B[i];
		updateB(i,B[i]);
	}
	cin>>Q;
	for(int p = 1;p <= n;p++)
	{
		for(int q = 1;q <= n;q++)
		{
			ansa[p][q] += queryA(p,q)*queryB(p,q);
		}
		updateA(p,0);
		updateB(p,0);
	}
	for(int q = 1;q <= Q;q++)
	{
		int l,r;
		cin>>l>>r;
		cout<<ansa[l][r]<<endl;
	}
	return 0;
} 
*/
