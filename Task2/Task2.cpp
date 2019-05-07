#include <iostream>
#include <iso646.h>

using namespace std;


int __fastcall CalculateDegree(unsigned int a, unsigned int b)
{

	unsigned int result;
	__asm
	{
		mov eax, a
		mov ecx, b
		sub ecx, 1
		_begin :
		imul a
		loop _begin
		_end :
		mov edx, b
		mov result, eax
	}
	return result;
}

int __fastcall Task2(unsigned int n, unsigned int m)
{
	unsigned int result;
	__asm
	{
		mov ecx, n
		mov edx, m
		mov ebx, 0
		mov ebp, n

		_begin :
		call  CalculateDegree
		mov ecx, ebp
		sub ebp, 1
		add ebx, eax
		loop _begin
		_end :
		mov result, ebx

	}

	return result;

}




int main()
{

	unsigned int N;
	unsigned int M;
	wcout << L"Input N and M : ";
	wcin >> N;
	wcin >> M;

	wcout << Task2(N, M);


}