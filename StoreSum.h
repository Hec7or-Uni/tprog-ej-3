# pragma once

# include "Store.h"

template <typename T>
class StoreSum : public Store<T> {
    private:
        T Sum;
    public:
        StoreSum(const T& v) : Sum(v) {}

        void push(const T& v) override {
            this->Sum = Sum + v;
        }

        const T& value() const override {
            return this->Sum;
        }

        std::string to_string() const override {
            std::ostringstream buff;
            buff << this->Sum;
            string cadena = "Sum:\t" + buff.str();
            return cadena;
        }
};