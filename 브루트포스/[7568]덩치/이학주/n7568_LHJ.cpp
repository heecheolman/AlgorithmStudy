#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int x = 0;
    int y = 0;
    int weight[N];
    int length[N];
    int k = 1;

    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        scanf("%d", &y);

        weight[i] = x;
        length[i] = y;
    }
    //x, y 둘다큰 사람이 k명 일때, 내 순위는 k+1

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != j && weight[i] < weight[j] && length[i] < length[j]){
                k++;
            }
        }
        printf("%d ", k);
        k = 1;
    }
    
}