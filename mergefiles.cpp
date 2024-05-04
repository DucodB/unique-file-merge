#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>  

using namespace std;

//read the contents of a file into a vector of strings where each line is a seperate element
vector<string> readFile(string fileName) {
    ifstream file(fileName);
    if(!file.is_open()) {
        cerr << "Cannot open file: " << fileName << endl;
    }

    //read each line seperately into fileContents vector
    vector<string> fileContents;
    string line;
    while(getline(file, line)) {
        fileContents.push_back(line);
    }
    
    file.close();
    return fileContents;
}

//write resulting set to file
void writeResult(const set<string>& resultSet, string fileName) {
    ofstream file(fileName);
    if(!file.is_open()) {
        cerr << "Cannot write to file: " << fileName << "\n";
        return;
    }
    for (const auto& syscall : resultSet) {
            file << syscall << endl;
    }
    file.close();
    cout << "Results written to file: " << fileName << endl;
    return;
}

int main(int argc, char *argv[])
{
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " [output file] [file1] [file2] ... [fileN]" << endl;
        return 1;
    }

    set<string> resultSet;
    for(int i = 2; i < argc; i++) {
        string fileName = argv[i];
        auto fileContents = readFile(fileName);
        resultSet.insert(fileContents.begin(), fileContents.end());
    }
 
    //write result to output file.
    writeResult(resultSet, argv[1]);
   
    return 0;
}