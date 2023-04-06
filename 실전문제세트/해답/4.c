#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sequence_len은 배열 sequence의 길이입니다.
int* solution(int sequence[], size_t sequence_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*2);
    
    int l = 0; int r = 0;
    int sum = 0;
    int len = 10000000; int start = 10000000;
    
    while (l < sequence_len && r <= sequence_len) {
        if (sum == k) {
            if (len > r-l || (len == r-l && start > l)) {
                len = r-l; start = l;
            }
            sum -= sequence[l++];
            sum += sequence[r++];
        }
        else if (sum > k) {
            sum -= sequence[l++];
        }
        else if (sum < k) {
            sum += sequence[r++];
        }
    }
    answer[0] = start; answer[1] = start+len-1;
    return answer;
}