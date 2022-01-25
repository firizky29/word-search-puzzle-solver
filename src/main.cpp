/*
Nama    : Firizky Ardiansyah/13520095
Tanggal : 24/01/2022
Kelas   : K02
Tugas Kecil 1 Strategi Algoritma
Penyelesaian Word Search Problem Menggunakan Algoritma
*/


#include <bits/stdc++.h>
using namespace std;
// Color Dictionary 
const string EOS = "\u001b[0m";
string dict[] = {"\u001b[31m", "\u001b[32m", "\u001b[33m", "\u001b[34m", "\u001b[35m", "\u001b[36m", "\u001b[37m", "\u001b[31;1m", "\u001b[32;1m", "\u001b[33;1m", "\u001b[34;1m", "\u001b[35;1m"};

// Global Directiory
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int n, m, l, cntWord;
long long allcomp = 0;
string line;
vector<string> lines, words;
vector<vector<char>> input;
vector<vector<string>> output;
clock_t S, E;

// Interface
void startProgram(){
    cout << dict[2]+"WELCOME!\n"+EOS;
    cout << "============================================================\n";
    cout << "This is a program to solve the well-known puzzle called word-search puzzle\n";
    cout << "Let's Solve Some Problems!\n\n";

}

void inputFile(string& addrIn, string &addrOut){
    cout << "Type Puzzle File You Want to Solve (without .txt): ";
    cin >> addrIn;
    addrOut = "./test/out_"+addrIn+".txt";
    addrIn = "./test/"+addrIn+".txt";
    cout << "Opening " << addrIn << "...\n\n";
    ifstream curIn(addrIn);
    if(!curIn.good()){
        cout << dict[0]+"The puzzle you requested was not found, please try again\n"+EOS;
        inputFile(addrIn, addrOut);
    }
}

// Inisialisasi
void init(string addrIn, string addrOut){
    ifstream in(addrIn);
    
    while(getline(in, line)){
        lines.push_back(line);
    }
    for(auto s: lines){
        if(s.size()!=lines[0].size()){
            if(s[1]!=' '&&s[1]!='\t'){
                while(s.size()>0&&(s.back()==' '||s.back()=='\t'||s.back()=='\n')){
                    s.pop_back();
                }
                if(s.size()!=0){
                    words.push_back(s);
                }
                continue;
            }
        }
        vector<char> cur;
        vector<string> curS;
        for(auto c: s){
            if(c!=' '&&c!='\n'&&c!='\t'){
                cur.push_back(c);
                string sc = "";
                sc += c;
                curS.push_back(sc);             
            }
        }
        input.push_back(cur);
        output.push_back(curS);
    }
    n = input.size();
    m = input[0].size();
    l = words.size();
    in.close();
}

// Create Analysis For One Word
void createSummary(vector<pair<int, int>> coor, ofstream& to, long comp, string word, double duration){
    to << "Searched Word: " << word << "\n";
    vector<vector<char>> res(n, vector<char> (m, '-'));
    for(auto p: coor){
        int x = p.first;
        int y = p.second;
        res[x][y] = input[x][y];
    }
    for(int x=0; x<n; x++){
        string s = "";
        for(int y=0; y<m; y++){
            s += res[x][y];
            if(y==m-1){
                s += '\n';
            }
            else{
                s += ' ';
            }
        }
        to << s;
    }
    to << "Comparison Counts: " << comp << "\n";
    to << "Duration: " << setprecision(10) << duration  << " seconds\n\n";
}

// Colorize Summarized Solution
void colorize(vector<pair<int, int>> coor, int id){
    for(auto p: coor){
        int x = p.first;
        int y = p.second;
        output[x][y] = dict[id]+output[x][y]+EOS;
    }
}


// Main Program
int main() { 
    string addrIn, addrOut;
    startProgram();
    inputFile(addrIn, addrOut);
    init(addrIn, addrOut);
    ofstream out(addrOut);
    out << fixed;
    S = clock();
    for(int i=0; i<l; i++){
        bool found = false;
        long comp = 0;
        clock_t curS, curE;
        curS = clock();
        for(int j=0; j<n&&!found; j++){
            for(int k=0; k<m&&!found; k++){
                allcomp++;
                comp++;
                if(input[j][k] == toupper(words[i][0])){
                    for(int d=0; d<8&&!found; d++){
                        int sz = words[i].size();
                        int boundj = j+(sz-1)*dx[d];
                        int boundk = k+(sz-1)*dy[d];                    
                        bool match = boundj<n&&boundj>=0&&boundk<m&&boundk>=0;
                        vector<pair<int, int>> coor (1, {j, k});
                        int nj = j+dx[d];
                        int nk = k+dy[d];
                        int cnt = 1;
                        while(match&&cnt<sz){
                            if(input[nj][nk]!=toupper(words[i][cnt])){
                                match = false;
                            }
                            else{
                                coor.push_back(make_pair(nj, nk));
                                cnt++;
                                nj += dx[d];
                                nk += dy[d];
                            }
                            allcomp++;
                            comp++;
                        }
                        allcomp++;
                        comp++;
                        if(match&&cnt==sz){
                            curE = clock();
                            double dur = (double) (curE-curS)/(CLOCKS_PER_SEC);
                            createSummary(coor, out, comp, words[i], dur);
                            colorize(coor, i%12);
                            cntWord++;
                            found = true;
                        }
                    }
                }
            }
        }
    }
    E = clock();
    out << "Overall Comparisons: " << allcomp << "\n";
    out << "Overall Excecution Time : ";
    out << setprecision(10) << (double) (E-S)/CLOCKS_PER_SEC << " seconds \n";
    out.close();

    cout << dict[1] << "This is the solution of " << addrIn << "\n\n" << EOS;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << output[i][j] << " \n"[j==m-1];
        }
    }
    cout << "\nTotal Word(s) Found: " << cntWord << "\n";
    cout << "Overall Comparisons: " << allcomp << "\n";
    cout << "Overall Excecution Time : ";
    cout << fixed;
    cout << setprecision(10) << (double) (E-S)/CLOCKS_PER_SEC << " seconds \n";
    cout << dict[2] << "\nYou can also see more detailed solution in " << addrOut << "\n" << EOS;
    return 0;
}