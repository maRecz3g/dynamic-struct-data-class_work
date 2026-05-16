#pragma once
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
struct Node
{
    T data;
    Node* next;

    Node(const T& data = T(), Node* next = nullptr)
        : data(data), next(next) {
    }
};

template <typename T>
class FwList
{
public:
    FwList() = default;

    // Конструктор копіювання
    FwList(const FwList& other);

    // Оператор присвоєння
    FwList& operator=(const FwList& other);

    // Деструктор
    ~FwList();

    void addHead(const T& data);
    void addTail(const T& data);

    void removeHead();
    void removeAt(const T& value);

    void clear();

    void print() const;

    bool isEmpty() const;

private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    size_t size = 0;
};

template<typename T>
void FwList<T>::addHead(const T& data)
{
    auto tmp = new Node<T>(data, head);

    if (isEmpty())
        tail = tmp;

    head = tmp;
    ++size;
}

template<typename T>
void FwList<T>::addTail(const T& data)
{
    auto tmp = new Node<T>(data);

    if (isEmpty())
    {
        head = tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
    }

    ++size;
}

template<typename T>
void FwList<T>::removeHead()
{
    if (isEmpty())
        return;

    auto tmp = head;
    head = head->next;

    delete tmp;
    --size;

    if (isEmpty())
        tail = nullptr;
}

template<typename T>
void FwList<T>::removeAt(const T& value)
{
    if (isEmpty())
        return;

    // Якщо видаляємо голову
    if (head->data == value)
    {
        removeHead();
        return;
    }

    auto current = head;

    while (current->next != nullptr &&
        current->next->data != value)
    {
        current = current->next;
    }

    // Не знайдено
    if (current->next == nullptr)
        return;

    auto toDelete = current->next;

    current->next = toDelete->next;

    // Якщо видаляємо tail
    if (toDelete == tail)
        tail = current;

    delete toDelete;
    --size;
}

template<typename T>
void FwList<T>::clear()
{
    while (!isEmpty())
    {
        removeHead();
    }
}

template<typename T>
FwList<T>::~FwList()
{
    clear();
}

template<typename T>
FwList<T>::FwList(const FwList& other)
{
    auto tmp = other.head;

    while (tmp != nullptr)
    {
        addTail(tmp->data);
        tmp = tmp->next;
    }
}

template<typename T>
FwList<T>& FwList<T>::operator=(const FwList& other)
{
    if (this == &other)
        return *this;

    clear();

    auto tmp = other.head;

    while (tmp != nullptr)
    {
        addTail(tmp->data);
        tmp = tmp->next;
    }

    return *this;
}

template<typename T>
void FwList<T>::print() const
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }

    auto tmp = head;

    cout << "List:\t";

    while (tmp != nullptr)
    {
        cout << tmp->data << "\t";
        tmp = tmp->next;
    }

    cout << endl;
}

template<typename T>
bool FwList<T>::isEmpty() const
{
    return head == nullptr;
}