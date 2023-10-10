#include <stdio.h>
#include <stdlib.h>

int main() {
    char* c_str = (char*)malloc(sizeof(char)*10);
    if (!c_str) {
        printf("Malloc failed");
        return 0;
    }
    scanf("%s", c_str);
    // fgets(c_str, 100, stdin);
    printf("%s", c_str);
    free(c_str);
    return 0;
}