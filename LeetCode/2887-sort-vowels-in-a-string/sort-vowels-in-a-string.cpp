class Solution {
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (auto c : s)
            if (isVowel(c)) vowels.emplace_back(c);
        // std::cout << "Before sorting\n";
        // for (auto v : vowels)
        //     std::cout << v << " ";
        sort(vowels.begin(), vowels.end());
        // std::cout << "\nAfter sorting\n";
        // for (auto v : vowels)
        //     std::cout << v << " ";
        int k = 0;
        for (auto& c : s)
            if (isVowel(c)) c = vowels[k++];
        return s;
    }
};