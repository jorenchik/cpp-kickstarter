// CPlusPlusUnit Usage Example.
// CPlusPlusUnit - C++ Unit testing TDD framework (github.com/cppunit/cppunit)
#include "MyLibrary.h"
#include "cppunit.h"
#include "main_lib.h"

// Class under test.
class test_class {
  public:
    int calculate() {
        int n, m;
        std::cin >> n >> m;
        return n + m;
    }
};

// Test examples.
class Cppunit_tests : public Cppunit {
    void single_test() {
        CHECKT(add(2, 3) == 5);
        CHECKT(functionToTest(5) == 10);
    }
};

int main(int argc, char *argv[]) {
    // Test invocation example.
    return (new Cppunit_tests)->run();
}
