#include <stdio.h>

int main(){
    
    int T;
    int H;
    int W;
    int N;
    int count = 0;
    
    scanf("%d", &T);
    
    for(int k = 0; k < T; k++){
        scanf("%d", &H);
        scanf("%d", &W);
        scanf("%d", &N);
        
        for(int i = 1; i <= W; i++){
            for(int j = 1; j <= H; j++){
                count++;
                if(count == N){
                    printf("%d\n", ((100 * j) + i) );
                }
            }
        }
        count = 0;
    }
}