//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <queue>

using namespace std;
queue<int> pox, poy, moves;
char mat[120][120];
int step[120][120];
int w, h, ex, ey;

int bfs(int row, int col)
{
    int i, j;
    step[row][col]=1;
    pox.push(row), poy.push(col), moves.push(0);
    while(!pox.empty()){
        int x=pox.front(), y=poy.front();
        pox.pop(), poy.pop();
        
        //base case
        if(x==ex && y==ey){
            return moves.front()-1;
        }
        
        //bfs
        //left
        for(i=y-1;;i--){
            if(mat[x][i]!='.')
                break;
            if(step[x][i])
                continue;
            step[x][i]=moves.front()+1;
            pox.push(x), poy.push(i), moves.push(moves.front()+1);
        }
        //right
        for(i=y+1;;i++){
            if(mat[x][i]!='.')
                break;
            if(step[x][i])
                continue;
            step[x][i]=moves.front()+1;
            pox.push(x), poy.push(i), moves.push(moves.front()+1);
        }
        //up
        for(i=x-1;;i--){
            if(mat[i][y]!='.')
                break;
            if(step[i][y])
                continue;
            step[i][y]=moves.front()+1;
            pox.push(i), poy.push(y), moves.push(moves.front()+1);
        }
        //down
        for(i=x+1;;i++){
            if(mat[i][y]!='.')
                break;
            if(step[i][y])
                continue;
            step[i][y]=moves.front()+1;
            pox.push(i), poy.push(y), moves.push(moves.front()+1);
        }
        moves.pop();
    }
    return 0;
}

int main()
{
    int x, y;
    int i, j;
    bool fi=false;
    
    cin >> w >> h;
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='C' && !fi)
                mat[i][j]='.', x=i, y=j, fi=true;
            if(mat[i][j]=='C' && fi)
                mat[i][j]='.', ex=i, ey=j;
        }
    }
    
    cout << bfs(x, y) << endl;
    
    return 0;
}
