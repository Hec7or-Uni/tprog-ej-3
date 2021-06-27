# pragma once

# include <sstream>
# include <string>

template <typename T>
class Store {
    public:
        virtual void push(const T& v) = 0;
        virtual const T& value() const = 0;
        virtual std::string to_string() const = 0;
};