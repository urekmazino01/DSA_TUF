#include<iostream>
#include<vector>
using namespace std;

int triangleNumber(vector<int>& nums) {

        int cnt =0 ;
        sort(nums.begin(),nums.end());

        for(int i=2;i<nums.size();i++){
            int left = 0;
            int right = i-1;

            while(left<right){
                if(nums[i]<nums[left]+nums[right]){
                    cnt +=(right-left);
                    right--;                    

                }else{
                    left++;
                }

            }
        }

        return cnt;
        
}

int main(){

    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        cout<<triangleNumber(nums)<<endl;
    }
    return 0;
}