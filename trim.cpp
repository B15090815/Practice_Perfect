
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* trim (char *phrase)
{
    char *old = phrase;
    char *s = phrase;
    while(*old == ' ')
    {
        old++;
    }
    int i=0;
    while(*old)
    {
        *(s++) = *(old++);
    }
    *s = 0;
    return (char*) realloc(phrase,strlen(phrase)+1);
}

int main()
{
	char *buf = (char*)malloc(strlen("   hello world")*sizeof(char));
	strcpy(buf,"   hello world");
	printf("%s\n",buf);
	buf = trim(buf);
	printf("%s\n",buf);
	return 0;

}
