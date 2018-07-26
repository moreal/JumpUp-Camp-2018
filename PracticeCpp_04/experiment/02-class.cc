/*
    Copyright 2018 Moreal
*/

#include <iostream>

class A {
    int a = 1;
 public:
    friend void show(A&);

    int b = 2;
    int c = 3;

    char d = 1;
    int e = 2;

    void empty_method() {}
    void arg_method(int i) {}
    int return_method() {}
};

void show(A& a) {
    std::cout << "===== Variables =====\n";
    std::cout
        << (intptr_t)&a.a << ' ' << a.a << '\n'
        << (intptr_t)&a.b << ' ' << a.b << '\n'
        << (intptr_t)&a.c << ' ' << a.c << '\n'
        << (intptr_t)&a.d << ' ' << (int)a.d << '\n'
        << (intptr_t)&a.e << ' ' << a.e << '\n';

    std::cout << "===== Method =====\n";
    std::cout
        << reinterpret_cast<void*>(&a.empty_method) << ' '
        << reinterpret_cast<void*>(&a.arg_method) << ' '
        << reinterpret_cast<void*>(&a.return_method) << "\n\n";
}

int main() {
    A a, b;
    A* c = new A;

    std::cout << "===== Check Memory =====\n";
    show(a);
    show(b);
    show(*c);

    return 0;
}

/*
Output
===== Check Memory =====
===== Variables =====
6422060 1
6422064 2
6422068 3
===== Method =====
0x402eb0 0x402ea0 0x402ec0

===== Variables =====
6422048 1
6422052 2
6422056 3
===== Method =====
0x402eb0 0x402ea0 0x402ec0

===== Variables =====
7411536 1
7411540 2
7411544 3
===== Method =====
0x402eb0 0x402ea0 0x402ec0

===== Check Memory 2 =====
===== Variables =====
6422048 1
6422052 2
6422056 3
6422060 1
6422064 2
===== Method =====
0x402f40 0x402f30 0x402f50

===== Variables =====
6422016 1
6422020 2
6422024 3
6422028 1
6422032 2
===== Method =====
0x402f40 0x402f30 0x402f50

===== Variables =====
15800144 1
15800148 2
15800152 3
15800156 1
15800160 2
===== Method =====
0x402f40 0x402f30 0x402f50

메소드는 고정되어 있다. 객체마다 가지는 변수만이 메모리 할당시 할당된다.
// 역시 C++은 어리석지 않다.

각 변수들을 선언한 순서대로 메모리상에 올라가는 것을 볼 수 있다.
그리고 char 같은 걸로 메모리 절약이라고 해도 int, 4단위로 끝어서 메모리를 할당한다.
char 다음 int를 사용하니 빈 3byte는 사라졌고 각 객체 사이에 추가적인 여백만이 더 생겼다

형변환을 해도 사용이 가능한 이유는 this 기준 거리가 같다면 메모리에서 값을 읽어올때에는 별 문제 없기 때문이다.

결론:
int 사용하자
*/