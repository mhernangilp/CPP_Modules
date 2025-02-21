#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    private:
        T *_arr;
        unsigned int _size;

    public:
        Array() : _arr(NULL), _size(0) {}

        Array(unsigned int size) : _arr(new T[size]), _size(size) {}

        Array(const Array &other) : _arr(new T[other._size]), _size(other._size) {
            for (unsigned int i = 0; i < _size; i++) {
                _arr[i] = other._arr[i];
            }
        }

        ~Array() {
            delete[] _arr;
        }

        Array &operator=(const Array &other) {
            if (this != &other) {
                delete[] _arr;
                _arr = new T[other._size];
                _size = other._size;

                for (unsigned int i = 0; i < _size; i++) {
                    _arr[i] = other._arr[i];
                }
            }
            return *this;
        }

        T &operator[](unsigned int index) {
            if (index >= _size) {
                throw std::out_of_range("Index out of range");
            }

            return _arr[index];
        }

        const T &operator[](unsigned int index) const {
            if (index >= _size) {
                throw std::out_of_range("Index out of range");
            }

            return _arr[index];
        }

        unsigned int size() const {
            return _size;
        }
};

#endif