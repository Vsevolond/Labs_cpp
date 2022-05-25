#include <iostream>
#include <dirent.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string path = "/Users/vsevolod/Documents/Labs_cpp/OpenDir/test/";

string get_ext (const string& st) {
    size_t pos = st.rfind('.');
    if (pos <= 0) return "";
    return st.substr(pos+1, string::npos);
}

string change_string(string s){
    size_t pos = s.find("\\b");
    if (pos != string::npos) {
        s.replace(pos, 2, "\\i");
    } else {
        pos = s.find("\\i");
        if (pos != string::npos) {
            s.replace(pos, 2, "\\b");
        }
    }
    return s;
}

void change_file(const string& file){
    string s;
    vector <string> file_data;
    ifstream f_from (string(path) + "/" + string(file));
    while(getline(f_from, s)){
        file_data.push_back(s);
    }
    f_from.close();
    ofstream f_to (string(path) + "/" + string(file));
    for (auto & x : file_data){
        f_to << change_string(x) << endl;
    }
    f_to.close();
    cout << file << endl;
}

int main() {

    DIR *mydir = opendir(path.c_str());

    struct dirent *catalog = readdir(mydir);
    while (catalog) {
        string expansion = get_ext(catalog->d_name);
        if (expansion == "rtf") {
            change_file(catalog->d_name);
        }
        catalog = readdir(mydir);
    }

    closedir(mydir);

    return 0;
}
