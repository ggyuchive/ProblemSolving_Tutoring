#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// elements_len은 배열 elements의 길이입니다.
int solution(int elements[], size_t elements_len) {
    int answer = 0;
    
    int sum = 0;
    for (int i = 0; i < elements_len; i++) {
        sum += elements[i];
    }
    
    bool isHave[1000001];
    for (int i = 0; i < 1000001; i++) isHave[i] = false;
    
    for (int i = 1; i < elements_len; i++) {
        elements[i] += elements[i-1];
    }
    
    for (int i = 0; i < elements_len; i++) {
        for (int j = i; j < elements_len; j++) {
            int partsum;
            if (i-1 < 0) partsum = elements[j];
            else partsum = elements[j]-elements[i-1];
            
            isHave[partsum] = true;
            isHave[sum-partsum] = true;
            //printf("%d %d\n", partsum, sum-partsum);
        }
    }
    
    for (int i = 1; i < 1000001; i++) {
        if (isHave[i] == true) answer++;
    }
    return answer;
}