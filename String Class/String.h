#ifndef _STRING_H__
#define _STRING_H__

#include <string.h>
#include <assert.h>

class String
{
private:
	char*			str;
	unsigned int	size;

public:
	String()
	{
		str = new char[size = 1];
		str[0] = '\0'; // str = ""
					   //memset(str, 0, sizeof(*str)); // str = ""
	}

	String(const char* string)
	{
		assert(string != nullptr);
		if (string != nullptr)
		{
			size = strlen(string) + 1;
			str = new char[size];
			strcpy_s(str, size, string);
		}
	}

	String(const String& string)
	{
		assert(string.str != nullptr);
		if (string.str != nullptr)
		{
			size = string.size;
			str = new char[size];
			strcpy_s(str, size, string.str);
		}
	}

	~String()
	{
		assert(str != nullptr);
		if (str != nullptr)
		{
			delete[] str;
			str = new char[size = 1];
			str[0] = '\0';
		}
	}

	String operator = (const char* string)
	{
		assert(str != nullptr);
		if (string != nullptr)
		{
			if (strlen(string) + 1 > size)
			{
				delete[] str;
				size = strlen(string) + 1;
				str = new char[size];
			}
			else
				str[0] = '\0'; // it's better having unsued chars allocated than deleting and allocating again

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
};

#endif // !_STRING_H__
