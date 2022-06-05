#pragma once
bool FloatMore(float number, float n)
{
	return number > n;
}
bool FloatLess(float number, float n)
{
	return number < n;
}
bool (*FloatFunctionsPtr[])(float, float) = { FloatMore,FloatLess };

enum FloatFunctions
{
	EnumFloatLess,
	EnumFloatMore,
};

bool IntDevidedBy(int number,int delim) 
{
	return number % delim == 0;
}
bool IntIsOdd(int number,int delim)
{
	return number % delim == 1;
}
bool IntMore(int number, int m) 
{
	return number > m;
}
bool IntLess(int number, int m)
{
	return number < m;
}
bool (*IntFunctionsPtr[])(int,int) = {IntDevidedBy,IntIsOdd,IntMore,IntLess};


enum IntFunctions 
{
	EnumIntDevidedBy,
	EnumIntIsOdd,
	EnumIntMore,
	EnumIntLess,
};



