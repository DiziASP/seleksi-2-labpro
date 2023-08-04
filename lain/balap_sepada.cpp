#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;

    vector<int> klasemen(N);
    for(int i = 0; i < N; i++){
        cin >> klasemen[i];
    }

    vector<int> switch_per_min(Q);
    for(int i = 0; i < Q; i++){
        cin >> switch_per_min[i];
    }

    for(int each: switch_per_min){
        deque<int> temp;

        for(int i = 0; i < each; i++){
            int x;
            cin >> klasemen[x];
            temp.push_back(x);
        }

        while(temp.size() > 0){
            int front = temp.front();
            temp.pop_front();

            int back;
            if(temp.size() != 1){
                back = temp.back();
                temp.pop_back();
            }
            else{
                back = front;
            }

            if(front == back){
                klasemen.erase(klasemen.begin() + (front - 1));
            } else {
                swap(klasemen[front - 1], klasemen[back - 1]);
            }
        }
    }

    (klasemen.size() > 0) ? cout << klasemen.size() << " " << klasemen[0] << endl : cout << "Tidak ada pemenang" << endl;
    return 0;
}