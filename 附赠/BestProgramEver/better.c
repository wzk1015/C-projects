#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s[ ] = {
    9,
    48,
    10,
    125,
    59,
    10,
    10,
    47,
    42,
    10,
    //(213 lines deleted)
    0
    };
    /* The string is a
    * representations of the body
    * of this program from ¡®0¡¯
    * to the end
    */

    int  i;
    printf("int \ts[ ] = { \n");
    for(i=0; s[i]; i++)
    printf("\t%c\n,\n", s[i]);
    printf("%s", s);


}
