class KthLargest
{
    int k;
    vector<int> nums;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        this->nums = nums;
        if (!this->nums.empty())
            sort(this->nums.begin(), this->nums.end(), greater<>());
    }

    int add(int val)
    {
        bool flag = false;
        for (int i = 0, length = nums.size(); i < length; i++)
        {
            if (val > nums[i])
            {
                nums.insert(nums.begin() + i, val);
                flag = true;
                break;
            }
        }
        if (!flag)
            nums.push_back(val);
        return nums[k - 1];
    }
};