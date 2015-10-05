#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <utility>
#include <string>

using namespace std;

vector<pair<int,int>> get_adjacent_nodes(pair<int,int> Pos, vector<string> matrix ,vector<std::pair<int,int>> Explored){
       pair<int,int> aux;
       vector<pair<int,int>> New_Reachable;
       vector<string> vString = matrix;

       if(vString[Pos.first+1][Pos.second] != 'X'){
           aux.first = Pos.first+1;
           aux.second = Pos.second;
          if(find(Explored.begin(), Explored.end(), aux)!=Explored.end()) { //To prevent adding already Known positions
          }else{
             New_Reachable.push_back(aux);
          }
       }
       if(vString[Pos.first-1][Pos.second] != 'X'){
           aux.first = Pos.first-1;
           aux.second = Pos.second;
           if(find(Explored.begin(), Explored.end(), aux)!=Explored.end()) {
           }else{
              New_Reachable.push_back(aux);
           }
       }
       if(vString[Pos.first][Pos.second+1] != 'X'){
           aux.first = Pos.first;
           aux.second = Pos.second+1;
           if(find(Explored.begin(), Explored.end(), aux)!=Explored.end()) {
           }else{
              New_Reachable.push_back(aux);
           }
       }
       if(vString[Pos.first][Pos.second-1] != 'X'){
           aux.first = Pos.first;
           aux.second = Pos.second-1;
           if(find(Explored.begin(), Explored.end(), aux)!=Explored.end()) {
           }else{
              New_Reachable.push_back(aux);
           }
       }
       return New_Reachable;
}

int main()
{



    /*sf::RectangleShape shape(sf::Vector2f(40, 40));
    shape.setPosition(10, 20);*/

    string STRING;
    string STRINGAUX;
    vector<std::string> vString;
    pair<int, int> D1Pos,GPos;
    vector<std::pair<int,int>> Explored,Reachable;
    ifstream infile;
    infile.open ("Test2.txt");
    int i = 0;

    getline(infile,STRING);
        while(!infile.eof()) // To get you all the lines.
        {
                getline(infile,STRING); // Saves the line in STRING.
                STRINGAUX = STRINGAUX+STRING+"\n";
                vString.push_back(STRING);
               //std::cout<<vString[i]; // Prints our STRING.

            i++;
        }
    cout<<STRINGAUX; // Prints our STRING.
    infile.close();
    for (int x = 0; x<vString[1].size();x++){
        for(int y = 0; y<i; y++){
            if(vString[y][x] == 'X'){

            }
            if(vString[y][x] == 'J'){
                D1Pos.first = y;
                D1Pos.second = x;
                Explored.push_back(D1Pos);
            }
            if(vString[y][x] == 'G'){
                GPos.first = y;
                GPos.second = x;
            }
        }
    }

    while(D1Pos != GPos){

        Reachable = get_adjacent_nodes(D1Pos,vString,Explored);
        D1Pos = Reachable.back();
        Reachable.pop_back();
        Explored.push_back(D1Pos);

    }


        for(int i = 0; i < Explored.size(); i++){
             cout << Explored[i].first << "  " << Explored[i].second << std::endl;
        }


    return 0;
}


