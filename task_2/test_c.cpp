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
    Объяснение:
    В представленном коде класс Child унаследован с модификатором public от класса Parent. Таким образом, класс
    Child имеет доступ к полям и методам класса Parent, которые определены в public- и protected- секциях родительского класса. 
    Поле целочисленного типа m_x класса Parent имеет модификатор доступа private,
    поэтому в унаследованном классе Child это поле будет недоступно. 
    В методе print() класса-потомка Child совершается попытка обращения к полю m_x, котрое ему недоступно, 
    что приводит к ошибке компиляции.
    
    Результат: Ошибка компиляции
*/