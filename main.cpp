#include<bits/stdc++.h>
using namespace std;
void next_move(int p1,int p2,vector<string> grid){


     ///check dirt
     if(grid[p1][p2]=='d') cout << "CLEAN\n";
     ///check right
     else if((p1+1<grid.size()) && (grid[p1+1][p2]) && (grid[p1+1][p2])=='d'){
            cout << "DOWN\n";

     }
     ///check left
     else if((p1>0) && (grid[p1-1][p2]) && (grid[p1-1][p2])=='d'){
            cout << "UP\n";

     }
     ///check up
     else if((p2+1<grid.size()) && (grid[p1][p2+1]) && (grid[p1][p2+1])=='d'){
            cout << "RIGHT\n";

     }
     ///check down
     else if((p2>0) &&(grid[p1][p2-1]) && (grid[p1][p2-1])=='d'){
            cout << "LEFT\n";
     }
     else if((p2>0 && p1+1<5) && (grid[p1+1][p2-1]) && (grid[p1+1][p2-1])=='d'){
            cout << "DOWN";
     }
     else if((p2>0) && (p1+1<5) && (p2+1<5) && (grid[p1+1][p2+1]) && (grid[p1+1][p2+1])=='d'){
            cout << "DOWN";
     }
     else if((p2>0) && p1>0 && (grid[p1-1][p2-1]) && (grid[p1-1][p2-1])=='d'){
            cout << "UP";
     }
     else if((p1>0) && p2+1<5 && (grid[p1-1][p2+1]) && (grid[p1-1][p2+1])=='d'){
            cout << "UP";
     }

     ///to make it more tight

     else{
        int g=0,h=0;
        bool k=false;
        int dis;
        ///getting lowest manhattan distance
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='d' && !k){
                    dis=abs(p1-i)+abs(p2-j);
                    g=i;
                    h=j;
                    k=true;
                }

                else if(grid[i][j]=='d' && k){
                    if(abs(p1-i)+abs(p2-j)<dis){
                        dis=abs(p1-i)+abs(p2-j);
                        g=i;
                        h=j;
                    }


                }
            }

        }
        ///cout << g << " " << h << '\n';
        if(p1<=g && p2<=h){
            if(p1<=g && p2==h){
                cout << "DOWN\n";
            }
            else{
                cout << "RIGHT\n";
            }

        }
        else if(p1<=g && p2>=h){
            if(p1<=g && p2==h){
                cout << "DOWN\n";
            }
            else{
                cout << "LEFT\n";
            }

        }

        else if(p1>=g && p2>=h){
            if(p1>=g && p2==h){
                cout << "UP\n";
            }
            else{
                cout << "LEFT\n";
            }

        }

        else if(p1>=g && p2<=h){
            if(p1>=g && p2==h){
                cout << "UP\n";
            }
            else{
                cout << "RIGHT\n";
            }

        }






     }


}
int main(void) {
    int pos[2];
    int dim[2];
    cin>>pos[0]>>pos[1];
    cin>>dim[0]>>dim[1];
    vector <string> board;

    for(int i=0;i<dim[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    /*for(int i=0;i<5;i++){
      for(int j=0;j<5;j++)
        cout << board[i][j] << ' ';
      cout << '\n';
    }*/
    next_move(pos[0], pos[1], board);

}


