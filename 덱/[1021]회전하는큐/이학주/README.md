# [회전하는큐 (1021)](https://www.acmicpc.net/problem/1021)

## 풀이
덱을 임포트하여 사용하였다.

우선 N을 입력받아서 오름차순으로 덱에 입력하였다.
그 후에 M을 입력받아서 뽑아내고자 하는 수를 반복문으로 M번 반복하게 하였다.

인덱스를 통해서 입력받은 수가 왼쪽에서 가까운지, 오른쪽에서 가까운지를 판단하였고 
가까운 곳에서 한칸씩 이동시켜주고 찾고자하는 수를 front에 위치시켜주어 최솟값을 구하였다.

<pre><code>
    if(i < dq.size() - i){
        output += i;
                    
        while (i--)
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    else if(i >= dq.size() - i){
        output += dq.size() - i;

        int count = dq.size() - i;
        while (count--)
        {
            dq.push_front(dq.back());
            dq.pop_back();
        }
    }
</code></pre>
