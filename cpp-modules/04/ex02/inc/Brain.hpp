#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

# include <string>
# include <iostream>

# ifndef VERBOSE
# define VERBOSE true
# endif

class Brain {
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain & cp);
        ~Brain();
        Brain & operator=(const Brain & cp);
        std::string getIdea(int index) const ;
        void    addIdea(std::string idea);
};

#endif