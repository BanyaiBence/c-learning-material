#include <stdio.h>

int main() {
    // Integer types


    // The range of a normal integer is from -2.147.483.648 to 2.147.483.647 
    int a = 10;               // A basic integer type

    // Takes half the amount of memory
    // Can only contains values from -32.786 to 32.767
    // You won't really need it nowadays, as we have moooooooaaaaar than enough memory
    // But if you reaaaaaaally, reaaally sure you will only use small values
    // And you fancy optimizing for memory, feel free to use it
    short int b = 5;          // A short integer type
    // Actually the same size as an int, but it's a different type, meh...
    long int c = 100000L;     // A long integer type
    // This is actually longer though, this is twice as large as an int, so can have values from -(2^63) to (2^63)-1
    long long int d = 1000000000LL; // A long long integer type

    // Floating point types
    // For rational numbers. Less precise, but only takes as much spaces as an integer
    // Floats are represented in canonical form
    // e.g. 374.2 = 3.7452 * 10^2
    float e = 3.14f;          // A float type (single precision)
    // This takes as much memory as two ints
    // Because it's actually just two ints
    // One int on the left, and one on the right side of the dot
    double f = 3.1415926535;  // A double type (double precision)
    // Aka two long long ints, on the left- and right-sides of the dot
    long double g = 3.141592653589793238L; // A long double type (extended precision)

    // Character type, the smallest possible value you can have
    // Exactly one byte
    // It is actually just an integer
    // Look up ASCII, you can figure out what will be 'A' as an int
    char h = 'A';             // A character type (can hold a single character)

    // Unsigned types
    // Unsigned types can have double the amount of positiive values
    // But they can't have negative values
    // Exactly what unsigned means...you get it
    unsigned int i = 100;     // Unsigned integer (only positive values)
    unsigned long j = 1000000L; // Unsigned long integer

    // Printing the values and sizes of the variables
    printf("Integer types:\n");
    printf("int a = %d, size = %lu bytes\n", a, sizeof(a));
    printf("short int b = %d, size = %lu bytes\n", b, sizeof(b));
    printf("long int c = %ld, size = %lu bytes\n", c, sizeof(c));
    printf("long long int d = %lld, size = %lu bytes\n", d, sizeof(d));

    printf("\nFloating point types:\n");
    printf("float e = %f, size = %lu bytes\n", e, sizeof(e));
    printf("double f = %lf, size = %lu bytes\n", f, sizeof(f));
    printf("long double g = %Lf, size = %lu bytes\n", g, sizeof(g));

    printf("\nCharacter type:\n");
    printf("char h = %c, size = %lu bytes\n", h, sizeof(h));

    printf("\nUnsigned types:\n");
    printf("unsigned int i = %u, size = %lu bytes\n", i, sizeof(i));
    printf("unsigned long j = %lu, size = %lu bytes\n", j, sizeof(j));

    return 0;
}
