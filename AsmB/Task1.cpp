#include <iostream>
#include <iso646.h>

using namespace std;

int __cdecl Calculate(int a, int b, int c)
{
	int result;

	__asm
	{
		mov eax, a
		mov ebx, c
		mov ecx, 4
		cdq
		imul ecx
		imul ebx

		mov ebx, eax
		mov eax, b
		cdq
		imul eax

		cmp eax, ebx
		jg disc_pos
		jz disc_zero

		mov eax, 0
		mov result, eax
		jmp _end

		disc_pos :
		mov eax, 2
			mov result, eax
			jmp _end

			disc_zero :
		mov eax, 1
			mov result, eax
			_end :
		
	}

	return result;
}

void  FirstTask(int a,int b,int c)
{
	unsigned int result;

	__asm
	{
		push a
		push b
		push c
		call Calculate
		mov result, eax
		add esp,12

	}
	wcout << L"Answer : " << result;
}


int main()
{
	int a;
	int b;
	int c;
	wcout << L"Input args : ";
	wcin >> a;
	wcin >> b;
	wcin >> c;
	FirstTask(a, b, c);
	
	system("pause");
	// a = c = 36864
	// b = 34048



}