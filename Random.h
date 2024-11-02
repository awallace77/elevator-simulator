#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>
#include <ctime>

class Random {

    public:
	static int rand() {
	    static bool seeded = false;
	    if(!seeded) {
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		seeded = true;
	    }
	    int flip = std::rand() % 2;
	    return flip;
	}
};

#endif

