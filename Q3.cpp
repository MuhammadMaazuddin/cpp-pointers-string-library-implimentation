#include<iostream>
using namespace std;
bool InstructionDisplay(bool flage);

////////////displaying board

void display(char** array, int height, int width)
{
    for(int j=1;j<=width;j++)
    {
        { if(j>=1&&j<=9){if(j == 1){ cout<<"     "<<j<<"   ";}else if(j>=2&&j<=8){cout<<j<<"   ";}else if(j==9){cout<<j<<"  ";}}  else{cout<<" "<<j<<" ";} }
    }cout<<endl;
 for(int i=1;i<=height;i++)
    {
        if(i>=1&&i<10){ cout<<i<<"  "; }  else if(i!=1){ cout<<i<<" "; } 
        for(int j=1;j<=width;j++)
        {
            if(j == 1){ cout<<"| "<< array[i][j]<<" | "; }else{cout<< array[i][j]<<" | ";}
        }cout<<endl;}cout<<endl;
    }
int main()
{
    bool flag = false;


    /////function to inform user about instruction of game
    flag = InstructionDisplay(flag); 

//////////////////taking option from user weather to start game or not

if(flag == true)
{ //==================================================================================================  
    int height = 0;
    int width = 0;
    cout<<"lenght  ===  ";
    cin>>height;
    cout<<"width   ===  ";
    cin>>width;

    int num = height;
    int point1 = 1;
    int point2 = 1;

    int PlayerIndexHeight = 0;
    int PlayerIndexWidth = 0;
    int wh = ( height * width ) / 2;

    /////dynamically allocation of 2D char  pointer
    char **array = new char*[height];
    for(int i=1;i<=height;i++)
    {
        array[i] = new char[width];
    }


    ///filling board with spaces
    for(int i=1;i<=height;i++)
    {
        for(int j=1;j<=width;j++){ *(*(array+i)+j) = ' '; }
    }
    ///displaying board
    display(array, height, width);

//Taking input from user
    for(int k=0;k<(height*width)/2;k++)
    {
        cout<<"PLAYER 1 :: IndexWidth ===  :: ";
        cin>>PlayerIndexWidth;
        
        
///////////////DROPING OF COIN BY PLAYER 1::://////////////////////

        for(int i=height;i>=1;i--)
        {
            if( array[i][PlayerIndexWidth] == ' ')
                {
                    array[i][PlayerIndexWidth] = 'o';
                    break;
                }
            
        } 
        display(array, height, width);

/////////////////SCORE BOARD OF PLAYER 1:::///////////////////
    // ==>[ - ]
        for (int i = 1; i <= width; i++) {
        for (int j = 1; j <= height ; j++) {
            if (array[i][j] == 'o' && array[i][j+1] == 'o' && array[i][j+2] == 'o' && array[i][j+3] == 'o') {
            point1++;
            
            }
        }
    }

    // ==>[ | ]
    for (int i = 1; i <= width ; i++) {
        for (int j = 1; j <= height; j++) {
            if (array[i][j] == 'o' && array[i+1][j] == 'o' && array[i+2][j] == 'o' && array[i+3][j] == 'o') {
               point1++;
               
            }
        }
    }

    // ==>[ \ ]
    for (int i = 1; i <= width; i++) {
        for (int j = 1; j <= height; j++) {
            if (array[i][j] == 'o' && array[i+1][j+1] == 'o' && array[i+2][j+2] == 'o' && array[i+3][j+3] == 'o') {
            point1++;
            
            }
        }
    }

    // ==>[ / ]
    for (int i = 1; i <= width ; i++)
    {
        for (int j = 4; j <= height; j++) {
            if (array[i][j] == 'o' && array[i+1][j-1] == 'o' && array[i+2][j-2] == 'o' && array[i+3][j-3] == 'o') {
            point1++;
            
            }
        }
    }
    
        
        
        

///////////////DROPING OF COIN BY PLAYER 2::://////////////////////
        cout<<"PLAYER 2 :: IndexWidth  ===  :: ";
        cin>>PlayerIndexWidth;

        for(int i=height;i>=1;i--)
        {
            if( array[i][PlayerIndexWidth] == ' ')
                {
                    array[i][PlayerIndexWidth] = 'x';
                    break;
                }
            
        } 
        display(array, height, width);

/////////////////////SCORE BORAD OF PLAYER 2:::///////////////////////
    // ==>[ - ]
        for (int i = 1; i <= width; i++) {
        for (int j = 1; j <= height ; j++) {
            if (array[i][j] == 'o' && array[i][j+1] == 'o' && array[i][j+2] == 'o' && array[i][j+3] == 'o') {
                point2++;
            
            }
        }
    }

    // ==>[ | ]
    for (int i = 1; i <= width ; i++) {
        for (int j = 1; j <= height; j++) {
            if (array[i][j] == 'o' && array[i+1][j] == 'o' && array[i+2][j] == 'o' && array[i+3][j] == 'o') {
               point2++;
            
            }
        }
    }

    // ==>[ / ]
    for (int i = 1; i <= width ; i++) {
        for (int j = 1; j <= height; j++) {
            if (array[i][j] == 'o' && array[i+1][j+1] == 'o' && array[i+2][j+2] == 'o' && array[i+3][j+3] == 'o') {
            point2++;
            
            }
        }
    }

    // ==>[ \ ]
    for (int i = 1; i <= width ; i++)
    {
        for (int j = 4; j <= height; j++) {
            if (array[i][j] == 'o' && array[i+1][j-1] == 'o' && array[i+2][j-2] == 'o' && array[i+3][j-3] == 'o') {
            point2++;
            
            }
        }
    }
    
        
        
        


cout<<point1<<" "<<point2<<endl;

}

cout<<"_________________________________________\n";
cout<<"[**************GAME OVER****************]\n";
cout<<"-----------------------------------------\n";
if ( point1>point2 )
{
cout<<"[*************PLAYER 1 WON***************]\n";
cout<<" Player 1 :: [ "<<point1<<" ] :: points"<<endl;
cout<<" Player 2 :: [ "<<point2<<" ] :: points"<<endl;
}
else if ( point1<point2 )
{
cout<<"[*************PLAYER 2 WON***************]\n";
cout<<" Player 1 :: [ "<<point1<<" ] :: points"<<endl;
cout<<" Player 2 :: [ "<<point2<<" ] :: points"<<endl;
}
else
{
cout<<"[*************NO PLAYER WON**************]\n";
}
}


return 0;
}
bool InstructionDisplay(bool flage )
{
    char alpha;
    cout<<"__________________________________________\n";
    cout<<"[READ THE FOLLOWING INSTRUCTION CAREFULLY]\n";
    cout<<"------------------------------------------\n";
    cout<<"**********This is 2 players game**********\n";
    cout<<"*****Enter the height and width***********\n";
    cout<<"::::::First turn will be player 1 ::::::::\n";
    cout<<"**Enter the index of the box you selected*\n";
    cout<<"[***************THANK_YOU****************]\n";
    cout<<"------------------------------------------\n";
    cout<<"Press c to continue ::  ";
    cin>>alpha;
    if(alpha == 'c')
    { flage = true; }
    return flage;
}
