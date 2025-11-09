#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int height;
    do{
        height = get_int("What is the height of the pyramid? ");
    }while (height < 1 || height > 8 );
    for (int i = 0; i < height;i++){
        for(int j = 0; j < height - i - 1; j++){
            printf(" ");
        }
        for(int k = 0; k <= i; k++){
            printf("#");
        }
        printf("  ");
        for(int k = 0; k <= i; k++){
            printf("#");
        }
        printf("\n");
    }
}
// void print_final(int spaces)
// {
//     for (int i = 0; i < height;i++){
//         for(int j = 0; j < height - i - 1; j++){
//             printf(".");
//         }
//         for(int k = 0; k <= i; k++){
//             printf("#");
//         }
//         printf(" ")
//         for(k = 0; k <= i; k++){
//             printf("#");
//         }
//         printf("\n");
//     }
// }
