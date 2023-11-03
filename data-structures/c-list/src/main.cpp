#include <iostream>
#include "includes/c-list.h"
#include "includes/test-module.h"

int main(int argc, char *argv[])
{
    Clist<int> cl1{1, 2, 3, 4, 5}, cl2{6, 12, 18, 24, 30};
    std::cout << cl1.first().value_or(0);
    cl1 = cl2;
    std::cout << cl1.first().value_or(0);
    return 0;
}
