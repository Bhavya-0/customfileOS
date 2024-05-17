# customfileOS
Custom file extension inclusing compresion and (possibly) cryptography
--------------------------------------------------Overview--------------------------------------------------------------------------------
This program implements a simple file compression and decompression utility using a Run-Length Encoding (RLE) algorithm. It aims to losslessly compress text files by encoding repeated consecutive characters as a single character followed by a count of its occurrences. The compressed file can then be decompressed to recover the original content.


------------------------------------Run-Length Encoding (RLE) algorithm-------------------------------------------------------------------
Run-Length Encoding (RLE) is like a secret code for messages where you have to say how many times a letter appears in a row.
Imagine you have a long message with many repeated letters, like "AAAABBBCCDAA". Instead of writing every single letter, you can use RLE to make it shorter.

----Let's use the example "AAAABBBCCDAA":

The first letter is 'A'. It repeats 4 times in a row. So, instead of writing "AAAA", you write "A4".
Then comes 'B'. It repeats 3 times in a row. So, instead of writing "BBB", you write "B3".
'C' repeats 2 times, so you write "C2".
'D' appears only once, so you write "D1".
Finally, 'A' repeats 2 times, so you write "A2".

Putting it all together, the compressed message becomes "A4B3C2D1A2".

----Now, to decode the message:

You look at each pair of a letter and a number.
If the number is 1, you write down the letter once.
If the number is greater than 1, you write down the letter as many times as the number indicates.
So, "A4B3C2D1A2" becomes "AAAABBBCCDAA" again.


------------------------------------------------------------------------------------------------------------------------------------------
This program takes a text file as input, compresses its content using the RLE algorithm, displays the compressed content, decompresses it back to its original form, and writes the decompressed content to an output file specified by the user.
------------------------------------------------------------------------------------------------------------------------------------------

1.It prompts the user to enter the input filename.
2.It calls the open function to read the content of the input file into the string S.
3.It calls the Encode function to compress the input string S, storing the compressed string in compressedString.
4.It displays the compressed string.
5.It calls the Decompress function to decompress the compressed string compressedString, storing the decompressed string in decompressedString.
6.It displays the decompressed string.
7.It prompts the user to enter the output filename.
8.It calls the writef function to write the decompressed string decompressedString to the output file specified by the user.
