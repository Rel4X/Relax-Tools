#include	"RxRandom.h"

/* Version 1.3 */

bool		RxRandom::p_initialized = false;

void		RxRandom::Init()
{
	if (RxRandom::p_initialized == false)
	{
		srand(time(NULL));
		RxRandom::p_initialized = true;
	}
}

int			RxRandom::Randomize(int min, int max)
{
	RxRandom::Init();
	if (min > max)
	{
		int tmp;

		tmp = max;
		max = min;
		min = tmp;
	}
	if (min < 0 || max < 0)
		return (RxRandom::OneIsNeg(min, max));
	max += 1;
	if (min == 0 && max == 1)
	{ return (((rand() % 2) + 1) - 1); }
	return ((rand() % (max - min)) + min);
}

double		RxRandom::Randomize(double min, double max)
{
	RxRandom::Init();
	if (min > max)
	{
		float tmp;

		tmp = max;
		max = min;
		min = tmp;
	}
	if (min < 0.0 || max < 0.0)
		return (RxRandom::OneIsNeg(min, max));
	return ((rand() / (double)RAND_MAX) * (max - min) + min);
}

void			RxRandom::TestAll()
{
	std::cout << "Int: 0, 100" << std::endl;
	for (int i = 0; i < N_TEST; ++i)
	{ std::cout << RxRandom::Randomize(0, 100) << std::endl; }

	std::cout << "Int: 0, 1" << std::endl;
	for (int i = 0; i < N_TEST; ++i)
	{ std::cout << RxRandom::Randomize(0, 1) << std::endl; }

	std::cout << "Int: 0, -100" << std::endl;
	for (int i = 0; i < N_TEST; ++i)
	{ std::cout << RxRandom::Randomize(0, -100) << std::endl; }

	std::cout << "Double: 0.0, 100.0" << std::endl;
	for (int i = 0; i < N_TEST; ++i)
	{ std::cout << RxRandom::Randomize(0.0, 100.0) << std::endl; }

	std::cout << "Double: 100.0, -100.0" << std::endl;
	for (int i = 0; i < N_TEST; ++i)
	{ std::cout << RxRandom::Randomize(100.0, -100.0) << std::endl; }
}

int			RxRandom::OneIsNeg(int min, int max)
{
	int		abs;
	int		ret;

	abs = RX_ABS(min);
	ret = RxRandom::Randomize(min + abs, max + abs);
	return (ret - abs);
}

double		RxRandom::OneIsNeg(double min, double max)
{
	double		abs;
	double		ret;

	abs = RX_ABS(min);
	ret = RxRandom::Randomize(min + abs, max + abs);
	return (ret - abs);
}
