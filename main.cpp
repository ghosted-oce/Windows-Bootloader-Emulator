#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to read the boot sector of an MBR
void ReadBootSector(string filename)
{
    ifstream mbr_file(filename);
    if (mbr_file.is_open())
    {
        char buffer[512];
        mbr_file.read(buffer, 512);
        cout << "Boot Sector: \n";
        for (int i = 0; i < 512; i++)
        {
            cout << buffer[i];
        }
        cout << endl;
    }
    else
    {
        cout << "Error opening file \n";
    }
    mbr_file.close();
}

// Function to parse the MBR and extract the partition table
void ParsePartitionTable(string filename)
{
    ifstream mbr_file(filename);
    if (mbr_file.is_open())
    {
        char buffer[512];
        mbr_file.read(buffer, 512);
        cout << "Partition Table: \n";
        for (int i = 446; i < 486; i++)
        {
            cout << buffer[i];
        }
        cout << endl;
    }
    else
    {
        cout << "Error opening file \n";
    }
    mbr_file.close();
}

int main()
{
    string mbr_file_name = "mbr.bin";
    ReadBootSector(mbr_file_name);
    ParsePartitionTable(mbr_file_name);
    return 0;
}
