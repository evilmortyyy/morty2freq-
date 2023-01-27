#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<unsigned char> hexToByteArray(string input_hash)
{
    vector<unsigned char> byteArray;
    for (unsigned int i = 0; i < input_hash.length(); i += 2)
    {
        string byteString = input_hash.substr(i, 2);
        unsigned char byte = (unsigned char) strtol(byteString.c_str(), NULL, 16);
        byteArray.push_back(byte);
    }
    return byteArray;
}

int main(int argc, char* argv[])
{
    string input_hash;
    if(argc>1)
    {
        input_hash=argv[1];
    }
    else
    {
        cout<<"Enter the input hash:";input_hash;
    }
    vector<unsigned char> byte_array = hexToByteArray(input_hash);
    vector<int> frequencies;

    for (unsigned int i = 0; i < byte_array.size(); i++)
    {
        int frequency = byte_array[i] * 20; // mapping each byte of RICK to a frequency
        frequencies.push_back(frequency);
    }
    cout<<"Frequency: ";
    for(int i=0;i<frequencies.size();i++)
    {
        cout<<frequencies[i]<<" ";
    }
    cout<<endl;
    return 0;
}
