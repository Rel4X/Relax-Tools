#pragma once

/* version 1.1 */

#include	<sys/time.h>
#include	<sys/types.h>
#include	<string.h>
#include	<map>
#include	<string>
#include	<stdlib.h>

#define		DEFAULT_KEY	"IamTheDefaultKeyOfRxTime"
#define		RXT_PRECISION	1000000

class		RxTime
{
 private:
  bool			p_initialized;
  struct timeval	p_initial_clock;
  std::map<std::string, struct timeval>	p_timers;

public:
  RxTime(void);
  ~RxTime(void);
  
 public:
  bool		Start(const char* key = 0);
  float		GetEllapsedTime(const char* key = 0);
};
