#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 常用集合算法set_difference
void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}
void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i * i);
    }
    printVector(v1);
    printVector(v2);
    vector<int> vTarget1;
    vector<int> vTarget2;
    cout << "v1和v2的差集为: " << endl;
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(vTarget1));
    printVector(vTarget1);
    cout << "v1和v2的差集为: " << endl;
    set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), back_inserter(vTarget2));
    printVector(vTarget2);
}
int main()
{
    test01();
    return 0;
}