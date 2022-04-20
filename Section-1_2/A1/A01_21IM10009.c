/************************************

* Name : Arpit Bhardwaj

* Roll No : 21IM10009

* Section : 1

* Assignment No : 1

* Description : First C programS

* Date : 13-Apr-2022

* ************************************/

#include<stdio.h>

int main(){

    // PART1: Take input for f(x) and g(x) and add f(x) and g(x) to compute another degree two polynomial h(x).
    
    // Input for f(x)
    int a, b, c, d, e, f, p = 59;
    printf("Give coefficients for f(x)\n");
    printf("constant term = ");
    scanf("%d", &a);
    printf("coeff of x = ");
    scanf("%d", &b);
    printf("coeff of x^2 = ");
    scanf("%d", &c);
    int a0 = a%p, a1 = b%p, a2 = c%p;
    // Input for g(x)
    printf("Give coefficients for g(x)\n");
    printf("constant term = ");
    scanf("%d", &d);
    printf("coeff of x = ");
    scanf("%d", &e);
    printf("coeff of x^2 = ");
    scanf("%d", &f);
    int b0 = d%p, b1 = e%p, b2 = f%p;
    // Adding f(x) and g(x)
    int c0, c1, c2;
    c0 = (a0 + b0)%p, c1 = (a1 + b1)%p, c2 = (a2 + b2)%p;
    // Printing f(x), h(x) and g(x)
    printf("Printing the functions\n");
    printf("f(x) = %d + %d(x) + %d(x^2)\n", a0, a1, a2);
    printf("g(x) = %d + %d(x) + %d(x^2)\n", b0, b1, b2);
    printf("h(x) = %d + %d(x) + %d(x^2)\n", c0, c1, c2);

    // PART2: Taking input for points, Evaluating values, Printing result

    // Input of points
    int p1, p2, p3;
    printf("\nEnter three points:\n");
    printf("s1 = ");
    scanf("%d", &p1);
    printf("\nEnter three points:\n");
    printf("s2 = ");
    scanf("%d", &p2);
    printf("\nEnter three points:\n");
    printf("s3 = ");
    scanf("%d", &p3);
    int s1 = p1%p, s2 = p2%p, s3 = p3%p;
    // Evaluating values
    int x;
    x = s1;
    int fs1 = (a0) + (a1*x) + (a2*x*x);
    x = s2;
    int fs2 = (a0) + (a1*x) + (a2*x*x);
    x = s3;
    int fs3 = (a0) + (a1*x) + (a2*x*x);

    x = s1;
    int gs1 = (b0) + (b1*x) + (b2*x*x);
    x = s2;
    int gs2 = (b0) + (b1*x) + (b2*x*x);
    x = s3;
    int gs3 = (b0) + (b1*x) + (b2*x*x);

    int ms1 = (fs1 + gs1)%p;
    int ms2 = (fs2 + gs2)%p;
    int ms3 = (fs3 + gs3)%p;

    printf("Point-value represntations\n");
    printf("{{s1, f(s1)}, {s2, f(s2)}, {s3, f(s3)}}: {{%d, %d}, {%d, %d}, {%d, %d}}\n", s1, fs1, s2, fs2, s3, fs3);
    printf("{{s1, g(s1)}, {s2, g(s2)}, {s3, g(s3)}}: {{%d, %d}, {%d, %d}, {%d, %d}}\n", s1, gs1, s2, gs2, s3, gs3);
    printf("{{s1, m(s1)}, {s2, m(s2)}, {s3, m(s3)}}: {{%d, %d}, {%d, %d}, {%d, %d}}\n", s1, ms1, s2, ms2, s3, ms3);
    
    // PART3: Calculating m(x) and comparing with h(x)
   
    int m0, m1, m2;
    int den;

    printf("Enter the integral value of modulo inverse[(data*inverse)%%p = 1: this inverse] of (s1-s2)(s2 - s3)(s1 - s3): ");
    
    scanf("%d", &den);

    m0 = (p + (((ms1*(s2 - s3)*s2*s3 - ms2*(s1 - s3)*s1*s3 + ms3*(s1 - s2)*s1*s2)%p)*(den))%p)%p;
    m1 = (p + (((- ms1*(s2 - s3)*(s2 + s3) + ms2*(s1 - s3)*(s1 + s3) - ms3*(s1 - s2)*(s1 + s2)))%p*(den))%p)%p;
    m2 = (p + (((ms1*(s2 - s3) - ms2*(s1 - s3) + ms3*(s1 - s2))%p)*(den))%p)%p;


    printf("m(x) = %d + %d(x) + %d(x^2)\n", m0, m1, m2);
    printf("h(x) = %d + %d(x) + %d(x^2)\n", c0, c1, c2);

    return 0;
}
