/*
Author:xwg
Time:2022.2.7
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
//priority_queue<int> h;//大根堆
//priority_queue<int, vector<int>, greater<int>> h;//小根堆
int n,x,op;

struct heap
{
    int cnt=0,tmp,h[300001];

    void build(int n)
    {
        for(int i=1;i<=2*n;++i)
        {
            h[i]=INT_MAX;
        }
    }

    inline int top()
    {
        return h[1];
    }

    inline void push(int x)
    {
        h[++cnt]=x;
        tmp=cnt;
        while(tmp>1)
        {
            if(h[tmp] < h[tmp/2])
            {
                swap(h[tmp], h[tmp/2]);
            } else return;
            tmp/=2;
        }
    }

    inline void pop()
    {
        h[1]=h[cnt--];
        tmp = 1;
        int net=tmp*2;
        while(net<=cnt)
        {
            if(net<cnt&&h[net+1]<h[net])
            {
                ++net;
            }
            if(h[tmp]<=h[net])
            {
                return;
            }
            swap(h[tmp], h[net]);
            tmp = net;
            net *= 2;
        }
    }
};

heap h;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&x);
            h.push(x);
        }
        if(op==2)
        {
            printf("%d\n",h.top());
        }
        if(op==3)
        {
            h.pop();
        }
    }
    return 0;
}