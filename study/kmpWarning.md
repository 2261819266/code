## KMP算法常见错误

* next 不明确
  
	```cpp
		#include <bits/stdc++.h>
		using namespace std;

		const int maxn = 1e5 + 8;
		int next[maxn];
	```
	> 用了万能头(或\<algorithms\>)和命名空间，使得 `next` 数组不明确
	> [next of "bits\stl_iterator_base_funcs.h"](./Screenshot%202022-01-26%20094502.png)