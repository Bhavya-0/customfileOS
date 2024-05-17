#include <iostream>
#include <fstream>

using namespace std;
// Function to open a file and read its content into a string
string open(string fname)
{
    ifstream file(fname);  // Open the file
    string S,line;

    if (file.is_open()) {     // Check if the file is successfully opened
        while (getline(file, line)) {   // Read each line of the file
            S += line;                  // Concatenate the lines into a single string
        }
        file.close();                   // Close the file after reading
    } else {
        std::cout << "Unable to open file";      // Display error message if file opening fails
    }
   
    cout << "File content: " << S << endl;       // Display the content of the file
    return S;                                    // Return the content of the file as a string
}
// Function to write a string to a file

void writef(string fname, string S)
{
    ofstream file(fname);     // Open the file for writing

    if (file.is_open()) {     // Check if the file is successfully opened
        file<<S;              // Write the string to the file
        file.close();         // Close the file after writing
        }
    else {
        cerr << "Unable to open file";      // Display error message if file opening fails
        
        return;
    }
   
    cout << "Successfully Written to file." << endl;     // Display success message after writing
}
// Function to perform Run-Length Encoding
void Encode(std::string &inputstring, std::string &outputstring)
{
    for (int i = 0; i < inputstring.length(); i++) {     // Iterate through the characters of the input string
        int count = 1;                                   // Initialize count of consecutive characters
        while (inputstring[i] == inputstring[i+1]) {     // Count consecutive occurrences of the same character
            count++;
            i++;
        }
        if(count <= 1) {                                // If only one occurrence of the character
            outputstring += inputstring[i];             // Append the character to the output string
        } else {                                        // If multiple consecutive occurrences of the character
            outputstring += std::to_string(count);      // Append the count to the output string
            outputstring += inputstring[i];             // Append the character to the output string
        }
    }
}
// Function to perform Run-Length Decoding
void Decompress(std::string &compressed, std::string &original)
{
    for (int i = 0; i < compressed.length(); i++) {              // Iterate through the characters of the compressed string
        if (isdigit(compressed[i])) {                            // If the character is a digit (indicating count)
            int count = compressed[i] - '0';                      // Convert the digit character to integer count
            for (int j = 0; j < count; j++) {                     // Repeat the next character count times
                original += compressed[i + 1];                    // Append the next character to the original string
            }
            i++;
        } else {
            original += compressed[i];                            // Append the character to the original string
        }
    }
}

int main() {
    string ifname;
    cout<<"Welcome to the Project, this project aims to develop a custom file extension aiming to losslessly compress text file (Currently RLE employed)"<<endl<<endl;
    cout<<"Enter the input filename: ";
    cin>>ifname;
    

    std::string S = open(ifname);              // Read the content of the input file into a string
    std::string compressedString;
    Encode(S, compressedString);               // Compress the input string using Run-Length Encoding
    std::cout << "Compressed String: " << compressedString << std::endl;        // Display the compressed string

    std::string decompressedString;
    Decompress(compressedString, decompressedString);                // Decompress the compressed string
    std::cout << "Decompressed String: " << decompressedString << std::endl;   // Display the decompressed string
    
    string ofname;
    cout<<"Enter the output filename: ";
    cin>>ofname;

    writef(ofname, decompressedString);     // Write the decompressed string to the output file

    return 0;
}
