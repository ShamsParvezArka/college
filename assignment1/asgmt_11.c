#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

int isvwl(char ch)
{
	for (size_t i = 0; i < sizeof(vowels); i++) {
		if (ch == vowels[i])
			return true;
	}
	return false;
}

int main()
{
	char ch;
	printf("input a letter: ");
	ch = getchar();

	if (!isalpha(ch)) {
		printf("Error! Input rage must be in [A-Z, a-z]\n");
		return 0;
	}

	if (isvwl(ch)) 
		printf("is vowel\n");
	else 
		printf("is consonent\n");
	return 0;
}
