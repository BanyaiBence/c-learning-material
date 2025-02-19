#include <stdio.h>

#define SIZE 5  // Define the size of the array to avoid hard-coding
// This thing is called a macro
// In this case it means, that the keyword SIZE will be substituted by the value 5 when the code gets compiled
// More info about the macros later

// P passing arrays to functions
// This might look similar to just passing an integer
// But integers get passed by value, which means, they get copied
// So changes made to the value 'inside' of a function will not effect the value on the 'outside'
// While passing arrays means telling the function where that given array is
// So you are actually passing a memory address
// This means that changes made inside of the function will effect the value outside of the function scope
// Just imagine having a stuff in the memory, and multiple variables pointing to it (see, that's why we call them pointers =))
void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to demonstrate passing pointers to functions
// Here we actually passed the array as a pointer
// It works the same, it's up to your preference whether your write 'int arr[]' or 'int *arr'
void modifyArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modify each element by multiplying it by 2
    }
}

int main() {
    // Arrays are collections of variables of the same type 


    int arr[SIZE] = {1, 2, 3, 4, 5};  // Declare and initialize an array
    
    // Array indexing starts from 0
    printf("Accessing array elements with correct indexing:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);  // Print array elements
    }

    // Incorrect indexing (out-of-bounds access) - THIS IS UNSAFE
    // Uncommenting the following line will lead to undefined behavior.
    // printf("arr[SIZE] = %d\n", arr[SIZE]);  // This is out of bounds (undefined behavior)

    // Passing arrays to functions
    printf("\nPassing arrays to functions:\n");
    printArray(arr, SIZE);  // Print original array
    modifyArray(arr, SIZE); // Modify array (double each element)
    printArray(arr, SIZE);  // Print modified array

    // Working with pointers (pointers to arrays)
    printf("\nWorking with pointers:\n");
    int *ptr = arr;  // Pointer pointing to the first element of the array



    // Arrays are basically just pointers
    // The indexing of arrays start with zero, because the index just tells how many 'steps' should we take to reach the desired memory address
    // This is why the type matters, if the given data type takes x bits of memory, when indexing the array, 
    // we will have to take steps with the length of x bits in the memory

    // Note: To see how much space something takes, you can use the 'sizeof' function



    //  arr[0] ..........arr[4]
    //    |                 |
    //    v                 v
    //  ---------------------------------------------------------------------------
    //  | 6 | 3 | 5 | 23 | 55 | Other stuff in the memory, this can be anything...
    //  --------------------------------------------------------------------------
    //  {   allocated memory  }{  unallocated memory...
    // The array size here is for
    // The 'arr' token itself is a pointer to the address of the first element
    // When I type 'arr[x]', I'm telling how many steps the program should take to reach the desired element
    // But the program doesn't care if I went outside of the bounds of the array
    // And this is dangerous, as the unallocated memory can contain anything, it might be used by another program
    // For e.g. you could just overwrite something there that is necessary for the OS to run, which will make it crash or behave weridly
    // Malicious actors who use your program can take advantage of this as well
    // The compiler assumes you will never do such heinous stuff, so we call this "undefined behavior"
    // This is a neat way of saying that the compiler expect you will take care of this, and it can't guarantee what will happen is you do this




    // Printing array using pointer notation
    printf("Array elements via pointer dereferencing:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));  // Equivalent to arr[i]
    }

    // Avoiding out-of-bounds access using a size check
    // By checking the value agains the SIZE value (here, it's 5), we make sure we can't mess up the indexing
    // Try changing the value of 'index' to something invalid (e.g. 6, -1, etc.)
    printf("\nAvoiding out-of-bounds access:\n");
    int index = 3;  // Valid index
    if (index >= 0 && index < SIZE) {
        printf("arr[%d] = %d\n", index, arr[index]);
    } else {
        printf("Index %d is out of bounds!\n", index);
    }

    return 0;
}
