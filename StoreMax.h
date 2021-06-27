# pragma once

# include "Store.h"

template <typename T>
class StoreMax : public Store<T> {
    private:
       T Max;
    public:
        void push(const T& v) override {
            if (v > Max) {
                this->Max = v;
            }
        }
        
        const T& value() const override {
            return this->Max;
        }

        std::string to_string() const override {
            std::ostringstream buff;
            buff << this->Max;
            string cadena = "Max:\t" + buff.str();
            return cadena;
        }
};