#include <stdio.h>

int main(){
    int N = 0;
    scanf("%d", &N);

    int count = 1;
    int check = 1;

    if(N == 1){
        printf("%d", count);
    }
    else if(N > 1){

        for(int i = 1; i <= N; i++){
            if(i == (check + (6 * count))){
                check = i;
                count++;
            }
        }
        if(N == check){
            count--;
        }
        printf("%d", (count + 1));

    }
}