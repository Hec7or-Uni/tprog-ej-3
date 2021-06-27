# pragma once
# include <string>
# include <vector>
# include "Store.h"

using namespace std;

template <typename T>
class Logger {
    private:
        string sensor;
        vector <Store<T>*> medidas;
    public:
        Logger(const string _sensor, const vector<Store<T>*> _medidas) : sensor(_sensor), medidas(_medidas) {}
        ~Logger() {}

        void push(const T& v);
        void push(const vector<T> v);
        void log();
};

template <typename T>
void Logger<T>::push(const T& v) {
    for (auto i : medidas)
        i->push(v);
}

template <typename T>
void Logger<T>::push(const vector<T> v) {
    for (auto i : medidas) {
        for (unsigned j = 0; j < v.size(); j++)
            i->push(v.at(j));
    }
}

template <typename T>
void Logger<T>::log() {
    cout << this->sensor << ':' << endl;
    for (auto i : medidas)
        cout << '\t' << i->to_string() << endl;
}