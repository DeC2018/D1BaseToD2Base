#include <iostream>
struct Base { int d; };
struct D1 : Base { D1() : Base() { d = 1; } };
struct D2 : Base { D2() : Base() { d = 2; } };
struct D3 : D1, D2 {};
Base const* D1BaseToD2Base(Base const* base) 
{
    const D1* d31 = (const D1*)base;
    const D2* d32 = new D3();

    d31 = (const D1*)base;

    d32 = (const D2*)((const D3*)d31);

    return (const Base*)d32;
}

int main() {
    D3 d3;
    std::cout << ((Base*)(D1*)&d3)->d << std::endl; // Должно быть 1
    std::cout << D1BaseToD2Base((Base*)(D1*)&d3)->d << std::endl; // Должно быть 2
}