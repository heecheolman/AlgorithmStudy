#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works)
{

    long long answer = 0;

    priority_queue<int> pq;

    for (int i = 0; i < works.size(); i++)
    {
        pq.push(works[i]);
    }

    while (n--)
    {
        if (pq.top() > 0)
        {

            pq.push(pq.top() - 1);
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }

    return answer;
}

int main()
{

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n = 4;
    vector<int> works;
    works.push_back(4);
    works.push_back(3);
    works.push_back(3);

    cout << solution(n, works);
}
