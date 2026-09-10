#include<bits/stdc++.h>
using namespace std;

class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool fooTurn = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {

            unique_lock<mutex> lock(m);

            while (fooTurn==false) {
                cv.wait(lock);
            }

            printFoo();

            fooTurn = false;

            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {

            unique_lock<mutex> lock(m);

            while (fooTurn==true) {
                cv.wait(lock);
            }

            printBar();

            fooTurn = true;

            cv.notify_all();
        }
    }
};