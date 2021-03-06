# Variant
A wrapper around std::variant with some helper functions

```cpp

#include <ea_variant/ea_variant.h>
#include <iostream>
#include <vector>

struct First
{
    void process() const
    {
        std::cout << "I am first! My value is " << myValue << std::endl;
    }

    int myValue = 5;
};

struct Second
{
    void process() const
    {
        std::cout << "I am second! My value is " << text << std::endl;
    }

    std::string text = "Hello World";
};

int main()
{
    using Var = EA::Variant<First, Second>;
    std::vector<Var> container;

    container.emplace_back(First());
    container.emplace_back(First());
    container.emplace_back(Second());

    //Visit polymorphic call:
    for (auto& element: container)
        element.visit([](auto& obj) { obj.process(); });

    //Manual polymorphic call:
    for (auto& element: container)
    {
        if (auto* first = element.get<First>())
            first->process();
        else if (auto* second = element.get<Second>())
            second->process();
    }

    return 0;
}
```



I created this for a few reasons:
1. std::visit has some issues in some compilers.
2. A faster alternative, like rollbear::visit doesn't compile on MacOS
3. I wanted to wrap this in a JUCE-style module
4. I thought the syntax could be slightly simplified by wrapping in an object


How to use:

Include the `ea_variant.h` file.
you can also use CMake to set up the include directories automatically

Visitation is using a modified version of:
https://github.com/rollbear/visit