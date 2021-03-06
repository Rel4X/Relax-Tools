#pragma once

/* Version 1.1 */

#include		<string>
#include		<vector>

class		RxString :
	public std::string
{
public:
	RxString(void);
	RxString(const std::string&);
	RxString(const char*);
	~RxString(void);

public:
	void				ToUpperCase();
	void				ToLowerCase();
	std::vector<RxString>*		Split(char c);

private:
	unsigned int				CountSeparator(char);
};

