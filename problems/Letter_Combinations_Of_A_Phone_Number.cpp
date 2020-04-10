/**
 * This is a DFS problem, or backtracing problem and can be solved by
 * using recursion. The idea is the combination can be represented by
 * combination+current letter, and process the following string using
 * recursion as shown in the code backtrack(comb+letter,
 * digits.substr(1, digits.size()-1));
 */



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() != 0) {backtrack("", digits);}
        return res;
    }

    void backtrack(string comb, string digits) {
        if (digits.size() == 0) {res.push_back(comb);}
        else {
            auto map = getMap();
            char digit = digits[0];
            string letters = map[digit];
            for (int i = 0; i < letters.size(); ++i) {
                char letter = letters[i];
                backtrack(comb+letter, digits.substr(1, digits.size()-1));
            }
        }
    }
private:
    unordered_map<char, string> getMap() {
        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        return map;
    }

    vector<string> res;


};
