#include <string.h>

class Solution {
public:
    bool isNum(string word){
        for(int i = 0; i < word.length(); i++){
            if(!isdigit(word[i]))
                return false;
        }
        return true;
    }

    string validIPAddress(string IP) {
        if(IP == ""){
            return "Neither";
        }
        string ipAddress = "";
        
        vector<string> ipv4;
        
        stringstream str1(IP);
        string token = "";
        while(getline(str1, token, '.')){
            ipv4.push_back(token);
        }
        if(ipv4[0] == IP)
            ipv4.clear();
        else{
            if(IP[IP.length() - 1] == '.')
                return "Neither"; 
        }
        
        vector<string> ipv6;
        stringstream str2(IP);
        token = "";
        while(getline(str2, token, ':')){
            ipv6.push_back(token);
        }
        if(ipv6[0] == IP)
            ipv6.clear();
        else{
            if(IP[IP.length() - 1] == ':')
                return "Neither";
        }
        
        if(ipv4.size() > 0 && ipv6.size() > 0){
            return "Neither";
        }
        
        if(ipv4.size() == 4){
            for(int i = 0; i < ipv4.size(); i++){
                if(ipv4[i] == ""){
                    ipAddress = "Neither";
                    return ipAddress;
                }
                bool one = isNum(ipv4[i]);
                bool two = false;
                if(ipv4[i] != "" && ipv4[i][0] == '0'){
                    if(ipv4[i].size() > 1)
                        two = true;
                }
                if(one && !two){
                    long long num;
                    istringstream ss(ipv4[i]);
                    ss >> num;
                    if(!(num >= 0 && num <= 255)){
                        ipAddress = "Neither";
                        return ipAddress;
                    }                        
                }
                else{
                    ipAddress = "Neither";
                    return ipAddress;
                }
            }
            ipAddress = "IPv4";
        }    
        else if(ipv6.size() == 8){
            for(int i = 0; i < ipv6.size(); i++){
                if(ipv6[i] == ""){
                    ipAddress = "Neither";
                    return ipAddress;
                }
                string::size_type x = 0;
                while(isxdigit(ipv6[i][x])){
                    x++;
                }
                if(x != ipv6[i].length() || !(1 <= ipv6[i].length() && ipv6[i].length() <= 4)){
                    ipAddress = "Neither";
                    return ipAddress;
                }
            }
            ipAddress = "IPv6";
        }
        else{
            ipAddress = "Neither";
        }
        return ipAddress;
    }
};
