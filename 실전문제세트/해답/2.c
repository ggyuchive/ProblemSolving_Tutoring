#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*10000), len = 0;
    
    bool isHave[202];
    for (int i = 0; i < 202; i++) isHave[i] = false;
    
    for (int i = 0; i < numbers_len; i++) {
        for (int j = i+1; j < numbers_len; j++) {
            isHave[numbers[i]+numbers[j]] = true;
        }
    }
    for (int i = 0; i < 202; i++) {
        if (isHave[i] == true) answer[len++] = i;
    }
    return answer;
}