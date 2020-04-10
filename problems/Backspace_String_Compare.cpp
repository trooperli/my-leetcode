/**
 * This problem is solved by building 2 extra strings and compare
 * them. When we meet '#' we pop_back, otherwise we push_back.
 */



class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string S_cp;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '#' and S_cp.size() != 0) {S_cp.pop_back();}
            else if (S[i] != '#'){S_cp.push_back(S[i]);}
        }

        string T_cp;
        for (int i = 0; i < T.size(); ++i) {
            if (T[i] == '#' and T_cp.size() != 0) {T_cp.pop_back();}
            else if (T[i] != '#'){T_cp.push_back(T[i]);}
        }

        return (T_cp == S_cp);

    }
};
