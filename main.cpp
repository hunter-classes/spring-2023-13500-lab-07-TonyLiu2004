#include <iostream>
#include <fstream>
using namespace std;

string removeLeadingSpaces(string);
int countChar(string line, char c);

int main(){
    ifstream fin("bad.cpp");
    ofstream ret("fixed.cpp");
    int open_brackets = 0;
    string a;
    while(getline(fin,a)){
        bool close = false;
        a=removeLeadingSpaces(a);
        if(a[0] == '}'){
            close = true;
            open_brackets -= 1;}
        for(int i = 0 ; i < open_brackets; i++){
            ret <<"\t";
        }
        ret<<a<<"\n";
        open_brackets += countChar(a,'{');
        if(!(close)){
            open_brackets -= countChar(a,'}');
        }
    }
    fin.close();
    ret.close();
    return 0;
}
int countChar(string line, char c){
    int i = 0;
    for(char x : line){
        if(x == c){
            i++;
        }
    }
    return i;
}

string removeLeadingSpaces(string line){
    string ret = "";
    for(int i = 0;i < line.length();i++){
        if(isspace(line[i])){
            continue;
        }
        else{
            ret = line.substr(i,line.length()-i);
            break;
        }
    }
    return ret;
}