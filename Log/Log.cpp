#include <iostream>
#include <string>

class MyInteger
{
public:
    friend std::ostream &operator<<(std::ostream &cout, const MyInteger &myinst);
    MyInteger()
    {
        m_Num = 0;
    }
    MyInteger &operator++()
    {
        m_Num++;
        return *this;
    }
    MyInteger operator++(int)
    {
        MyInteger temp = *this;
        m_Num++;
        return temp;
    }

private:
    int m_Num;
};

std::ostream &operator<<(std::ostream &cout, const MyInteger &my_data)
{
    cout << my_data.m_Num;
    return cout;
}

void test01()
{
    MyInteger myinst;
    std::cout << ++myinst << std::endl;
    std::cout << myinst << std::endl;
}

void test02()
{
    MyInteger myinst;
    std::cout << myinst++ << std::endl;
    std::cout << myinst << std::endl;
}

int main()
{
    test01();
    test02();
    return 0;
}