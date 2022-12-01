//
//  Day1.cpp
//  aoc-2022
//
//  Created by Sanjin Grahovar Sadiković on 01.12.2022..
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#include <unistd.h> // for getcwd()


class Day1{
private:
    std::vector<int> input1;
    std::vector<int> input2;
    
public:
    Day1(){
        
    }
    
    std::vector<int> loadInput(std::string inputFile){
        std::vector<int> inputList;
        
        std::ifstream file(inputFile);
        std::string str;
                
        if (file.is_open()) {
            while(std::getline(file, str)){
                if(str != ""){
                    inputList.push_back(std::stoi(str));
                }
                else {
                    inputList.push_back(-1);
                }
            }
        }

        return inputList;
    }
    
    int solveFirst(){
        this->input1 = loadInput("Day1/input_first.txt");
        
        std::cout << "Input 1: " << input1[0] << std::endl;
        
        int max = 0;
        int tmp_max = 0;
        
        for(int i = 0; i < input1.size(); i++){
            if(input1[i] != -1){
                tmp_max += input1[i];
            }
            
            else{
                if(tmp_max > max) max = tmp_max;
                tmp_max = 0;
            }
        }
        
        return max;
    }
    
    int solveSecond(){
        this->input2 = loadInput("Day1/input_first.txt");
        
        std::vector<int> *max = new std::vector<int>(5, 0);
        int tmp_max = 0;
                        
        for(int i = 0; i < input2.size(); i++){
            if(input2[i] != -1){
                tmp_max += input2[i];
            }
            
            else{
                for(int j = 2; j >= 0; j--){
                    // std::cout << "j: " << j << std::endl;
                    if(tmp_max > max->at(j)) {
                        max->at(j+1) = max->at(j);
                        max->at(j) = tmp_max;
                        // std::cout << "max at " << j << ": " << max->at(j) << std::endl;
                    }
                }
                tmp_max = 0;
            }
        }
        
        return max->at(0) + max->at(1) + max->at(2);
    }
    
};
