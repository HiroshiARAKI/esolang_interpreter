#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

#include "orders.h"

using namespace std;

char noise(){
    char n = char(rand() % 256);
    if(n != PTR_INCREMENT &&
       n != PTR_DECREMENT &&
       n != BYTE_INCREMENT &&
       n != BYTE_DECREMENT &&
       n != OUTPUT &&
       n != INPUT &&
       n != LOOP_START &&
       n != LOOP_END)
        return n;

    return '\n';
}

vector<char> encode(int ascii){
    vector<char> res;
    res.reserve(256);
    res.emplace_back(PTR_INCREMENT);

    res.emplace_back(noise());

    int loop = 0;
    int rest = ascii;
    if(ascii > 10){
        loop = ascii / 10;  // used as a loop counter
        rest = ascii % 10;
    }

    if(loop > 0) {  // if loop is existed
        for (int i = 0; i < loop; ++i) {
            res.emplace_back(noise());
            res.emplace_back(BYTE_INCREMENT); // ++ ... +  loop counter
        }
        res.emplace_back(noise());
        res.emplace_back(LOOP_START); // [  loop start
        res.emplace_back(BYTE_DECREMENT); // -  decrement loop counter
        res.emplace_back(PTR_INCREMENT);  // >  move the pointer to main
        res.emplace_back(noise());
        res.emplace_back(noise());
        for (int j = 0; j < 10; ++j) {
            res.emplace_back(noise());
            res.emplace_back(BYTE_INCREMENT);  // 10 times +
            res.emplace_back(noise());
        }
        res.emplace_back(PTR_DECREMENT);  // move to loop counter pointer
        res.emplace_back(noise());
        res.emplace_back(LOOP_END);  // ]
        res.emplace_back(PTR_INCREMENT);  // move next pointer
    }

    for(int i = 0; i < rest; ++i){
        res.emplace_back(BYTE_INCREMENT);
        res.emplace_back(noise());
    }
    res.emplace_back(OUTPUT);
    return res;
}

int main(int argc, char* argv[]){
    random_device rnd;

    try{

        if(argc < 2){
            throw invalid_argument("Oops! There are no files.");
        }

        string filename = argv[1];
        ifstream ifs(filename);

        if(ifs.fail()){
            throw invalid_argument("The file does not exist.");
        }

        // Read file
        int begin = static_cast<int>(ifs.tellg());

        ifs.seekg(0, ifs.end);
        int end = static_cast<int>(ifs.tellg());
        int size = end - begin;
        ifs.clear();  // clear EOF flag

        ifs.seekg(0, ifs.beg);
        char *original = new char[size + 1];
        original[size] = '\0';
        ifs.read(original, size);
        ifs.close();

        cout << "Original : " << original << endl;
        cout << "Size     : " << size << endl;

        // convert to ascii codes
        int ascii[size];
        for(int i = 0; i < size; ++i){
            ascii[i] = int(original[i]);
        }

        // out
        string out_file;
        if(argc < 3) {
            out_file = "a.bf";
        }else{
            out_file = argv[2];
        }

        ofstream ofs(out_file);
        if(ofs.fail()){
            throw invalid_argument("Failed to open output file.");
        }

        for(auto a : ascii){
            auto code = encode(a);
            for(auto c : code)
                ofs << c;
        }
        ofs << '\n';
        ofs.close();
        cout << "Done!" << endl;

    }catch (exception& e){
        cerr << e.what() << endl;
        return -1;
    }


    return 0;
}