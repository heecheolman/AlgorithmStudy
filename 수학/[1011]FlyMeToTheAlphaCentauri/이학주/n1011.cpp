#include <stdio.h>

int main(){
    int T = 0;
    int x = 0;
    int y = 0;
    int count = 0;

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d", &x);
        scanf("%d", &y);
        int k = 1;

        x += k;
        y -= k;
        count = 2;

        while(x < y){
            if( (y - x) == k){
                x += k;
                count++;
            }
            else if( (y - x) >= k){
                k++;
                x += k;
                count++;
            }
            else if( (y - x) < k){
                k--;
                x += k;
                count++;
            }
        }
        
        //while(x!=y)
        //(y-x)==1 -> count++; x += k;

        //처음 k=1 -> x+k 그다음 k값은 (y-x) 즉, 남은거리가 결정한다.
        //(y-x) >= k+1 -> k++; x+=k;

        //(y-x) < k -> k--; x+=k;

        printf("%d\n", count);
    }
}