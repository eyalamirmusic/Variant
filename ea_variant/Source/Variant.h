#pragma once

#include "Rollbear.h"

namespace EA
{
template <typename... Args>
struct Variant : std::variant<Args...>
{
    using VarType = std::variant<Args...>;
    using VarType::variant;

    template <typename T>
    T* get()
    {
        return std::get_if<T>(this);
    }

    template <typename Callable>
    auto visit(Callable&& func)
    {
        return rollbear::visit(func, *this);
    }
};

} // namespace EA
