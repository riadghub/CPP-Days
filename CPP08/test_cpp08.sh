#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
GRAY='\033[0;90m'
NC='\033[0m'

print_ok()   { echo -e "[$GREEN OK $NC] $1"; }
print_fail() { echo -e "[$RED FAIL $NC] $1"; }

check_forbidden() {
    file=$1
    if grep -E "using namespace" "$file" >/dev/null; then
        print_fail "Forbidden: using namespace in $file"
    fi
    if grep -E "malloc|free|printf|calloc|realloc" "$file" >/dev/null; then
        print_fail "Forbidden C function in $file"
    fi
}

echo -e "${GRAY}=== CPP08 AUTO TEST SCRIPT ===${NC}"
echo

##########################################
# Test ex00
##########################################
echo -e "${GRAY}--- Testing ex00 ---${NC}"
cd ex00 || exit 1

# Forbidden checks
for f in *.cpp *.hpp; do
    check_forbidden "$f"
done

# Compilation
make re >/dev/null 2>&1
if [[ $? -ne 0 ]]; then
    print_fail "ex00 does not compile"
else
    print_ok "ex00 compiles"
fi

# Run tests
output=$(./easyfind 2>/dev/null)
if [[ $? -ne 0 ]]; then
    print_fail "ex00 program crashed or threw incorrect exceptions"
else
    print_ok "ex00 runs"
fi

cd ..

##########################################
# Test ex01
##########################################
echo -e "${GRAY}--- Testing ex01 ---${NC}"
cd ex01 || exit 1

# Forbidden checks
for f in *.cpp *.hpp; do
    check_forbidden "$f"
done

make re >/dev/null 2>&1
if [[ $? -ne 0 ]]; then
    print_fail "ex01 does not compile"
else
    print_ok "ex01 compiles"
fi

# Run tests
output=$(./span 2>/dev/null)
if [[ $? -ne 0 ]]; then
    print_fail "ex01 runtime error"
else
    print_ok "ex01 runs"
fi

# Additional Span test
echo "Testing Span with 20k numbers..."
cat <<EOF > span_test.cpp
#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    Span sp(20000);
    for (int i = 0; i < 20000; i++)
        sp.addNumber(rand());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}
EOF

c++ -std=c++98 -Wall -Wextra -Werror span_test.cpp Span.cpp -o span_test

if [[ $? -ne 0 ]]; then
    print_fail "Span large test failed to compile"
else
    ./span_test >/dev/null 2>&1
    if [[ $? -ne 0 ]]; then
        print_fail "Span failed large test (20k numbers)"
    else
        print_ok "Span handles 20k numbers successfully"
    fi
fi

cd ..

##########################################
# Test ex02
##########################################
echo -e "${GRAY}--- Testing ex02 ---${NC}"
cd ex02 || exit 1

# Forbidden checks
for f in *.cpp *.hpp; do
    check_forbidden "$f"
done

make re >/dev/null 2>&1
if [[ $? -ne 0 ]]; then
    print_fail "ex02 does not compile"
else
    print_ok "ex02 compiles"
fi

output=$(./mutant 2>/dev/null)
if [[ $? -ne 0 ]]; then
    print_fail "ex02 runtime error"
else
    print_ok "ex02 runs"
fi

# Extended iterator tests
echo "Testing extended iterator behavior..."
cat <<EOF > mtest.cpp
#include "MutantStack.hpp"
#include <iostream>
int main() {
    MutantStack<int> ms;
    for (int i = 0; i < 50; i++) ms.push(i);

    // forward iteration
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        if (*it < 0) return 1;

    // reverse iteration
    for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend(); ++it)
        if (*it < 0) return 1;

    return 0;
}
EOF

c++ -std=c++98 -Wall -Wextra -Werror mtest.cpp -o mtest
./mtest >/dev/null 2>&1
if [[ $? -ne 0 ]]; then
    print_fail "extended iterator tests failed"
else
    print_ok "extended iterator tests passed"
fi

cd ..
 
cd ex00 && make fclean && cd ..
cd ex01 && make fclean && rm span_test span_test.cpp && cd ..
cd ex02 && make fclean && rm mtest mtest.cpp && cd ..

##########################################
# Done
##########################################
echo
echo -e "${GREEN}All tests executed.${NC}"
