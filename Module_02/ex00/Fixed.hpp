#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int                 _value;
        static const int    _fract;

    public:
        Fixed(void);
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed& original);
        ~Fixed(void);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif