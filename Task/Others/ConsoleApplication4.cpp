#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;

// 冒泡排序
void bubbleSort(vector<int>& arr, long long& comparisons, long long& moves) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++; // 比较次数加1
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                moves++; // 移动次数加1
            }
        }
    }
}

// 简单选择排序
void selectionSort(vector<int>& arr, long long& comparisons, long long& moves) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            comparisons++; // 记录比较次数
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        moves += 3; // 记录移动次数（swap操作需要3次移动）
    }
}

// 直接插入排序
void insertionSort(vector<int>& arr, long long& comparisons, long long& moves) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++; // 记录比较次数
            arr[j + 1] = arr[j];
            moves++; // 记录移动次数
            --j;
        }
        arr[j + 1] = key;
        moves++; // 记录移动次数
    }
}


// 快速排序
void quickSort(vector<int>& arr, int low, int high, long long& comparisons, long long& moves) {
    if (low < high) {
        int pivot = partition(arr, low, high, comparisons, moves);
        quickSort(arr, low, pivot - 1, comparisons, moves);
        quickSort(arr, pivot + 1, high, comparisons, moves);
    }
}

int partition(vector<int>& arr, int low, int high, long long& comparisons, long long& moves) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
            moves++;
        }
        comparisons++;
    }
    swap(arr[i + 1], arr[high]);
    moves++;
    return i + 1;
}


// 堆排序
void heapify(vector<int>& arr, int n, int i, long long& comparisons, long long& moves) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        moves++;
        heapify(arr, n, largest, comparisons, moves);
    }
}

// 希尔排序
void shellSort(vector<int>& arr, long long& comparisons, long long& moves) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparisons++;
                arr[j] = arr[j - gap];
                moves++;
            }
            arr[j] = temp;
            moves++;
        }
    }
}


// 归并排序
void merge(vector<int>& arr, int l, int m, int r, long long& comparisons, long long& moves) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        comparisons++;
        moves++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        moves++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        moves++;
    }
}

void mergeSort(vector<int>& arr, int l, int r, long long& comparisons, long long& moves) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparisons, moves);
        mergeSort(arr, m + 1, r, comparisons, moves);
        merge(arr, l, m, r, comparisons, moves);
    }
}




int main() {
    // 生成随机数据
    vector<int> data;
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 100; ++i) {
        data.push_back(rand() % 100);
    }

    // 生成随机数据
    vector<int> data10, data10000, data100000;
    for (int i = 0; i < 10000; ++i) {
        int num = rand() % 10000;
        data10.push_back(num);
        data10000.push_back(num);
        // data100000.push_back(num);
    }

    // 冒泡排序
    // 记录关键字比较次数和移动次数
    long long comparisons = 0;
    long long moves = 0;

    // 测试排序算法并记录执行时间
    auto start_time = chrono::high_resolution_clock::now();
    // 调用排序算法
    bubbleSort(data10000, comparisons, moves);
    // selectionSort(data, comparisons, moves);
    // insertionSort(data10000, comparisons, moves);
    auto end_time = chrono::high_resolution_clock::now();



    chrono::duration<double> elapsed_time = end_time - start_time;
    // 输出关键字比较次数、移动次数和执行时间
    cout << "Comparisons: " << comparisons << endl;
    cout << "Moves: " << moves << endl;
    cout << "Execution Time: " << elapsed_time.count() << " seconds" << endl;

    // 插入排序
    // 记录关键字比较次数和移动次数
    long long comparisons2 = 0;
    long long moves2 = 0;

    // 测试排序算法并记录执行时间
    auto start_time2 = chrono::high_resolution_clock::now();
    // 调用排序算法
    // bubbleSort(data, comparisons, moves);
    // selectionSort(data, comparisons2, moves);
    insertionSort(data10000, comparisons2, moves2);
    auto end_time2 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time2 = end_time2 - start_time2;
    // 输出关键字比较次数、移动次数和执行时间
    cout << "Comparisons: " << comparisons2 << endl;
    cout << "Moves: " << moves2 << endl;
    cout << "Execution Time: " << elapsed_time2.count() << " seconds" << endl;



    return 0;
}
