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
    Объяснение: 
    В функции main() создается автоматический объект ch класса Child, который унаследован от класса Parent. 
    При создании объекта класса-потомка сначала вызывается конструктор класса-родителя (Parent()), 
    а потом конструктор наследника (Child()). Когда дело доходит до уничтожения объекта класса-потомка, 
    то сначала вызывается деструктор потомка (~Child()), а потом деструктор родителя (~Parent()). 
    
    Результат:
    Parent()
    Child()
    ~Child()
    ~Parent()
*/