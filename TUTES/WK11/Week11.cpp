#include <functional>
#include <iostream>

using namespace std;

int main()

{
    auto f1 = [](int x, int y) { return x + y; };

    cout << f1(2, 3) << endl;

    // use capture list

    int i = 1;

    int j = 5;

    auto f2 = [i, &j] { return i + j; };

    cout << f2() << endl;

    return 0;
}