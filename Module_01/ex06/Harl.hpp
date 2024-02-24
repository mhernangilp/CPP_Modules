#ifndef HARL_HPP
#define HARL_HPP

#define RESET   "\033[0m"
#define BLUE    "\033[94m"
#define GREEN   "\033[92m"
#define ORANGE  "\033[33m"
#define RED     "\033[91m"

#include <iostream>
#include <string>

class Harl {
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
    
    public:
        Harl();
        ~Harl();
        void    complain(std::string level);
};

#endif