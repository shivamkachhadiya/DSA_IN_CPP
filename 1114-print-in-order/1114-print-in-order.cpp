using namespace std;

class Foo {
public:
atomic<int>lock;
void spinlock(int id){
    while(lock!=id){}
}
    Foo() {
        lock=1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        lock=2;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        spinlock(2);
        printSecond();
        lock=3;
    }

    void third(function<void()> printThird) {
        spinlock(3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};