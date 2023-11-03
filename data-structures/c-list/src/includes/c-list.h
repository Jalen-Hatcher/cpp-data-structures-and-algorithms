#ifndef __CLIST_H
#define __CLIST_H

#include <optional>
#include <string>
#include <initializer_list>

template<typename T>
struct Node
{
    T data{};
    Node<T> *next{nullptr};
};

template<typename T>
class Clist
{
private:
    Node<T> *cursor;
public:
    //Constructors/destructors
    Clist();
    Clist(const std::initializer_list<T>&);
    ~Clist();

    //Observer member functions
    inline bool is_empty(void) const;
    bool is_full(void) const;
    std::optional<const T> first(void) const; //return element after the cursor
    std::optional<const T> last(void) const; //return element at the cursor

    //Mutator member functions
    void advance();
    void add(const T&);
    void remove(void);
    void make_empty(void);

    //misc
    Clist<T>& operator =(const Clist<T>&);
};

template<typename T>
Clist<T>::Clist(): cursor{nullptr} {}

template<typename T>
Clist<T>::Clist(const std::initializer_list<T>& init_list)
{
    for (const T& itr: init_list)
        add(itr);
}

template<typename T>
Clist<T>::~Clist()
{
    while (!is_empty()) 
        remove();
}

template<typename T>
inline bool Clist<T>::is_empty(void) const
{
    return cursor == nullptr;
}

template<typename T>
bool Clist<T>::is_full(void) const
{
    try
    {
        Clist<T> *nl = new Clist<T>();
        delete nl;
        return false;
    }
    catch(const std::bad_alloc& e)
    {
        return true;
    }
        
}

template<typename T>
std::optional<const T> Clist<T>::first(void) const
{
    return cursor == nullptr ?
        std::nullopt : std::optional<const T>(cursor->next->data);
}

template<typename T>
std::optional<const T> Clist<T>::last(void) const
{
    return cursor == nullptr ?
        std::nullopt : std::optional<const T>(cursor->data);
}

template<typename T>
void Clist<T>::advance()
{
    if (is_empty())
        throw ("List is empty!");
    cursor = cursor->next;
}

template<typename T>
void Clist<T>::add(const T& item)
{
    Node<T> *new_node = new Node<T>;
    new_node->data = item;

    if (cursor == nullptr)
    {
        new_node->next = new_node;
        cursor = new_node;
        return;
    }

    new_node->next = cursor->next;
    cursor->next = new_node;
}

template<typename T>
void Clist<T>::remove(void)
{
    Node<T> *old = cursor->next;

    if (cursor == old)
        cursor = nullptr;
    else
        cursor->next = old->next;

    delete old;  
}

template<typename T>
void Clist<T>::make_empty(void)
{
    while (cursor != nullptr)
        remove();
}

// !NOTE! needs refining
template<typename T>
Clist<T>& Clist<T>::operator=(const Clist<T>& other)
{
    if (this == &other)
        return *this;

    this->make_empty();

    Node<int> *ref = other.cursor, *itr = ref;
    do
    {
        this->add(itr->data);
        itr = itr->next;
    } while (itr != ref);

    return *this;
}
#endif
