#include <iostream>
 
class Parent
{
public:
    Parent() {
        std::cout << "Parent()\n";
    }
    ~Parent() {
        std::cout << "~Parent()\n";
    }
};
 
class Child: public Parent
{
public:
    Child() {
        std::cout << "Child()\n";
    }
    ~Child() {
        std::cout << "~Child()\n";
    }
};

int main()
{
    Child ch;
}

/*
    ����������: 
    � ������� main() ��������� �������������� ������ ch ������ Child, ������� ����������� �� ������ Parent. 
    ��� �������� ������� ������-������� ������� ���������� ����������� ������-�������� (Parent()), 
    � ����� ����������� ���������� (Child()). ����� ���� ������� �� ����������� ������� ������-�������, 
    �� ������� ���������� ���������� ������� (~Child()), � ����� ���������� �������� (~Parent()). 
    
    ���������:
    Parent()
    Child()
    ~Child()
    ~Parent()
*/