#include <atomic>
#include <thread>
#include <functional>

using namespace std;

class FooBar {
private:
    int n;
    atomic<bool> fooTurn{true};

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            while (!fooTurn.load());

            printFoo();

            fooTurn.store(false);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            while (fooTurn.load());

            printBar();

            fooTurn.store(true);
        }
    }
};