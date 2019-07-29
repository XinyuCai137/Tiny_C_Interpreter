#include "stdio.h"

extern void SyntaxAnalysis();

FILE *sFile;


int main(int argc, char* argv[])
{
	char i;
	char t[10] = "test1.txt";
	printf("Please input test number:\n");
	scanf("%c", &i);
	getchar();

	t[4] = i;
	printf("Result of %s:\n", t);
	sFile=fopen(t,"rt");
	SyntaxAnalysis();
	fclose(sFile);

	system("pause");
	return 0;
}

/*
int main(int argc, char* argv[])
{
//    sFile=fopen_s(argv[1],"r");
    sFile=fopen("test2.txt","rt");
	SyntaxAnalysis();
	fclose(sFile);

//Free all memories

	return 0;
}
*/