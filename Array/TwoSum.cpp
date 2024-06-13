#include<bits/stdc++.h>
using namespace std;

//BruteForce Approach
//Time complexity: O(n*n)

vector<int>twoSum(vector<int>& nums, int target){
    int n = nums.size();

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i]+nums[j] == target){
                return {i,j};
            }
        }
    }
    return {};
}


//Sorting + Two Pointer Approach
//Time complexity: O(nlogn)

vector<int>twoSum(vector<int>& nums, int target){
    int n = nums.size();

    int a[n];
    for(int i=0; i<n; i++){
        a[i] = nums[i];
    }

    vector<int>v;
    sort(nums.begin(), nums.end());

    int l=0, r=n-1;
    while(l<r){
        if(nums[l] + nums[r] == target){
            break;
        }
        else if(nums[l] + nums[r] < target){
            l++;
        }
        else{
            r--;
        }
    }

    for(int i=0; i<n; i++){
        if(nums[i] == a[i]){
            v.push_back(i);
        }
        else if(nums[r] == a[i]){
            v.push_back(i);
        }
    }
    return v;
    
}



// //optimized Approach(using map)
// //Time complexity: O(n)

vector<int>twoSum(vector<int>& nums, int target){

    int n = nums.size();
    unordered_map<int, int>map;
    vector<int>res;

    for(int i=0; i<n; i++){
        if(map.find(target - nums[i]) != map.end()){
            res.push_back(map[target - nums[i]]);
            res.push_back(i);
            return res;
        }else{
            map[nums[i]] = i;
        }
    }
    return res;
}
