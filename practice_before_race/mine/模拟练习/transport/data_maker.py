from cyaron import *
import numpy as np
import random
import math
maxn = 1000000
q = 100
_n = ati([0, 2E3, 5E3, 1E6, 1E6])
_m = ati([0, 1E5, 1E5, 1E5, 1E5])
_d = ati([0, 10, 1E6])
cur = 1
def fun () :
    x = randint(1, 2)
    if x % 2 == 1 :
        return 'S'
    else :
        return 'T'

for i in range (1, 21) :
    t = IO(file_prefix = "transport", data_id = i) # 输入文件前缀
    if i == 3 :
        cur = cur + 1
    n = _n[cur]
    t.input_writeln(n)
    for i in range(1, n + 1) :
        x = randint(-maxn, maxn)
        y = randint(-maxn, maxn)
        t.input_writeln(x, y)
    t.output_gen(r"C:\Users\xiaoy\Desktop\Tools\Program\20210806-A组\transport\transport.exe") # 输入文件路径