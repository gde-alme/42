#ifndef __SERIALIZE_HPP__
#define __SERIALIZE_HPP__

# include "data.h"
# include <stdint.h>
# include <iostream>

class Serialize {
	private:
	public:
		Serialize();
		Serialize(const Serialize &);
		~Serialize();
		Serialize	&operator=(const Serialize &);

		uintptr_t	serialize(Data *);
		Data 		*deserialize(uintptr_t);
};

#endif