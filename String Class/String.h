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
		str = "x";
	}

	String(const String& string)
	{
		Alloc(string.size);
		strcpy_s(str, size, string.str);
	}

	String(const char* string)
	{
		unsigned int size = strlen(string) + 1;
		Alloc(size);
		strcpy_s(str, size, string);
	}

	void Print()
	{
		printf("%s\n", str);
	}

	void Alloc(unsigned int size) 
	{
		str = new char[size];
	}

	/*String operator = (const String& string)
	{
		if (strlen(string) > size)
		{

		}
	}*/

	bool operator == (const String& string) const
	{
		return strcmp(str, string.str);
	}
};

#endif // !_STRING_H__
