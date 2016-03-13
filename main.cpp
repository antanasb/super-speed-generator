#include <fstream>
#include <string>

using namespace std;

const int CMax = 1000; // Pop. žodžių sąrašo ilgis
const int CLev = 100; // Lygių kiekis
const int CWordsL = 6; // Žodžių aibė lygyje eilutėje
const int CLLen = 10; // Žodžių skaičius skaitymo eilutėje
const int CLNum = 3; // Eilučių skaičius lygyje (be antraštės)
const string CIF = "PopŽodžiai.txt";
const string COF = "SuperGreitis.txt";
/*
void read(const string CIF, string words[CMax], int & sw);
void write(const string COF, string sSpeed[CMax], const int CLev);
string biuldLine(string wLine[CWordsL], int n);
string buildLev(string wLine[CWordsL]);
void buildSS(string words[CMax], int & sw, string sSpeed[CMax]);
*/
void read(const string, string*, int&);
void write(const string, string*, const int);
string biuldLine(string*, int);
string buildLev(string*);
void buildSS(string*, int&, string*);

//=================================================
int main()
{
    int sw; // Pop. žodžių kiekis
    string words[CMax], // žodžių talpykla
        sSpeed[CMax]; // skaitymo eilučių talpykla

    read(CIF, words, sw);
    buildSS(words, sw, sSpeed);
    write(COF, sSpeed, CLev);

    return 0;
}

//----------------------------------------------
void read(const string CIF, string words[CMax], int & sw) {
    ifstream in(CIF);
    in >> sw;
    for(int i = 0; i < sw; i++) {
        in >> words[i];
    }
    in.close();
}

//----------------------------------------------
void write(const string COF, string sSpeed[CMax], int ss) {
    ofstream out(COF);
    for(int i = 0; i < ss-5; i++) {
        out << i+6 << " lygis: ";
        out << sSpeed[i] << endl;
    }
    out.close();
}

//----------------------------------------------
string buildLine(string wLine[CWordsL], int n) {
    string line = "";
    string words[CLLen];
    int forw = 1, w = 0;

    // žodžių seka
    int j = 0;
    int x = CWordsL - 1;
    for(int i = 0; i < CLLen; i++) {
        if(i < x) words[i] = wLine[i];
        else if(i == x) words[i] = wLine[x];
        else { words[i] = wLine[x-j]; j++;}
    }
// priešinga kryptis antroje eilutėje
if(n == 2) {forw = -1; w = CLLen-1;}

while(w < CLLen && w >= 0) {
    line += words[w];
    if(n == CLNum && w == CLLen-1) line += ".";
        else  line += ", ";
    w += forw;
    }
    return line;
}

//----------------------------------------------
string buildLev(string wLine[CWordsL]) {
    string lev = "";
    wLine[CWordsL-1] = "*" + wLine[CWordsL-1];

    for(int j = 0; j < CWordsL; j++) {
        lev = lev + wLine[j] + ", ";
    }
    lev += "\n";
    for(int i = 1; i <= CLNum; i++) {
        lev += buildLine(wLine, i) + "\n";
    }
    return lev;
}

//----------------------------------------------
void buildSS(string words[CMax], int & ss, string sSpeed[CLev]) {
    string lin[CWordsL],
        lev[CLNum];
    for(int i = 0; i < CLev-5; i++) {
        for(int j = 0; j < CWordsL; j++) lin[j] = words[i+j];
            sSpeed[i] = buildLev(lin);
    }
}
