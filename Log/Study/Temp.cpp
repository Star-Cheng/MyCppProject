#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 常用排序算法reverse
void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}
void test01()
{
    srand(time(NULL));
    vector<int> v1;
    for (int i = 0; i < 10; i++)
        v1.push_back(i);
    cout << "反转前: " << endl;
    printVector(v1);
    cout << "反转后: " << endl;
    reverse(v1.begin(), v1.end());
    printVector(v1);
}
int main()
{
    test01();
    return 0;
}