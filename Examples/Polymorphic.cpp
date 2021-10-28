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