//
//  Day6.cpp
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


class Day6{
private:
    std::string input1;
    std::string input2;
    
public:
    Day6(){
        
    }
    
    
    std::string loadInput(std::string inputFile){
        std::string inputString;
        
        std::ifstream file(inputFile);
        std::string str;
                
        if (file.is_open()) {
            while(std::getline(file, str)){
                inputString = str;
            }
        }

        return inputString;
    }
    
    int solveFirst(){
        
        std::string signal1 = "zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw";
        
        this->input1 = loadInput("Day6/input_first.txt");
        
        std::cout << "Input: " << input1 << std::endl;
        
        for(int i = 3; i < input1.size(); i++){
            /*
            std::cout << signal1[i] << " " << std::endl;
            if(signal1[i-3] != signal1[i-2] != signal1[i-1] != signal1[i]){
                std::cout << i << ": " << signal1[i-3] << " " << signal1[i-2] << " " << signal1[i-1] << " " << signal1[i] << std::endl;
            }
            */
            
            std::cout << i << ": " << input1[i-3] << " " << input1[i-2] << " " << input1[i-1] << " " << input1[i] << std::endl;
            
            bool not_found = false;
            int tmp_cnt = 0;
            
            for(int j = 0 ; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    if(j != k){
                        if(input1[i-j] == input1[i-k]){
                            tmp_cnt--;
                        }
                        else tmp_cnt++;
                    }
                }
                // if(j == 3 && not_found == false) return i;
            }
            
            std::cout << "tmp_count: " << tmp_cnt << std::endl;
            if(tmp_cnt == 12) return i+1;
            
        }
        
        
        
        return 0;
    }
    
    int solveSecond(){
        std::string signal1 = "zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw";
        
        this->input2 = loadInput("Day6/input_first.txt");
        
        // this->input2 = signal1;
        
        // std::cout << "Input: " << input2 << std::endl;
        
        for(int i = 13; i < input2.size(); i++){
            int tmp_cnt = 0;
            
            for(int j = 0 ; j < 14; j++){
                for(int k = 0; k < 14; k++){
                    if(j != k){
                        if(input2[i-j] == input2[i-k]){
                            tmp_cnt--;
                        }
                        else tmp_cnt++;
                    }
                }
            }
            
            std::cout << "tmp_count: " << tmp_cnt << std::endl;
            if(tmp_cnt == 182) return i+1;
            
        }
        
        
        
        return 0;
    }
};
