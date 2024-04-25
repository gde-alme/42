#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

void    deepCopy(const Cat &ref) {
    Cat tmp = ref;
}

int main() {
    Brain marvin;

    marvin.addIdea("melhorar marvin");

    std::cout << "Marvin ideias: " << marvin.getIdea(0) << "\n" << std::endl;

    Cat ArthurDent;
    deepCopy(ArthurDent);
    
    ArthurDent.getBrain()->addIdea("42"); 
    std::cout << "* == " << ArthurDent.getBrain()->getIdea(0) << "\n" << std::endl;
    
    Cat riscas;
    deepCopy(riscas);
    
    riscas.getBrain()->addIdea("dormir"); 
    std::cout << "sleep == " << riscas.getBrain()->getIdea(0) << "\n" << std::endl;
    
	// create n animals; half dogs, rest cats
    int n_animals = 8;

    const Animal  *AnimalArray[n_animals];
    for (int i = 0; i < n_animals; i++) {
        if (i < n_animals/2)
            AnimalArray[i] = new Dog();
        else
            AnimalArray[i] = new Cat();
    }

    // test for deep copies
    for (int copy = 0; copy < n_animals; copy++) {
        std::cout << "My type is: " << AnimalArray[copy]->getType() << std::endl;
        std::cout << "And I make: " << std::flush;
        AnimalArray[copy]->makeSound();
    }

	// delete each Animal instance one by one
    for (int j = 0; j < n_animals; j++) {
        delete AnimalArray[j];
    }
}