class Solution {
public:
    int romanToInt(string s) {
        map<char,int> values;
values['I'] = 1;
values['V'] = 5;
values['X'] = 10;
values['L'] = 50;
values['C'] = 100;
values['D'] = 500;
values['M'] = 1000;

    int sum=0;
    for(int i=0;i<s.length();++i)
    {
        if(i!=0 && values[s[i]] > values[s[i-1]] )
        {
            sum = sum - 2*values[s[i-1]];
        }
        
        sum = sum + values[s[i]];
            
    }
    
    return sum;
    
}
};