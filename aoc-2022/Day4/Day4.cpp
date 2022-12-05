//
//  Day4.cpp
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
#include <utility>

#include <unistd.h> // for getcwd()


class Day4{
private:
    std::vector<std::string> input1;
    std::vector<std::string> input2;
    
public:
    Day4(){
        
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
    
    std::vector<std::pair<int, int>> createPairs(std::vector<std::string> input){
        std::vector<std::pair<int, int>> pairArray;
        for(int i = 0; i < input.size(); i++){
            std::string textBeforeDelimiter = input[i].substr(0, input[i].find(","));
            std::string textAfterDelimiter = input[i].substr(input[i].find(",") + 1);
            
            // std::cout << textBeforeDelimiter.substr(0, textBeforeDelimiter.find("-")) << " " << textBeforeDelimiter.substr(textBeforeDelimiter.find("-") + 1) << std::endl;
            
            pairArray.push_back(std::make_pair(
                                               stoi(textBeforeDelimiter.substr(0, textBeforeDelimiter.find("-"))),
                                               stoi(textBeforeDelimiter.substr(textBeforeDelimiter.find("-") + 1))
                                               ));
            
            pairArray.push_back(std::make_pair(
                                               stoi(textAfterDelimiter.substr(0, textAfterDelimiter.find("-"))),
                                               stoi(textAfterDelimiter.substr(textAfterDelimiter.find("-") + 1))
                                               ));
        }
        return pairArray;
    }
    
    int solveFirst(){
        // this->input1 = loadInput("Day4/input_first.txt");
        this->input1 = loadInput("Day4/input_first.txt");
        int overlapCounter = 0;
        
        std::vector<std::pair<int, int>> pairArray;
        
        pairArray = createPairs(this->input1);
        
        for(int i = 1; i < pairArray.size(); i+=2){
            if(pairArray[i-1].second - pairArray[i-1].first > pairArray[i].second - pairArray[i].first){
                // std::cout << "first is bigger" << std::endl;
                
                if(pairArray[i-1].first <= pairArray[i].first && pairArray[i-1].second >= pairArray[i].second){
                    // std::cout << "overlap" << std::endl;
                    overlapCounter+=1;
                }
            }
            else if(pairArray[i-1].second - pairArray[i-1].first < pairArray[i].second - pairArray[i].first){
                // std::cout << "first is smaller" << std::endl;
                
                if(pairArray[i-1].first >= pairArray[i].first && pairArray[i-1].second <= pairArray[i].second){
                    // std::cout << "overlap" << std::endl;
                    overlapCounter+=1;
                }
                
            }
            else{
                // std::cout << "equal" << std::endl;
                
                if(pairArray[i-1].first == pairArray[i].first && pairArray[i-1].second == pairArray[i].second){
                    // td::cout << "overlap" << std::endl;
                    overlapCounter+=1;
                }
            }
            
        }
        
        return overlapCounter;
    }
    
    int solveSecond(){
        this->input2 = loadInput("Day4/input_first.txt");
        // this->input2 = loadInput("Day4/input_example.txt");
        int overlapCounter = 0;
        
        std::vector<std::pair<int, int>> pairArray;
        
        pairArray = createPairs(this->input2);
        
        for(int i = 1; i < pairArray.size(); i+=2){
            for(int j = pairArray[i-1].first; j <= pairArray[i-1].second; j++){
                int condition2 = j >= pairArray[i-1].first;
                int condition3 = j >= pairArray[i].first;
                
                int condition5 = j <= pairArray[i-1].second;
                int condition6 = j <= pairArray[i].second;
                
                if(condition2 && condition3 && condition5 && condition6){
                    overlapCounter+=1;
                    break;
                }
            }
        }
        
        return overlapCounter;
    }
};
