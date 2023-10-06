class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag_one = false, flag_zero = false;
        for(auto& c : s)
        {
            if(c == '1')
            {
                if(flag_zero == true)
                    return false;
                else if(flag_one == false)
                    flag_one = true;
            }
            else if(c == '0')
                flag_zero = true;
        }
        return true;
    }
};