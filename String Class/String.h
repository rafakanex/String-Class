#ifndef _STRING_H__
#define _STRING_H__

#include <string.h>

class String
{
private: 
	char* str;
	unsigned int size;

public:
	String()
	{
		Alloc(1);
		Clear();
	}
	
	String(const char* str)
	{
		unsigned int size = strlen(str) + 1;
		if (size > 0) Alloc(size);
		strcpy_s(this->str, size, str);
	}

	String(const String& str)
	{
		unsigned int size = strlen(str.str) + 1;
		if (size > 0) Alloc(size);
		strcpy_s(this->str, size, str.str);
	}

	~String()
	{
		delete[] str;
	}

	String operator = (const String& str)
	{
		delete[] this->str;
		unsigned int size = strlen(str.str) + 1;
		if (size > 0) Alloc(size);
		strcpy_s(this->str, size, str.str);
		return *this;
	}

	void Alloc(unsigned int size)
	{
		str = new char[size];
	}

	void Clear()
	{
		str[0] = '\n';
	}

};
#endif // !_STRING_H__
