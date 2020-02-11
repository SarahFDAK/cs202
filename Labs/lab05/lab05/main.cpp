//
//  main.cpp
//  lab05
//
//  Created by Sarah Carter on 2/11/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using std::ifstream;
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    int read = 0;
    int count = 0;
    int sum = 0;
    std::vector<int> holder;
    ifstream fin("data.dat", std::ios::binary);
    if(!fin){
        if(fin.eof()){
            cout << "End of file" << endl;
            return 0;
        }
        else{
            cout << "Error opening file" << endl;
            return 9;
        }
    }
    fin.seekg(0,std::ios_base::seekdir::end);
    count =  fin.tellg()/sizeof(int);
    fin.seekg(0,std::ios_base::seekdir::beg);
    for(int i = 0; i < count; i++){
        fin.read(reinterpret_cast<char*>(&read), sizeof(read));
        holder.push_back(read);
        sum += holder[i];
    }
    cout << count << " integers,\nTotal: " << sum << "\nAverage: " << static_cast<double>(sum)/count << endl;
    return 0;
}
