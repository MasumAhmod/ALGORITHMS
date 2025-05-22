class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int p1 = 0 , p2 = 0;

        while(1){
            if(p1 >= name.size() && p2 >= typed.size()){
                return true;
            }

            if(p1 >= name.size()){
                if(typed[p2] == name.back()){
                    p2++;
                    continue;
                } else {
                    return false;
                }
            }

            if(p2 >= typed.size()){
                return false;
            }

            if(name[p1] == typed[p2]){
                p1++;
                p2++;
            } else {
                if(p1 == 0){
                    return false;
                } else if(name[p1 - 1] == typed[p2]){
                    p2++;
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
