#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int n = strlen(s);
    
    int samecnt = 0; int diffcnt = 0;
    char first;
    for (int i = 0; i < n; i++) {
        if (samecnt+diffcnt == 0) {
            first = s[i];
            samecnt++;
        }
        else {
            if (first == s[i]) samecnt++;
            else diffcnt++;
            
            if (samecnt == diffcnt) {
                answer++;
                samecnt = 0; diffcnt = 0;
            }
        }
    }
    if (samecnt+diffcnt > 0) answer++;
    
    return answer;
}