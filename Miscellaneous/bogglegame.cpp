
ggle game - given a board of letters (2d array) and a word (string), 
* return whether the word exists in the board. From each letter you can move 
* in all directions (including diagonals), but you cannot use the same letter twice.  
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>
using namespace std;

#define X 3
#define Y 3

bool checkString(char board[X][Y],char visited[X][Y],string word,string str,int xpos,int ypos){
  //cout<<"Inside checkString,xpos:"<<xpos<<", ypos:"<<ypos<<endl;
  for(int x=xpos-1;(x<X) && x<=xpos+1;x++){
    for(int y=ypos-1;(y<Y) && y<=ypos+1;y++){
      str+= board[xpos][ypos];
      //cout<<"str is "<<str<<endl;
      visited[xpos][ypos]=true;
      if(str == word){
        cout <<"The word "<<word<<" was found in the boggle board"<<endl;
        return true;
      }
      if(x>=0 && y>=0 && !visited[x][y]){
        bool found = checkString(board,visited,word,str,x,y);
        if(found) goto END_OF_LOOP;
      }
      visited[xpos][ypos]=false;
      str.erase(str.size()-1);
    }
  }
  return false;
  END_OF_LOOP:return true;
}

void boggle(char board[X][Y],string word){
  //cout<<"inside boggle"<<endl;
  char visited[X][Y] = {{false}};
  bool found = false;
  for(int x=0; x<X;x++){
    for(int y=0;y<Y;y++){
      string str = "";
      //cout<<"x:"<<x<<", y:"<<y<<endl;
      if(board[x][y]==word[0]){
        bool found = checkString(board,visited,word,str,x,y);
        //cout<<"found is "<<found<<endl;
        if(found) goto END_OF_LOOP;
      }
    }
  }
  cout<<"The word "<<word<<" was not found in the boggle board"<<endl;
  END_OF_LOOP: return;
}

int main()
{
  string str;
  char board[X][Y] = {{'G','I','Z'},
                      {'U','E','K'},
                      {'Q','S','E'}};


  cout<<"Enter the string to be searched in the boggle board"<<endl;
  getline(cin,str);
  boggle(board,str);  
  return 0;
}

