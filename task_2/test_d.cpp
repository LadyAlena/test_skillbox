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
 
int main()
{
    Child ch(7);
    ch.print();
}

/*
    Объяснение:
    В данном коде класс Child унаследован с модификатором public от класса Parent. Таким образом, класс
    Child имеет доступ к полям и методам класса Parent, которые определены в public- и protected- секциях родительского класса. 
    Поле целочисленного типа m_x класса Parent имеет модификатор доступа protected,
    поэтому в унаследованном классе Child это поле будет доступно и иметь модификатор доступа protected. 
    Метод print() класса Parent() находится в public-секции, поэтому этот метод также будет доступен в классе Child с модификатором доступа public.
    В функции main() создается автоматический объект ch (сначала вызывается конструктор Parent() с параметром 7, 
    значение которого инициализирует поле m_x в списке инициализации, а затем конструктор Child()). Далее у объекта ch вызывется публичный
    метод print(), который выводит в консоль имя класса и значение поля m_x (Child: 7). При выходе из области видимости функции main() объект ch уничтожается (~Child(), ~Parent()).
    
    Результат:
    Parent()
    Child()
    Child: 7
    ~Child()
    ~Parent()
*/