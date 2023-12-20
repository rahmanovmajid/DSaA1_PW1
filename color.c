#include<stdio.h>

struct color{
    int red;
    int green;
    int blue;
};


void C_print(struct color c);
struct color C_new(int r,int g,int b);
struct color C_multiply(struct color c,float coef);
int clamp(int n);
struct color C_negative(struct color c);


int main() {

    struct color a;
    a.blue = 25;
    a.green = 13;
    a.red = 0;
    C_print(a);

    // 6
    struct color orange = C_new(300,100,0);
    C_print(orange);

    C_print(C_multiply(orange,1.2));
    
    

    return 0;
}

void C_print(struct color c){
    printf("%d,%d,%d\n",c.red,c.green,c.blue);
}

struct color C_new(int r,int g,int b){
    struct color new;
    new.red = clamp(r);
    new.green = clamp(g);
    new.blue = clamp(b);
    return new;
}

int clamp(int n){
    if ( n < 0 ) return 0;
    else if ( n > 255 ) return 255;
    else   return n;
}


struct color C_permute(struct color c){
    return C_new(c.green,c.blue,c.red);
}