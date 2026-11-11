
#include <iostream>

int main()
{
    // Brace initialization
    int a{7};
    int b{2};

    // Explicit conversion
    double c = static_cast<double>(a) / b;

    std::cout << "Correct division: " << c << '\n';

    // Explicit character conversion
    char ch = static_cast<char>('A' + 2);

    std::cout << "Character: " << ch << '\n';

    // Explicit Boolean conversion
    bool flag = static_cast<bool>(5);

    std::cout << "Boolean: " << std::boolalpha
              << flag << '\n';

    // Safe signed and unsigned comparison
    unsigned int u{1};
    int s{-1};

    bool result;

    if (s < 0)
    {
        result = true;
    }
    else
    {
        result = static_cast<unsigned int>(s) < u;
    }

    std::cout << "Signed comparison: "
              << (result ? "s < u" : "s >= u")
              << '\n';

    // Safe narrowing example
    int x = static_cast<int>(3.7);

    std::cout << "Converted integer: " << x << '\n';

    return 0;
}
