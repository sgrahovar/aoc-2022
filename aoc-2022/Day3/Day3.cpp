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
            tmpArray.clear();
            for(int j = 0; j < input1[i].size() / 2; j++){
                for(int k = input1[i].size() / 2; k <= input1[i].size(); k++){
                    if(input1[i][j] == input1[i][k]){
                        
                        // j++;
                        if (std::find(tmpArray.begin(), tmpArray.end(), input1[i][j]) == tmpArray.end()){
                            tmpArray.push_back(input1[i][j]);
                            // std::cout << "Same - " << input1[i][j] << std::endl;
                            
                            if(isupper(input1[i][j])){
                                // std::cout << "Upper case - " << ((int(input1[i][j])) - 38) << std::endl;
                                sumOfPriorities += ((int(input1[i][j])) - 38);
                            }
                            else {
                                // std::cout << "Lower case - " << ((int(input1[i][j])) - 96) << std::endl;
                                sumOfPriorities += ((int(input1[i][j])) - 96);
                            }
                            
                            // std::cout << "Sum: " << sumOfPriorities << std::endl;
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
        std::vector<char> tmpArray;
        int sum = 0;

        
        for(int i = 2; i < input2.size(); i+=3){
            tmpArray.clear();
            
            for(int j = 0; j < input2[i-2].size(); j++){
                for(int k = 0; k < input2[i-1].size(); k++){
                    if(input2[i-2][j] == input2[i-1][k]){
                        if(std::find(tmpArray.begin(), tmpArray.end(), input2[i-2][j]) == tmpArray.end()){
                            tmpArray.push_back(input2[i-2][j]);
                            // std::cout << "Same - " << input2[i-2][j] << std::endl;
                            break;
                        }
                    }
                }
            }
            
            for(int j = 0; j < tmpArray.size(); j++){
                std::cout << "j: " << tmpArray[j] << std::endl;
                for(int k = 0; k < input2[i].size(); k++){
                    if(tmpArray[j] == input2[i][k]){
                        // std::cout << "Same - " << tmpArray[j] << std::endl;
                        if(isupper(tmpArray[j])){
                            // std::cout << "Upper case - " << ((int(input1[i][j])) - 38) << std::endl;
                            sum += (int(tmpArray[j]) - 38);
                        }
                        else {
                            // std::cout << "Lower case - " << ((int(input1[i][j])) - 96) << std::endl;
                            sum += (int(tmpArray[j]) - 96);
                        }
                        break;
                    }
                }
            }
            // std::cout << input2[i-2] << std::endl << input2[i-1] << std::endl << input2[i] << std::endl;
        }
        
        
        return sum;
    }
};
