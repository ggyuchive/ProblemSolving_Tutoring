#include <stdio.h>
#include <stdlib.h>

int main() {
    int T; scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int R; scanf("%d", &R);
        
        // 정적 char 배열, 동적 char 배열 할당
        // scanf를 정적에 쓴 후 동적에 복사
        // * %s의 scanf는 &를 쓰지 않습니다! *
        char static_string[21];
        char* dynamic_string = (char*)malloc(sizeof(char) * 21); 
        scanf("%s", static_string);
        strcpy(dynamic_string, static_string);

        // 동적 char 배열의 길이를 구하는 strlen 함수 사용
        for (int i = 0; i < strlen(dynamic_string); i++) {
            for (int j = 0; j < R; j++) {
                printf("%c", dynamic_string[i]);
            }
        }
        printf("\n");
    }
}