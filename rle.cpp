#include <iostream>
#include <fstream>

using namespace std;

string open(string fname)
{
    ifstream file(fname);
    string S,line;

    if (file.is_open()) {
        while (getline(file, line)) {
            S += line;
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }
   
    cout << "File content: " << S << endl;
    return S;
}

void writef(string fname, string S)
{
    ofstream file(fname);

    if (file.is_open()) {
        file<<S;
        file.close();
        }
    else {
        cerr << "Unable to open file";
        return;
    }
   
    cout << "Successfully Written to file." << endl;
}

void Encode(std::string &inputstring, std::string &outputstring)
{
    for (int i = 0; i < inputstring.length(); i++) {
        int count = 1;
        while (inputstring[i] == inputstring[i+1]) {
            count++;
            i++;
        }
        if(count <= 1) {
            outputstring += inputstring[i];
        } else {
            outputstring += std::to_string(count);
            outputstring += inputstring[i];
        }
    }
}

void Decompress(std::string &compressed, std::string &original)
{
    for (int i = 0; i < compressed.length(); i++) {
        if (isdigit(compressed[i])) {
            int count = compressed[i] - '0';
            for (int j = 0; j < count; j++) {
                original += compressed[i + 1];
            }
            i++;
        } else {
            original += compressed[i];
        }
    }
}

int main() {
    string ifname;
    cout<<"Enter the input filename: ";
    cin>>ifname;
    

    std::string S = open(ifname);
    std::string compressedString;
    Encode(S, compressedString);
    std::cout << "Compressed String: " << compressedString << std::endl;

    std::string decompressedString;
    Decompress(compressedString, decompressedString);
    std::cout << "Decompressed String: " << decompressedString << std::endl;
    
    string ofname;
    cout<<"Enter the output filename: ";
    cin>>ofname;

    writef(ofname, decompressedString);

    return 0;
}