#include "queue.h"

template<typename T>
Queue<T>::Queue(): front{nullptr}, rear{nullptr}{}

template<typename T>
Queue<T>::Queue(const std::initializer_list<T>& init_list)
{
    for (const T& val : init_list)
        this->enqueue(val);
}

template<typename T>
void Queue<T>::enqueue(const T& item)
{
    Node<T> *new_node = new Node<T>;
    new_node->data = item;

    if (front == nullptr & rear == nullptr)
    {
        front = new_node;
        rear = front;
        front->next = rear;
        return;
    }

    if (front == rear)
    {
        rear = new_node;
        front->next = rear;
        rear->next = front;
        return;
    }

    rear->next = new_node;
    rear = new_node;
    rear->next = front;
}

template<typename T>
void Queue<T>::dequeue(void)
{
    if (is_empty())
        return;

    Node<T> *del = front;

    if (front == rear)
    {
        front = rear = nullptr;
        return;
    }

    front = front->next;
    delete del;
}


template<typename T>
bool Queue<T>::is_empty(void) const 
{
    return front == nullptr && rear == nullptr;
}

template<typename T>
bool Queue<T>::is_full(void) const 
{
    try
    {
        Node<T> *new_node = new Node<T>;
        delete new_node;
        return false;
    }
    catch(const std::bad_alloc& e)
    {
        return true;
    }
}

template<typename T>
std::optional<const T> Queue<T>::first(void) const
{
    return is_empty() ? std::nullopt : std::optional<const T>{front->data};
}

template<typename T>
std::optional<const T> Queue<T>::last(void) const
{
    return is_empty() ? std::nullopt : std::optional<const T>{rear->data};
}
