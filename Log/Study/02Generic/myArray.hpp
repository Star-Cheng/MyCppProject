#pragma
#include <iostream>
using namespace std;
#include <string>

template <class T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        cout << "MyArray有参构造调用" << endl;
        this->m_capacity = capacity;
        this->m_size = 0;
        this->pAddress = new T[this->m_capacity];
    }
    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        cout << "MyArray拷贝构造调用" << endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[arr.m_capacity];
        // 拷贝数组元素
        for (int i = 0; i < this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    // operator=防止浅拷贝
    MyArray &operator=(const MyArray &arr)
    {
        cout << "MyArray operator=调用" << endl;
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_size = 0;
            this->m_capacity = 0;
        }
        // 深拷贝
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[arr.m_capacity];
        // 拷贝数组元素
        for (int i = 0; i < this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }
    // 尾差法
    void Push_Back(const T &val)
    {
        if (this->m_size == this->m_capacity)
        {
            return;
        }
        this->pAddress[this->m_size] = val;
        this->m_size++;
    }
    // 尾删法
    void Pop_Back()
    {
        // 让用户访问不到最后一个元素, 逻辑上删除
        if (this->m_size == 0)
        {
            return;
        }
        this->m_size--;
    }
    // 通过下标访问元素
    T &operator[](int index)
    {
        return this->pAddress[index];
    }
    // 返回数组容量
    int Capacity()
    {
        return this->m_capacity;
    }
    // 返回数组大小
    int Size()
    {
        return this->m_size;
    }
    // 析构函数
    ~MyArray()
    {
        cout << "MyArray析构调用" << endl;
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T *pAddress;    // 指针指向堆区开辟的真是数组
    int m_capacity; // 数组容量
    int m_size;     // 数组大小
};