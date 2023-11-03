#include "test-module.h"
#include <iostream>

TestModule::TestModule(): tl() {}

TestModule::TestModule(const std::initializer_list<int>& init_list): tl{init_list} {};

void TestModule::test(size_t lim)
{
    std::cout << "Result of is_empty(): " << tl.is_empty() << '\n';
    std::cout << "Result of is_full(): " << tl.is_full() << '\n';

    for (unsigned i = 0; i < lim; ++i)
        tl.add(i);

    std::cout << "first(): " << tl.first().value_or(-1) << '\n';
    std::cout << "last(): " << tl.last().value_or(-1) << '\n';

    std::cout << "calling advance()...\n";
    tl.advance();

    std::cout << "first(): " << tl.first().value_or(-1) << '\n';
    std::cout << "last(): " << tl.last().value_or(-1) << '\n';

    std::cout << "calling make_empty()...\n";
    tl.make_empty();

    std::cout << "Result of is_empty(): " << tl.is_empty() << '\n';
    std::cout << "Result of is_full(): " << tl.is_full() << '\n';
}