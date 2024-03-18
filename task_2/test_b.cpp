#include <iostream>
 
class Parent
{
public:
    Parent()
    {
        std::cout << "Parent()\n";
    }
    ~Parent()
    {
        std::cout << "~Parent()\n";
    }
};
 
class Child: public Parent
{
public:
    Child()
    {
        std::cout << "Child()\n";
    }
    ~Child()
    {
        std::cout << "~Child()\n";
    }
};
 
int main()
{
    Child ch;
    Parent p;
}

/*
    ����������: 
    � ������� main() ��������� ��� �������������� �������: ch ������ Child � p ������ Parent.
    �������������� ������� ��������� �� ����� (������� LIFO: ��������� ����� - ������ �����). ������� ��������� ������ ch (���������� �����������
    �������� Parent(), � ����� ����������� ���������� Child()), � ����� ������ p (���������� ����������� Parent()).
    ��� ����������� �������������� ������� ��������� � �������, ������� �������������� ������� ��������. �� ���� ������� 
    ������������ ������ p (~Parent()), � ����� ������ ch (~Child(), ~Parent()).
    
    ���������:
    Parent()
    Child()
    Parent()
    ~Parent()
    ~Child()
    ~Parent()
*/