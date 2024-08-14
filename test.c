#include <stdio.h>
// Include the header for string type
struct person{
    char name[50];
    int id;
    float height;

    struct dob{
        int d;
        int m;
        int y;
    }d1;
};

int main(){

 struct person p1 ={"praj",121,5.7,{12,11,2004}};
 printf("%d",p1.id);
 printf("%d",p1.d1.m);




    return 0;
}