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
		str = new char[size];
		str[0] = '\0'; 
	}

	String(const char* string)
	{
		size = strlen(string) + 1;
		str = new char[size];
		strcpy_s(str, size, string);
	}

	String(const String& string)
	{
		size = string.size;
		str = new char[size];
		strcpy_s(str, size, string.str);
	}

	~String()
	{
		delete[] str; // cannot be nullptr cause of the default constructor -> Clear()
	}

	String operator = (const char* string)
	{
		if (string != nullptr)
		{
			if (strlen(string) + 1 > size) // it's better having more unsued char allocated than deleting and allocating again
			{
				size = strlen(string) + 1;
				str = new char[size];
			}
			else
				str[0] = '\0';

			strcpy_s(str, size, string);
		}
		else
			str[0] = '\0'; // clear string if it's empty

		return *this;
	}

	bool operator == (const String& string) const
	{
		return strcmp(str, string.str) == 0;
	}

	/*void Alloc(const unsigned int memory) 
	{
		str = new char[size];
	}

	void Clear() const
	{
		str[0] = '\0'; // or memset
	}*/
};

#endif // !_STRING_H__
