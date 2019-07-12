#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

vector<int> twoSum(vector<int>, int);

int main()
{
    vector<int> input = {150,24,79,50,88,345,3};
    int target = 200;
    vector<int> output = twoSum(input, target);
    cout << output[0] << " " << output[1];
    int c = getchar();
    return 0;
}

vector<int> twoSum(vector<int> nums, int target) {
    vector<int> rv;

    while(nums.size())
    {
        int inSearch = target - nums[nums.size()-1];
        int numsend = nums.size() - 1;
        nums.pop_back();
        auto iter = find(nums.begin(), nums.end(), inSearch);
        if(iter != nums.end())
        {
            rv.push_back(distance(nums.begin(), iter));
            rv.push_back(numsend);
            break;
        }
        else
        {
            rv.clear();
        }
    }
    return rv;
}