#include "RxString.h"

/* Version 1.0 */

RxString::RxString(void)
{
}

RxString::RxString(const std::string& s) :
	std::string(s)
{
}

RxString::RxString(const char* s) :
 std::string(s)
 {
 }

RxString::~RxString(void)
{
}

void						RxString::ToUpperCase()
{
	for (int i = 0; i < this->size(); ++i)
	{
		if ((*this)[i] >= 'a' && (*this)[i] <= 'z')
			(*this)[i] = (*this)[i] - 32;
	}
}

void						RxString::ToLowerCase()
{
	for (int i = 0; i < this->size(); ++i)
	{
		if ((*this)[i] >= 'A' && (*this)[i] <= 'Z')
			(*this)[i] = (*this)[i] + 32;
	}
}

std::vector<RxString>*		RxString::Split(char c)
{
	std::vector<RxString>*	vec;
	int						idx;
	RxString				tmp;
	unsigned int			count;
	int						j;

	j = 0;
	vec = 0;
	tmp = (*this);
	count = this->CountSeparator(c);
	if (count == 0)
		return (0);
	vec = new std::vector<RxString>(count);
	for (int i = 0; i < count; ++i)
	{
		(*vec)[i] = "";
		if ((idx = tmp.find_first_of(c)) > -1)
		{
			(*vec)[i] = tmp.substr(0, idx);
			tmp = tmp.substr(idx + 1);
		}
		else if (i == count - 1 && tmp.size() > 0)
			(*vec)[i] = tmp;
	}
	return (vec);
}

unsigned int				RxString::CountSeparator(char c)
{
	unsigned int			count;

	if (this->size() == 0)
		return (0);
	count = 0;
	for (int i = 0; i < this->size(); ++i)
	{
		if ((*this)[i] == c)
			++count;
	}
	return (count + 1);
}

void						RxString::RemoveSeparator(RxString& s, char c)
{
	while (s.size() > 0 && s[0] == c)
		s = s.substr(1);
}