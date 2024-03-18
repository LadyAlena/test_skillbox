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
 
        // Обратите внимание, здесь нет метода print()
};
 
int main()
{
    D2 d(7);
    d.print();
}

/*
    Объяснение: 
    В данном коде класс D2 унаследован с модификатором доступа public от класса Child, который в свою очередь
    публично унаследован от класса Parent. При этом класс D2 унаследовал переопределенный метод print() от класса
    Child, который определен в public-секции. Таким образом, при вызове у объекта класса D2 метода print()
    будет вызван метод print() класса Child.

    Поле m_x находится в protected-секции класса Parent, поэтому при публичном наследовании классов Child и D2 
    это поле будет в них доступно с модификатором доступа protected.

    В функции main() создается автоматический объект d с параметром 7, 
    значением которого будет проинициализировано поле m_x (Parent() Child() D2()). Далее у объекта d вызывается метод print(), который
    печатает имя класса Child и значение поля m_x (Child: 7). При выходе из функции main() объект d уничтожается (~D2() ~Child() ~Parent()).

    Результат:
    Parent()
    Child()
    D2()
    Child: 7
    ~D2()
    ~Child()
    ~Parent()
*/