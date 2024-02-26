#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;

// 冒泡排序
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 简单选择排序
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 直接插入排序
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// ... 其他排序算法的实现

int main() {
    // 生成随机数据
    vector<int> data;
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 100; ++i) {
        data.push_back(rand() % 1000);
    }

    // 测试排序算法并记录执行时间
    auto start_time = chrono::high_resolution_clock::now();
    
    // 调用排序算法
    bubbleSort(data);
    // selectionSort(data);
    // insertionSort(data);
    // ...

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time = end_time - start_time;

    // 输出执行时间
    cout << "Execution Time: " << elapsed_time.count() << " seconds" << endl;
    
    return 0;
}
