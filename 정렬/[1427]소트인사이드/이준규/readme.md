# 소트인사이드
***
### 입력범위

1000000000 까지의 자연수를 입력받으니 최대 자리수는 10자리수이므로 
10칸의 정수배열을 0으로 초기화 해줍니다
***
입력받은 자연수를 작은 자리수부터 배열에 차례로 저장시킵니다.

2143일 경우) 3을 첫칸에 저장하기 위해
2143을 1로 나눈 몫인 2143에서 2140을 빼준다
2140은 2143을 10으로 나눈 몫

> data = ( n / i ) - 10 * ( n / (i * 10) ) 

이 식을 얻었다.
n 을 i 로 나눈 몫이 0일 경우면 자리수가 끝난 거고 i 에 10을 곱해가며 반복문을 만든다

자리수를 세기 위한 len 와 배열 인덱스인 a 에 1씩 더해줍니다.

***
### 선택정렬을 을 진행
최소값을 이용하면 오름차순이고 최대값을 이용하면 내림차순이 형성된다
***
자리수인 len만큼 배열을 차례로 출ur
