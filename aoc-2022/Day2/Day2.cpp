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

#include <unistd.h> // for getcwd()


class Day2{
private:
    std::vector<std::string> input1;
    std::vector<std::string> input2;
    
public:
    Day2(){
        
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

    
    int first_checkResult(char shapeElf, char shapePlayer){
        if(shapeElf == 'A' && shapePlayer == 'X') return 0;
        else if(shapeElf == 'A' && shapePlayer == 'Y') return 1;
        else if(shapeElf == 'A' && shapePlayer == 'Z') return -1;
        
        if(shapeElf == 'B' && shapePlayer == 'X') return -1;
        else if(shapeElf == 'B' && shapePlayer == 'Y') return 0;
        else if(shapeElf == 'B' && shapePlayer == 'Z') return 1;
        
        if(shapeElf == 'C' && shapePlayer == 'X') return 1;
        else if(shapeElf == 'C' && shapePlayer == 'Y') return -1;
        else if(shapeElf == 'C' && shapePlayer == 'Z') return 0;
        
        else return NULL;
    }
    
    
    int first_getShapeScore(char shapePlayer){
        if(shapePlayer == 'X') return 1;
        else if(shapePlayer == 'Y') return 2;
        else if(shapePlayer == 'Z') return 3;
        
        else return NULL;
    }
    
    
    int second_chooseShape(char opponentShape, char result){
        if(opponentShape == 'A' && result == 'X') return 0 + 3;
        else if(opponentShape == 'A' && result == 'Y') return 3 + 1;
        else if(opponentShape == 'A' && result == 'Z') return 6 + 2;
        
        if(opponentShape == 'B' && result == 'X') return 0 + 1;
        else if(opponentShape == 'B' && result == 'Y') return 3 + 2;
        else if(opponentShape == 'B' && result == 'Z') return 6 + 3;
        
        if(opponentShape == 'C' && result == 'X') return 0 + 2;
        else if(opponentShape == 'C' && result == 'Y') return 3 + 3;
        else if(opponentShape == 'C' && result == 'Z') return 6 + 1;
        
        else return NULL;
    }
    
    
    int solveFirst(){
        this->input1 = loadInput("Day2/input_first.txt");
        int total_score = 0;
        
        for(int i = 0; i < input1.size(); i++){
            int score = this->first_checkResult(input1[i][0], input1[i][2]);
            if(score == -1) total_score += (0 + this->first_getShapeScore(input1[i][2]));
            else if(score == 0) total_score += (3 + this->first_getShapeScore(input1[i][2]));
            else if(score == 1) total_score += (6 + this->first_getShapeScore(input1[i][2]));
        }
        
        return total_score;
    }
    
    int solveSecond(){
        this->input2 = loadInput("Day2/input_first.txt");
        int total_score = 0;
        
        for(int i = 0; i < input2.size(); i++){
            int score = this->second_chooseShape(input2[i][0], input2[i][2]);
            total_score += score;
        }
        
        return total_score;
    }
};
