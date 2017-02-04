#include<stdio.h>
#include<string.h>

// 1) initialize bss
#pragma bss_seg(".bss_data")
char bss[12];

// 4) initialize mem in bss
#pragma bss_seg(".bss_data")
char bss_from_data[15];

int main() {
	// 1) copy data from stack to bss
	char stack_from_bss[12];
	for (int i = 0; i < strlen(bss); i++)
	{
		bss_from_data[i] = bss[i];
	}

	// 2) initialize data in heap
	// strdup automatically mallocs
	char *heap = _strdup("abcdefghijklm");
	static char data_from_heap[13];
	// copy data from heap to data section
	for (int x = 0; x < strlen(data_from_heap); x++) {
		data_from_heap[x] = heap[x];
	}


	// 3) initilize stack with random data
	char stack[14] = "abcdefghijklmn";
	// copy from stack to heap
	// strdup automatically mallocs
	char *heap_from_stack = _strdup(stack);

	// 4) initialize data section
	static char data[15] = "abcdefghijklmno";
	// copy to bss
	for (int i = 0; i < strlen(data); i++)
	{
		bss_from_data[i] = data[i];
	}

	// 5) initialize constant data in text section
	const static char text[4] = "abcd";
	// copy from text to data
	static char data_from_text[4];
	for (int i = 0; i < strlen(text); i++)
	{
		data_from_text[i] = text[i];
	}
}
