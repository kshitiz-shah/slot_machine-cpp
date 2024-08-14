#include <stdio.h>




int main() {
    int array[] = {2, 4, 6, 8, 10};
    int *ptr =&array;

    for(int i=0;i<5;i++){
        printf("%d ",*ptr);
        *ptr++;
    }
    return 0;

    
}
