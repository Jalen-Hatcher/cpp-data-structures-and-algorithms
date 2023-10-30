#include <initializer_list>
#include <optional>

template<typename T>
struct Node
{
    Node<T> *next{nullptr};
    T data;
};

template<typename T>
class Queue
{
private:
    Node<T> *front, *rear;
public:
    Queue();
    Queue(const std::initializer_list<T>&);
    void enqueue(const T&);
    void dequeue(void);
    bool is_empty(void) const;
    bool is_full(void) const;
    std::optional<const T> first(void) const;
    std::optional<const T> last(void) const;
};