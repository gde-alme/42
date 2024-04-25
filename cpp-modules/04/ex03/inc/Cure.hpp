#ifndef __CURE_HPP__
#define __CURE_HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
    private:
        std::string _type;
    protected:
    public:
        Cure();
        Cure(const Cure & cp);
        Cure &operator=(const Cure & cp);
        ~Cure();
        std::string const & getType() const;
        Cure    *clone() const;
        void    use(ICharacter &target);
};

#endif