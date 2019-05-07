#include <iostream>
#include <iso646.h>

using namespace std;

int  FirstTask(int a,int b,int c)
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
		jz disc_neg

		mov eax, 0
		mov result,eax
		jmp _end

		disc_pos :
		 mov eax,2
		 mov result,eax
		 jmp _end

		disc_neg :
		 mov eax, 1
		 mov result, eax
		 _end :

	}

   	return result;
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
	auto result = FirstTask(a, b, c);
	//////////////////////////////
	wcout <<L"Count : " << result << endl;
	system("pause");



}