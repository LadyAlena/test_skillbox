#include <iostream>
 
class Parent
{
private:
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
 
int main()
{
    Child ch(7);
    ch.print();
}

/*
    ����������:
    � �������������� ���� ����� Child ����������� � ������������� public �� ������ Parent. ����� �������, �����
    Child ����� ������ � ����� � ������� ������ Parent, ������� ���������� � public- � protected- ������� ������������� ������. 
    ���� �������������� ���� m_x ������ Parent ����� ����������� ������� private,
    ������� � �������������� ������ Child ��� ���� ����� ����������. 
    � ������ print() ������-������� Child ����������� ������� ��������� � ���� m_x, ������ ��� ����������, 
    ��� �������� � ������ ����������.
    
    ���������: ������ ����������
*/