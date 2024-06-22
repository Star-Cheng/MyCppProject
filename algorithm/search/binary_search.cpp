#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}
int binary_search(vector<int> &v, int search)
{
    int left = 0;
    int right = v.size() - 1;
    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (v[middle] > search)
            right = middle - 1;
        else if (v[middle] < search)
            left = middle + 1;
        else
            return middle;
    }
    return -1;
}

int main()
{
    vector<int> v;
    v.push_back(-1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(5);
    v.push_back(9);
    v.push_back(12);
    printVector(v);
    cout << binary_search(v, 9) << endl;
}