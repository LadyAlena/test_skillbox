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
    Объяснение: 
    В функции main() создаются два автоматических объекта: ch класса Child и p класса Parent.
    Автоматические объекты создаются на стеке (принцип LIFO: последний зашел - первый вышел). Сначала создается объект ch (вызывается конструктор
    родителя Parent(), а потом конструктор наследника Child()), а потом объект p (вызывается конструктор Parent()).
    При уничтожении автоматические объекты удаляются в порядке, который противоположен порядку создания. То есть сначала 
    уничтожается объект p (~Parent()), а потом объект ch (~Child(), ~Parent()).
    
    Результат:
    Parent()
    Child()
    Parent()
    ~Parent()
    ~Child()
    ~Parent()
*/