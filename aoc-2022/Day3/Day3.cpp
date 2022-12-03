//
//  Day2.cpp
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
#include <cctype>


#include <unistd.h> // for getcwd()


class Day3{
private:
    std::vector<std::string> input1;
    std::vector<std::string> input2;
    
public:
    Day3(){
        
    }
    
    
    std::vector<std::string> loadInput(std::string inputFile){
        std::vector<std::string> inputList;
        
        std::ifstream file(inputFile);
        std::string str;
                
        if (file.is_open()) {
            while(std::getline(file, str)){
                inputList.push_back(str);
            }
        }

        return inputList;
    }
    
    int solveFirst(){
        this->input1 = loadInput("Day3/input_first.txt");
        // this->input1 = loadInput("Day3/input_example.txt");
        std::vector<int> tmpArray;
        int sumOfPriorities = 0;
        
        for(int i = 0; i < input1.size(); i++){
            std::cout << input1[i] << std::endl << input1[i].substr(0, input1[i].size()/2) << " " << input1[i].substr(input1[i].size()/2, input1[i].size()) << std::endl;
        }
        std::cout << "Result: " << std::endl;
        
        
        for(int i = 0; i < input1.size(); i++){
            for(int j = 0; j < input1[i].size() / 2; j++){
                for(int k = input1[i].size() / 2; k <= input1[i].size(); k++){
                    if(input1[i][j] == input1[i][k]){
                        
                        // j++;
                        if (std::find(tmpArray.begin(), tmpArray.end(), input1[i][j]) == tmpArray.end()){
                            tmpArray.push_back(input1[i][j]);
                            std::cout << "Same - " << input1[i][j] << std::endl;
                            
                            if(isupper(input1[i][j])){
                                std::cout << "Upper case - " << ((int(input1[i][j])) - 38) << std::endl;
                                sumOfPriorities += ((int(input1[i][j])) - 38);
                                // break;
                            }
                            else {
                                std::cout << "Lower case - " << ((int(input1[i][j])) - 96) << std::endl;
                                sumOfPriorities += ((int(input1[i][j])) - 96);
                                // break;
                            }
                            
                            std::cout << "Sum: " << sumOfPriorities << std::endl;
                            // j++;
                            break;
                        }
                        
                    }
                    
                }
            }
        }
        
        return sumOfPriorities;
    }
    
    int solveSecond(){
        this->input2 = loadInput("Day3/input_first.txt");
        int total_score = 0;
        
        return 0;
    }
};
