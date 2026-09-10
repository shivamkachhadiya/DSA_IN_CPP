#include <iostream>
#include <thread>
#include <atomic>
#include <functional>

using namespace std;

class FooBar {
private:
    int n;
    atomic<bool> fooTurn;

public:
    FooBar(int n) {
        this->n = n;
        fooTurn = true;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {

            // Wait until it is foo's turn
            while (!fooTurn);

            printFoo();

            // Now bar's turn
            fooTurn = false;
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {

            // Wait until it is bar's turn
            while (fooTurn);

            printBar();

            // Now foo's turn
            fooTurn = true;
        }
    }
};