#include <iostream>
#include "String.h"

int main()
{
	String str1("Wuuba lubba dub dub!");
	String str2(str1);
	String str3 = "Wuuba lubba dub dub!";
	String str4 = str3;
	String str5;

	if (str1 == str2 && str2 == str3 && str3 == str4 && str5 == "")printf("Wuuba lubba dub dub!\n");


	system("pause");
	return 0;
}