#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;

// 冒泡排序
void bubbleSort(vector<int>& arr, long long& comparisons, long long& moves) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            comparisons++; // 记录比较次数
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                moves += 3; // 记录移动次数（swap操作需要3次移动）
            }
        }
    }
}

// 简单选择排序
void selectionSort(vector<int>& arr, int& comparisons, int& moves) {
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
void insertionSort(vector<int>& arr, int& comparisons, int& moves) {
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
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// 堆排序
void heapify(vector<int>& arr, int n, int i) {
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
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 希尔排序
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 归并排序
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// 折半插入排序
void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int low = 0;
        int high = i - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        for (int j = i - 1; j >= low; --j) {
            arr[j + 1] = arr[j];
        }
        arr[low] = key;
    }
}

// 基数排序
int getMax(vector<int>& arr) {
    int max = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


// ... 其他排序算法的实现

int main() {
    // 生成随机数据
    vector<int> data;
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 100; ++i) {
        data.push_back(rand() % 1000);
    }

    // 生成随机数据
    vector<int> data10, data10000, data100000;
    for (int i = 0; i < 100000; ++i) {
        int num = rand() % 100000;
        data10.push_back(num);
        data10000.push_back(num);
        data100000.push_back(num);
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
    
    // // 插入排序
    // // 记录关键字比较次数和移动次数
    // int comparisons2 = 0;
    // int moves2 = 0;

    // // 测试排序算法并记录执行时间
    // auto start_time2 = chrono::high_resolution_clock::now();
    // // 调用排序算法
    // // bubbleSort(data, comparisons, moves);
    // // selectionSort(data, comparisons2, moves);
    // insertionSort(data10000, comparisons2, moves2);
    // auto end_time2 = chrono::high_resolution_clock::now();
    // chrono::duration<double> elapsed_time2 = end_time2 - start_time2;
    // // 输出关键字比较次数、移动次数和执行时间
    // cout << "Comparisons: " << comparisons2 << endl;
    // cout << "Moves: " << moves2 << endl;
    // cout << "Execution Time: " << elapsed_time2.count() << " seconds" << endl;



    return 0;
}
