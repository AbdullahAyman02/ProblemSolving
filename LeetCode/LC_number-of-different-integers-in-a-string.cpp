class Solution {
public:
    int numDifferentIntegers(string words) {
        unordered_set<int> s;
        long long int x = 0;
        bool flag = false;
        for(int i=0;i<words.length();i++)
        {
            if(words[i]>='0' && words[i] <='9')
            {
                x=x*10+(words[i]-'0');
                x%=1000000007;
                flag=true;
            }
            else
            {
                if(flag==true)
                    s.insert(x);
                flag=false;
                x=0;
            }
        }
        if(flag==true)
            s.insert(x);
        return s.size();
    }
};