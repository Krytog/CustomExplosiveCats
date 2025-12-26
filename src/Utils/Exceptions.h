#pragma once

#include <stdexcept>
#include <format>

class Exception : public std::runtime_error {
public:
    template <typename... Args>
    Exception(const std::format_string<Args...>& format_string, Args&&... args)
    : std::runtime_error(std::format(format_string,
                                     std::forward<Args>(args)...)) {}
};
