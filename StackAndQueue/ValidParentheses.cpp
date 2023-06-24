class Solution {
public:
    bool isValid(string s) {
        stack<char> newstack;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                newstack.push(s[i]);
            }else{
                if(s[i] == ')'){
                    if(newstack.size()){
                        if(newstack.top() != '('){
                            return false;
                        }
                        newstack.pop();
                    }else{
                        return false;
                    }
                }else if(s[i] == '}'){
                    if(newstack.size()){
                        if(newstack.top() != '{'){
                            return false;
                        }
                        newstack.pop();
                    }else{
                        return false;
                    }
                }else if(s[i] == ']'){
                    if(newstack.size()){
                        if(newstack.top() != '['){
                            return false;
                        }
                        newstack.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(!newstack.size()){
            return true;
        }else{
            return false;
        }
    }
};