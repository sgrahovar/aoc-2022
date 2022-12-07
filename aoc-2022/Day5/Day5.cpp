//
//  Day5.cpp
//  aoc-2022
//
//  Created by Sanjin Grahovar Sadiković on 06.12.2022..
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

/*
 
    [D]
[N] [C]
[Z] [M] [P]
 1   2   3

move 1 from 2 to 1
move 3 from 1 to 3
move 2 from 2 to 1
move 1 from 1 to 2
 
 */

class Day5{
private:
    std::vector<std::string> input1;
    std::vector<std::string> input2;
    
public:
    Day5(){
        
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
        this->input1 = loadInput("Day5/input_first.txt");
        // this->input1 = loadInput("Day5/input_example.txt");
        
        std::vector<std::vector<char>> charArray(10);
        std::vector<std::string> instructionArray;
        
        for(int i = 0; i < input1.size(); i++){
            // std::cout << "len: " << input1[i].size() << std::endl;
            int tmpCount = 0;
            
            if(!isdigit(input1[i][1]) && !isalpha(input1[i][0]) && input1[i].size() != 0){
                for(int j = 1; j <= input1[i].size(); j+=4){
                    if(isalpha(input1[i][j])){
                        // std::cout << "Input: " << input1[i][j] << std::endl;
                        charArray[tmpCount].push_back(input1[i][j]);
                    }
                    tmpCount++;
                }
            }
            
            else if(input1[i].size() == 0){
                for(int k = 0; k < charArray.size(); k++){
                    std::reverse( charArray[k].begin(), charArray[k].end() );
                }
            }
            
            else if(isdigit(input1[i][1])){
                
            }
            
            else{
                instructionArray.push_back(input1[i]);
            }
        }
        
        for(int i = 0; i < instructionArray.size(); i++){
            int from = 0, to = 0, quantity = 0;
            
            quantity = stoi(instructionArray[i].substr(4, instructionArray[i].find(' ')));
            to = stoi(instructionArray[i].substr(instructionArray[i].length() - 1));
            from = stoi(instructionArray[i].substr(instructionArray[i].length() - 6));
            
            for(int j = 0; j < quantity; j++){
                
                char tmpChar = charArray[from-1].back();
                charArray[from-1].pop_back();
                charArray[to-1].push_back(tmpChar);
            }
        }
        
        for(int i = 0; i < charArray.size(); i++){
            if(charArray[i].size() > 0){
                // std::cout << "s: " << size << std::endl;
                std::cout << charArray[i][(charArray[i].size() - 1)];
            }

        }
        
        std::cout << std::endl;
        return 0;
    }
    
    int solveSecond(){
        this->input2 = loadInput("Day5/input_first.txt");
        
        // this->input1 = loadInput("Day5/input_example.txt");
        
        std::vector<std::vector<char>> charArray(10);
        std::vector<std::string> instructionArray;
        
        for(int i = 0; i < input2.size(); i++){
            // std::cout << "len: " << input1[i].size() << std::endl;
            int tmpCount = 0;
            
            if(!isdigit(input2[i][1]) && !isalpha(input2[i][0]) && input2[i].size() != 0){
                for(int j = 1; j <= input2[i].size(); j+=4){
                    if(isalpha(input2[i][j])){
                        // std::cout << "Input: " << input1[i][j] << std::endl;
                        charArray[tmpCount].push_back(input2[i][j]);
                    }
                    tmpCount++;
                }
            }
            
            else if(input2[i].size() == 0){
                for(int k = 0; k < charArray.size(); k++){
                    std::reverse( charArray[k].begin(), charArray[k].end() );
                }
            }
            
            else if(isdigit(input2[i][1])){
                
            }
            
            else{
                instructionArray.push_back(input2[i]);
            }
        }
        
        for(int i = 0; i < instructionArray.size(); i++){
            int from = 0, to = 0, quantity = 0;
            
            quantity = stoi(instructionArray[i].substr(4, instructionArray[i].find(' ')));
            to = stoi(instructionArray[i].substr(instructionArray[i].length() - 1));
            from = stoi(instructionArray[i].substr(instructionArray[i].length() - 6));
            
            std::vector<char> tmpArray;
            
            for(int j = 0; j < quantity; j++){
                
                tmpArray.push_back(charArray[from-1].back());
                charArray[from-1].pop_back();
            }
            
            std::reverse( tmpArray.begin(), tmpArray.end() );
            
            for(int j = 0; j < tmpArray.size(); j++){
                charArray[to-1].push_back(tmpArray[j]);
            }
            
            
        }
        
        for(int i = 0; i < charArray.size(); i++){
            if(charArray[i].size() > 0){
                // std::cout << "s: " << size << std::endl;
                std::cout << charArray[i][(charArray[i].size() - 1)];
            }

        }
        
        std::cout << std::endl;
        return 0;

    }
};
