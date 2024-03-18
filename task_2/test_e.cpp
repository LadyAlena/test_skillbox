#include <iostream>
 
class Parent
{
protected:
    int m_x;
public:
    Parent(int x): m_x(x)
    {
        std::cout << "Parent()\n";
    }
    ~Parent()
    {
        std::cout << "~Parent()\n";
    }
 
    void print() { std::cout << "Parent: " << m_x << '\n';  }
};
 
class Child: public Parent
{
public:
    Child(int y):  Parent(y)
    {
        std::cout << "Child()\n";
    }
    ~Child()
    {
        std::cout << "~Child()\n";
    }
 
    void print() { std::cout << "Child: " << m_x << '\n'; }
};
 
class D2 : public Child
{
public:
    D2(int z): Child(z)
    {
        std::cout << "D2()\n";
    }
    ~D2()
    {
        std::cout << "~D2()\n";
    }
 
        // �������� ��������, ����� ��� ������ print()
};
 
int main()
{
    D2 d(7);
    d.print();
}

/*
    ����������: 
    � ������ ���� ����� D2 ����������� � ������������� ������� public �� ������ Child, ������� � ���� �������
    �������� ����������� �� ������ Parent. ��� ���� ����� D2 ����������� ���������������� ����� print() �� ������
    Child, ������� ��������� � public-������. ����� �������, ��� ������ � ������� ������ D2 ������ print()
    ����� ������ ����� print() ������ Child.

    ���� m_x ��������� � protected-������ ������ Parent, ������� ��� ��������� ������������ ������� Child � D2 
    ��� ���� ����� � ��� �������� � ������������� ������� protected.

    � ������� main() ��������� �������������� ������ d � ���������� 7, 
    ��������� �������� ����� ������������������� ���� m_x (Parent() Child() D2()). ����� � ������� d ���������� ����� print(), �������
    �������� ��� ������ Child � �������� ���� m_x (Child: 7). ��� ������ �� ������� main() ������ d ������������ (~D2() ~Child() ~Parent()).

    ���������:
    Parent()
    Child()
    D2()
    Child: 7
    ~D2()
    ~Child()
    ~Parent()
*/