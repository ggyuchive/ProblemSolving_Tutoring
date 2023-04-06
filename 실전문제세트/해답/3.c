#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// tangerine_len은 배열 tangerine의 길이입니다.
int solution(int k, int tangerine[], size_t tangerine_len) {
    int answer = 0;
    
    int cnt[10000001];
    for (int i = 0; i < 10000001; i++) cnt[i]=0;
    
    for (int i = 0; i < tangerine_len; i++) {
        cnt[tangerine[i]]++;
    }
    
    int cntcnt[100001];
    for (int i = 0; i < 100001; i++) cntcnt[i] = 0;
    
    for (int i = 0; i < 10000001; i++) {
        cntcnt[cnt[i]]++;
    }
    
    int todelete = tangerine_len - k;
    int pnt = 1;
    while (todelete > 0) {
        if (cntcnt[pnt] == 0) pnt++;
        else {
            if (pnt <= todelete) {
                todelete-=pnt;
                cntcnt[pnt]--;
            }
            else break;
        }
    }
    
    for (int i = 1; i < 100001; i++) {
        answer += cntcnt[i];
    }
    return answer;
}