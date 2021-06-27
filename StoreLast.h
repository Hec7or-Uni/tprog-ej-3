# pragma once

# include "Store.h"

template <typename T>
class StoreLast : public Store<T> {
    private:
        T Latest;
    public:
        void push(const T& v) override {
            this->Latest = v;
        }

        const T& value() const override {
            return this->Latest;
        }

        std::string to_string() const override {
            std::ostringstream buff;
            buff << this->Latest;
            string cadena = "Last:\t" + buff.str();
            return cadena;
        }
};