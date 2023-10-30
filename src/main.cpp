#include <iostream>
#include "./includes/queue.cpp"

int main(int argc, char *argv[])
{ 
    Queue<int> *q = new Queue<int>({1, 2, 3, 4, 5});

    for (unsigned i = 1; i <= 5; i++)
        q->dequeue();

    auto f = q->first().value_or(0);
    auto l = q->last().value_or(0);

    std::cout << f << ' ' << l;
}