#include <bits/stdc++.h>

using namespace std;

int pairman(vector<int> nums, int l, int r)
{
    int count = 0;
    int l_num = min(nums[l-1], nums[r-1]);
    int r_num = max(nums[l-1], nums[r-1]);


    unordered_set<int> nums_set;
    sort(nums.begin(), nums.end());
    copy(nums.begin(), nums.end(), inserter(nums_set, nums_set.begin()));
    

    for(int i = l-1; i < r; i++){
        for(int j = 1; j <= sqrt(nums[i]); j++){
            if(nums[i] % j == 0){
                if(nums[i]/j == j){
                    continue;
                }

                if(nums_set.find(j) != nums_set.end() 
                && nums_set.find(nums[i]/j) != nums_set.end()){
                    if(nums[i] >= l_num && nums[i] <= r_num){
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main(){
    int b, q;
    cin >> b >> q;

    vector<int> A(b);
    for (int i = 0; i < b; i++){
        cin >> A[i];
    }


    vector<int> ans;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;

        ans.push_back(pairman(A, l, r));
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}