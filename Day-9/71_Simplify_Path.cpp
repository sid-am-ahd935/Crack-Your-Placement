class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string temp = "";
        int i=0;
        path.push_back('/');    // for code simplication, for adding last folder, dirs update only when '/' is found

        while(i < path.size()) {
            if(path[i] == '/') {
                if(temp == "..") {
                    if(!dirs.empty()) dirs.pop_back();
                    temp.pop_back();    // changes .. to . to skip add dir
                }
                if(temp == ".")
                    temp.pop_back();
                if(!temp.empty())
                    dirs.push_back(temp);
                temp = "";
            } else {
                temp.push_back(path[i]);
            }
            i++;
        }

        temp = "";
        for(string d:dirs) {
            temp.push_back('/');
            temp.append(d);
        }
        return temp.empty() ? "/" : temp;
    }
};
