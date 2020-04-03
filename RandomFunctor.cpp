#include "RandomFunctor.h"
#include <cstdlib>
#include <ctime>

RandomFunctor::RandomFunctor(int M)
{
	_M = M;
	srand(time(0));
}

int RandomFunctor::operator()()
{
	return rand() % (2 * _M + 1) - _M;
}
