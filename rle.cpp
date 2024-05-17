#include <iostream>
#include <fstream>

using namespace std;
// Function to open a file and read its content into a string
string open(string fname)
{
    ifstream file(fname);
    string S,line;

    if (file.is_open()) {
        while (getline(file, line)) {
            S += line;        // Concatenate the lines into a single string
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }
   
    cout << "File content: " << S << endl;
    return S;                 // Return the content of the file as a string
}
// Function to write a string to a file
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
// Function to perform Run-Length Encoding
void Encode(std::string &inputstring, std::string &outputstring)
{
    for (int i = 0; i < inputstring.length(); i++) {
        int count = 1;
        while (inputstring[i] == inputstring[i+1]) {     // Count consecutive occurrences of the same character
            count++;
            i++;
        }
        if(count <= 1) {
            outputstring += inputstring[i];             // Append the character to the output string
        } else {
            outputstring += std::to_string(count);
            outputstring += inputstring[i];
        }
    }
}
// Function to perform Run-Length Decoding
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
            original += compressed[i];       //end the character to the original string
        }
    }
}

int main() {
    string ifname;
    cout<<"Welcome to the Project, this project aims to develop a custom file extension aiming to losslessly compress text file (Currently RLE employed)"<<endl<<endl;
    cout<<"Enter the input filename: ";
    cin>>ifname;
    

    std::string S = open(ifname);
    std::string compressedString;
    Encode(S, compressedString);       // Compress the input string using Run-Length Encoding
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
