#pragma once

/* Version 1.2 */

#include	<random>
#include	<ctime>

#define		RX_ABS(value)		((value < 0) ? (-value) : (value))

#define		FLOAT_PRECISION	10000

class		RxRandom
{
private:
	static bool		p_initialized;

private:
	RxRandom(void)		{ }
	~RxRandom(void)		{ }

public:
	static void			Init();
	static int			Randomize(int, int);
	static float		Randomize(float, float);
	static double		Randomize(double, double);

private:
	static int			OneIsNeg(int min, int max);
	static double		OneIsNeg(double min, double max);
};

