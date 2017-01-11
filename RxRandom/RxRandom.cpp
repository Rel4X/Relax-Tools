#include	"RxRandom.h"

/* Version 1.2 */

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
	if (min < 0 || max < 0)
		return (RxRandom::OneIsNeg(min, max));
	if (min > max)
	{
		unsigned int tmp;

		tmp = max;
		max = min;
		min = tmp;
	}
	max += 1;
	if (min == 0 && max == 1)
	{ return (((rand() % 2) + 1) - 1); }
	return ((rand() % (max - min)) + min);
}

float		RxRandom::Randomize(float min, float max)
{
	int		ret;

	ret = RxRandom::Randomize((int)(min * FLOAT_PRECISION),
		(unsigned int)(max * FLOAT_PRECISION));
	return (((float)ret) / FLOAT_PRECISION);
}

double		RxRandom::Randomize(double min, double max)
{
	int		ret;

	ret = RxRandom::Randomize((int)(min * FLOAT_PRECISION),
		(unsigned int)(max * FLOAT_PRECISION));
	return (((double)ret) / FLOAT_PRECISION);
}

int			RxRandom::OneIsNeg(int min, int max)
{
	int		abs;
	int		ret;

	abs = RX_ABS(max - min);
	ret = RxRandom::Randomize(min + abs, max + abs);
	return (ret - abs);
}

double		RxRandom::OneIsNeg(double min, double max)
{
	float		abs;
	float		ret;

	abs = RX_ABS(max - min);
	ret = RxRandom::Randomize(min + abs, max + abs);
	return (ret - abs);
}
