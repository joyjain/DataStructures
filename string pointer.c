#include<stdio.h>
#include<string.h>
void main()
{
	char string[100],substring[100];
	printf("Enter two strings\n");
	scanf("%s",string);
	scanf("%s",substring);
	findstringinstring(string,substring);
}
char *findstringinstring(string,substring)
    register char *string;	/* String to search. */
    char *substring;		/* Substring to try to find in string. */
{
    register char *a, *b;

    /* First scan quickly through the two strings looking for a
     * single-character match.  When it's found, then compare the
     * rest of the substring.
     */

    b = substring;
    if (*b == 0) {
	return string;
    }
    for ( ; *string != 0; string += 1) {
	if (*string != *b) {
	    continue;
	}
	a = string;
	while (1) {
	    if (*b == 0) {
		return string;
	    }
	    if (*a++!=*b++) {
		break;
	    }
	}
	b = substring;
    }
    return (char *) 0;
}
