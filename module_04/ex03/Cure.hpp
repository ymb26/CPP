#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
public:
	Cure();
	virtual ~Cure();
	Cure(const Cure& copy);
	Cure& operator=(const Cure& copy);

	AMateria* clone() const;
	void use(ICharacter& target);
};


#endif //CURE_HPP
