class Foo {
private:
    mutex firstCompleted;
    mutex secondCompleted;

public:
    Foo() {
        firstCompleted.lock();
        secondCompleted.lock();
    }

    void first(function<void()> printFirst) {

        printFirst();

        // second() ko allow karo
        firstCompleted.unlock();
    }

    void second(function<void()> printSecond) {

        lock_guard<mutex> waitForFirst(firstCompleted);

        printSecond();

        // third() ko allow karo
        secondCompleted.unlock();
    }

    void third(function<void()> printThird) {

        lock_guard<mutex> waitForSecond(secondCompleted);

        printThird();
    }
};