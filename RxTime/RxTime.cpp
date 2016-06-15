#include	"RxTime.h"

/* version 1.1 */

RxTime::RxTime(void) :
  p_initialized(false)
{
  memset(&this->p_initial_clock, 0, sizeof(this->p_initial_clock));
}

RxTime::~RxTime(void)
{
}

bool		RxTime::Start(const char* key)
{
  struct timeval	tmp;

  if (this->p_initialized == false)
    {
      if (gettimeofday(&this->p_initial_clock, NULL) == -1)
	return (false);
      this->p_initialized = true;
    }
  if (gettimeofday(&tmp, NULL) == -1)
    return (false);
  if (key)
    { this->p_timers[key] = tmp; }
  else
    { this->p_timers[DEFAULT_KEY] = tmp; }
  return (true);
}

float		RxTime::GetEllapsedTime(const char* key)
{
  struct timeval	tmp;
  float			timer;
  std::map<std::string, struct timeval>::iterator	it;
  
  if (this->p_initialized = false) return (0.0);
  if (key) it = this->p_timers.find(key); else it = this->p_timers.find(DEFAULT_KEY);
  if (it == this->p_timers.end()) return (0.0);
  if (gettimeofday(&tmp, NULL) == -1) { return (false); }
  timer = ((tmp.tv_sec - (*it).second.tv_sec) * RXT_PRECISION)
    + (tmp.tv_usec - (*it).second.tv_usec);
  timer = timer / RXT_PRECISION;
  return (timer);
}
