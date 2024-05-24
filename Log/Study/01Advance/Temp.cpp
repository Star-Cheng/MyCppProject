#include <iostream>
using namespace std;

// 动物类
class Animal
{
public:
    int m_Age;
};
// 利用虚继承解决菱形继承问题
// 继承之前加上关键字virtual
// Animal类称为虚基类
// 羊类
class Sheep : virtual public Animal
{
};
// 驼类
class Horse : virtual public Animal
{
};
// 羊驼类
class SheepHorse : public Sheep, public Horse
{
};
void test01()
{
    SheepHorse s;
    s.Sheep::m_Age = 20;
    s.Horse::m_Age = 30;
    // 当菱形继承, 当两个父类拥有相同数据, 需要加以作用域区分
    cout << "s.Sheep::m_Age = " << s.Sheep::m_Age << endl;
    cout << "s.Horse::m_Age = " << s.Horse::m_Age << endl;
    cout << "s.m_Age = " << s.m_Age << endl;
    // m_Age我们只需要一份就可以了, 菱形继承导致数据有两份, 资源浪费
}
main()
{
    test01();
    return 0;
}