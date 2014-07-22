#include	"RxRandom.h"

/* Version 1.0 */

bool		RxRandom::p_initialized = false;

void		RxRandom::Init()
{
	if (RxRandom::p_initialized == false)
	{
		srand(time(0));
		RxRandom::p_initialized = true;
	}
}

int			RxRandom::Randomize(unsigned int min, unsigned int max)
{
	RxRandom::Init();
	return ((rand() % max) + min);
}
