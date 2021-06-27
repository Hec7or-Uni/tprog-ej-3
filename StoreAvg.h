# pragma once

# include "complex"
# include "Store.h"

template <typename T>
class StoreAvg : public Store<T> {
    private:
        T Avg;
        int ind;
    public:
        StoreAvg(const T& r) : Avg(r), ind(0) {}

        void push(const T& r) override {
            this->Avg = ( (this->Avg * ind) + r ) / (ind + 1);
            this->ind++;
        }

        const T& value() const override {
            return this->Avg;
        }

        std::string to_string() const override {
            std::ostringstream buff;
            buff << this->Avg;
            string cadena = "Average:" + buff.str();
            return cadena;
        }
};

template <typename T>
class StoreAvg<complex<T>> : public Store<complex<T>> {
    private:
        complex<T> Avg;
        int ind;
    public:
        StoreAvg(const complex<T>& c) : Avg(c), ind(0) {}
        ~StoreAvg() {}

        void push(const complex<T>& c) override {
            T rel = ( (real(this->Avg) * ind) + real(c) ) / (ind + 1);
            T img = ( (imag(this->Avg) * ind) + imag(c) ) / (ind + 1);

            this->Avg = complex<T>(rel, img);
            this->ind++;
        }

        const complex<T>& value() const override {
            return this->Avg;
        }

        std::string to_string() const override {
            std::ostringstream buff;
            buff << this->Avg;
            string cadena = "Average:" + buff.str();
            return cadena;
        }
};