#include <stdio.h>

int getlength(char *a){
	int i;
	for (i = 0; a[i] != NULL; i++);
	return i;
}

int IndexString(char *a, char *b){
	int i = 1, j = 0, k = 0;
	int next[255];
	int charnum1, charnum2;      //×Ö·û´®1ºÍ×Ö·û´®2µÄ³¤¶È
	charnum1 = getlength(a);
	charnum2 = getlength(b);
	//printf("%d\n", charnum2);


	next[1] = 0;
	while (i < charnum2)
	{
		if ((j == 0) || (b[i-1] == b[j-1]))
		{
			i++; j++;
			next[i] = j;
		}
		else j = next[j];
	}

	for (i = 1; i <= charnum2; i++)
	{
		printf("%d\n", next[i]);
	}

	while (i < charnum1 && j < charnum2)
	{
		if (j == 0 || a[i] == b[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == charnum2)
	{
		return (i - charnum2);
	}
	else
	{
		return -1;
	}

	return 0;
}

int main(){
	char a[256];
	char b[16];
	int i;

	strcpy(a, "etggaaqabaabcaclgrewughpoiuagnloerihaglkd");
	strcpy(b, "abaabcac");

	printf("%s\n", a);
	printf("%s\n", b);

	i = IndexString(a, b);


	if (i != -1)
	{
		printf("Æ¥Åä³É¹¦Î»ÖÃÔÚ%d\n", i + 1);
	}
	else
	{
		printf("Æ¥ÅäÊ§°Ü\n");
	}

	return 0;
}