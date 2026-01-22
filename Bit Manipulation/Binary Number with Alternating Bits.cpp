class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = "";
    while (n > 0)
    {
        s += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    reverse(s.begin(), s.end());

    bool chk = true;

    for(int i = 0; i < s.size(); i += 2)
    {
        if(s[i] == '0')
        {
            chk = false;
            break;
        }
    }

    for(int i = 1; i < s.size(); i += 2)
    {
        if(s[i] == '1')
        {
            chk = false;
            break;
        }
    }

    return chk;
    }
};
