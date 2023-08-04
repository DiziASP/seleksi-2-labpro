#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    deque<int> minima;
    deque<int> maxima;
    vector<int> maxSublist;
    int maxSubarray = 0;
    int start = 0, end = 0;

    while(end < A.size()){
        int currNum = A[end];

        while (!minima.empty() && A[minima.back()] >= currNum)
            minima.pop_back();
        
        minima.push_back(end);

        while (!maxima.empty() && A[maxima.back()] <= currNum)
            maxima.pop_back();

        maxima.push_back(end);

        if(A[maxima.front()] - A[minima.front()] <= M){

            if(end - start + 1 >= maxSubarray){
                maxSubarray = end - start + 1;
                maxSublist.clear();
                for(int i = start; i <= end; i++){
                    maxSublist.push_back(A[i]);
                }
            }
            end++;
            
        }
        else{
            start++;
            if (start > minima.front())
                minima.pop_front();
            if (start > maxima.front())
                maxima.pop_front();
        }
    }
    

    cout << maxSubarray << endl;

    for(int each: maxSublist){
        cout << each << " ";
    }
    cout << endl;

    return 0;
}