#include <iostream>
#include "String.h"

int main()
{
	String s1("hello");
	String s2(s1);
	String s3("helloo");
	String s4;

	s2.Print();
	
	s2 = s3;
	s2.Print();

	s4 = "hellooo";
	s4.Print();
	system("pause");
	return 0;
}