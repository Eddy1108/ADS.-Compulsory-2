#ifndef STACK_H
#define STACK_H
#include <iostream>

template<class T>
class Stack
{
public:
    Stack(T c = '0', Stack* next = nullptr);
    Stack<T>* getNext() const;
    void pop(Stack<T>* &ptr) const;
    Stack<T>* Push(T chr);
    static int getSize();
    T top() const;
    void printBackwards() const;
    bool empty();
    ~Stack();
private:
    T m_c = nullptr;
    static int s_stackSize;
    Stack<T>* m_Next;
    Stack<T>* m_top;
};

template <class T>
int Stack<T>::s_stackSize;

template <class T>
Stack<T>::Stack(T c, Stack<T>* next) : m_c(c), m_Next(next)
{
    s_stackSize ++;
    m_top = this;
}

template <class T>
Stack<T>* Stack<T>::getNext() const
{
    return m_Next;
}

template <class T>
void Stack<T>::pop(Stack<T>* &ptr) const
{
    Stack<T>* deletedPtr = ptr;
    ptr = ptr->getNext();
    delete deletedPtr;
    s_stackSize--;
}

template <class T>
Stack<T>* Stack<T>::Push(T chr)
{
    Stack<T>* tempPtr = new Stack<T> (chr, this);
    return tempPtr;
}

template<class T>
int Stack<T>::getSize()
{
    return s_stackSize;
}

template <class T>
Stack<T>::~Stack()
{
    s_stackSize--;
}

template<class T>
T Stack<T>::top() const
{
    return m_c;
}

template<class T>
void Stack<T>::printBackwards() const
{
        if(m_Next)
            m_Next->printBackwards();
        std::cout << m_c;
}

template<class T>
bool Stack<T>::empty()
{
    if (this == nullptr)
        return true;
    else
        return false;
}

#endif // STACK_H
