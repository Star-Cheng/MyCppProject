#include <iostream>
using namespace std;
#include <vector>

// vector预留空间
void printVector(vector<int> &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
void test01()
{
    vector<int> v;
    // 利用reserve提前指定容器的容量
    v.reserve(100000);
    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << "capacity:" << v.capacity() << endl;
    cout << "size:" << v.size() << endl;
    cout << num << endl;
}

int main()
{
    test01();
    return 0;
}