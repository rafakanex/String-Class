#include <iostream>
#include "String.h"

int main()
{
	String s1;
	String s2("hello");
	String s3(s2);

	s3 = s2;
	printf("%s\n", s2);
	printf("%s\n", s3);

	system("pause");
	return 0;
}