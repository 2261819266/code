/*  writer:yuxinhao  */
/*  creation date:2021/7/27  */
/*  updata date:2021/7/28  */
/*  edition:1.0  */

#include <cstdio>

// 定义坐标  图像
class coordinate {

  public:
    // 获取数据  d=>值  x,y=>(coordinate)[x][y]
    void push(int d, int x, int y) {}

    // 输出数据(数值)
    void printdata() const {}

    // 删除数据  x,y同"void push();"
    void pop(int x, int y) { state = false; }

    // 初始化状态
    coordinate() { state = false; }

  private:
    // 图像
    char node[4][4];

    // 名字
    int name;

    // 数值
    int data;

    // 状态  是否有数
    bool state;
};

// 创建总区域(游戏区域)
// 不用"a[0][0~4]"和"a[0~4][0]"
coordinate a[5][5];

// 记录分数
int score;

// 获取总区域内((coordinate)[5][5])有几个数据
int get_state_true_n() {}

// 判断一个数是否存在(数值)
bool judge_find_true_data(int d) {}

// 判断游戏是否结束
bool judge_AFO() {
    // return get_state_true_n() == 16 && judge_find_true_data(-1) &&
    // judge_find_true_data(-2) && judge_find_true_data(-4);
}

// 定义方向 vec[c][0]横轴  vec[c][1]纵轴
int vec[10][2];

// 格式化方向  方式一  =>  8上2下4左6右
void memvec1() {}

// 格式化方向  方式二  =>  1上2下3左4右
// void memvec2() {}

// ......

// 输出  数值
void printdata() {}

// 输出  名字
// void printname(){}
