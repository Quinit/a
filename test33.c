#include "stdio.h"

int main(){
    char a = 'k';
    char b = a;
    printf("char is %c\n",a);
    printf("ASCII num %x\n",a);

    int i = 0;
    while(a != 0){
        i += a & 0x01;
        a = a >> 1;
    }

    printf("num 1 has %x\n",i);
    if((i & 0x01) == 1)
        printf("changed num is %x\n",b + 0x80);
    return 0;
}