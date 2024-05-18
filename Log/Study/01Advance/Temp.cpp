#include <iostream>
using namespace std;
#include <string>

class Cube
{
private:
    int m_length;
    int m_width;
    int m_height;

public:
    void set_length(int length)
    {
        m_length = length;
    }
    int get_length()
    {
        return m_length;
    }
    void set_width(int width)
    {
        m_width = width;
    }
    int get_width()
    {
        return m_width;
    }
    void set_height(int height)
    {
        m_height = height;
    }
    int get_height()
    {
        return m_height;
    }
    int get_calculateS()
    {
        return 2 * (m_length * m_width + m_width * m_height + m_height * m_length);
    }
    int get_caluculateV()
    {
        return m_length * m_width * m_height;
    }
    bool isSameByClass(Cube &c)
    {
        if (c.get_length() == m_length && c.get_width() == m_width && c.get_height() == m_height)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
bool isSame(Cube c1, Cube c2)
{
    if (c1.get_length() == c2.get_length() && c1.get_width() == c2.get_width() && c1.get_height() == c2.get_height())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Cube c1;
    c1.set_length(10);
    c1.set_width(10);
    c1.set_height(10);
    cout << "length: " << c1.get_length() << endl;
    cout << "width: " << c1.get_width() << endl;
    cout << "height: " << c1.get_height() << endl;
    cout << "surface area: " << c1.get_calculateS() << endl;
    cout << "volume: " << c1.get_caluculateV() << endl;
    Cube c2;
    c2.set_length(10);
    c2.set_width(10);
    c2.set_height(10);
    cout << "is_same: " << isSame(c1, c2) << endl;
    cout << "is_same: " << c1.isSameByClass(c2) << endl;
    return 0;
}