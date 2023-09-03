# 线段树注意事项

## [线段树模板1](https://www.luogu.com.cn/problem/P3372)

### 早期版本

#### [0.0.1](https://www.luogu.com.cn/record/62009928)
* `void add(...)`也要传递`lazy`标签
* 传递`lazy`标签时要更新父节点


### 0.0版本：

* 修改后要 __更新__ 父节点的值
	> `void pushdown(int k, int l, int r)`  
	> `void add(int k, int l, int r, int L, int R, int x)`  
	> `void modify(int k, int l, int r, int L, int R)`

### 1.0版本：

* 数组大小至少为 `maxn << 2` ( `maxn * 4` )
	> `node a[maxn << 2];`  
	> `ll a[maxn << 2], lazy[maxn << 2], sum[maxn << 2];`

### 2.0版本：

	
* 由于没有lazy标记，所以 __`add` 也要 `pushdown`__
```cpp
	ll add(int k, int l, int r, int L, int R, int x) {
		if (l >= L && r <= R) return a[k] += x * num;
		if (l > R || L > r) return 0;
		Def
		add(Ls, L, R, x), add(Rs, L, R, x);
		return updata
	}
```

### [3.0版本（最终版本）（正式版）](https://www.luogu.com.cn/paste/5a347tau)
* `sum` 和 `lazy` 在 `add` 时 __都要更新__
	> `sum[k] += x * (r - l + 1);`  
	> `lazy[k] += (r - l + 1);`

## [线段树模板2](https://www.luogu.com.cn/problem/P3373)

### [3.1版本](https://www.luogu.com.cn/paste/r2on2a0k)
* `lazy_add` 在 `pass` 时也要乘 `lazy_mul`
	> `b[ls] = (b[ls] * c[k]) % p;`  
	> `b[rs] = (b[rs] * c[k]) % p;` 

* 一开始修改节点时也要开 `long long`
	> `ll x;`  
	> `scanf("%lld", &x);`  
	> `sgt.modify(1, 1, n, i, x);`  
	>> `ll SegTree::modify(int k, int l, int r, int i, ll x);`

