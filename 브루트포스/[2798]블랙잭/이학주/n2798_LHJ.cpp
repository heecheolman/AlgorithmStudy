#include <stdio.h>

int blackjack(int array[], int N, int M){

    int sum = 0; //카드의 합, M과 비교되는 변수
    int result = 0; //최종으로 제출되는 변수

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(i != j && i != k && j != k){
                    sum = array[i] + array[j] + array[k];
                    if(sum <= M && result <= sum){
                        result = sum;
                    }
                }
                
            }
        }
    }

    return result;
}

int main(){
    int N; //N장의 카드
    int M; //합이 M을 초과하면 안됨
    
    scanf("%d", &N);
    scanf("%d", &M);

    int array[N]; //N장의 카드들의 모임 0 ~ N-1
    
    for(int i = 0; i < N; i++){
        scanf("%d", &array[i]);
    }

    printf("%d", blackjack(array, N, M));

}
