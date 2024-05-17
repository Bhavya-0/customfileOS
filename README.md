# customfileOS
Custom file extension inclusing compresion and (possibly) cryptography

This project report documents a text file compression tool designed to compress text files losslessly using Run-Length Encoding (RLE). The tool allows users to specify input and output filenames and performs both compression and decompression of text data.
----------------------------------------------------Main Function-----------------------------------------------------------------------------
The main function guides the user interaction. It welcomes the user, explains the project's purpose, and prompts for the input filename.
It reads the file content using open, performs compression using Encode, displays the compressed string, decompresses using Decompress, displays the decompressed string, prompts for the output filename, and writes the decompressed data to the output file using writef.
----------------------------------------------------Implementation---------------------------------------------------------------------------
The Encode function iterates through the input string, keeping track of consecutive character occurrences. If a character repeats, it counts the occurrences and appends the count (converted to string) followed by the character to the output string. Single characters are directly appended. The Decompress function processes the compressed string, identifying digits as counts. For each digit, it extracts the count value, repeats the following character that many times in the original string, and moves on to the next character.

-------------------------------------------------Layered Algorithm---------------------------------------------------------------------------
