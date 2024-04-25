#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

# include <stack>
# include <deque>
# include <iostream>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack &ref) { *this = ref; };

		MutantStack	&operator=(const MutantStack &ref) {
			std::stack<T, Container>::operator=(ref); 
			return (*this);
		};

		typedef typename Container::iterator		iterator;
		typedef typename Container::const_iterator	const_iterator;

		iterator	begin() { return this->c.begin(); }
		iterator	end() { return this->c.end(); }

		const_iterator	begin() const { return this->c.begin(); }
		const_iterator	end() const { return this->c.end(); }
};

template<typename T, typename Conatainer>
std::ostream	&operator<<(std::ostream &fd, const MutantStack<T, Conatainer> &ref) {
	int i = 0;
	for (typename MutantStack<T, Conatainer>::const_iterator it = ref.begin(); it != ref.end(); it++) {
		fd << "[" << i << "] ->\t" << *it << std::endl; i++;
	}
	return (fd);
}

#endif
