#include <iostream>
using namespace std;
#include <deque>
#include <algorithm> // 标准库算法

void printDeque(deque<int> &d)
{
    for (auto x : d)
    {
        cout << x << " ";
    }
    cout << endl;
}
// deque排序
void test01()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);
    // 对于支持随机访问迭代器的容器，都可以使用标准库算法
    sort(d1.begin(), d1.end()); // 升序, 默认从小到大
    printDeque(d1);
    sort(d1.begin(), d1.end(), greater<int>()); // 降序
    printDeque(d1);
}
int main()
{
    test01();
    return 0;
}