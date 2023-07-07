#include <stdio.h>
#include <string.h>
const int sz = 0;
int a[sz];
typedef struct
{
    char *s;
} st;

int main()
{
    st obj;
    strcpy(obj.s, "hello world");
    printf("%s", obj.s);
    return 0;
}
