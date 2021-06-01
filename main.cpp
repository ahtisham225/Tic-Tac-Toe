#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class TicTacToe
{

private:

    char** Board;
    int capacity;
    string p1;
    string p2;
    char p1x;
    char p2x;

public:
    char check;
    TicTacToe();
    TicTacToe(char a, char b, string c, string d);
    TicTacToe(TicTacToe &T1);
    void setName(string x, string y);
    void printBoard();
    void takeInput(int &in, int t);
    void playerMove(int f);
    void tooglePlayer(int &x);
    void checkWinner(int &y);
    void resetBoard();
    ~TicTacToe();

};

TicTacToe::TicTacToe()
{
    capacity=3;
    p1="";
    p2="";
    p1x='X';
    p2x='O';
    Board=new char*[capacity];
    for(int i=0; i<capacity; i++)
    {
        Board[i]=new char[capacity];
    }
    for (int i=0; i<capacity;i++)
    {
        for(int j=0; j<capacity; j++)
        {
            Board[i][j]=' ';
        }
    }
}

TicTacToe::TicTacToe(char a, char b, string c, string d)
{
    capacity=3;
    p1x=a;
    p2x=b;
    p1=c;
    p2=d;
    Board=new char*[capacity];
    for(int i=0; i<capacity; i++)
    {
        Board[i]=new char[capacity];
    }
    for (int i=0; i<capacity;i++)
    {
        for(int j=0; j<capacity; j++)
        {
            Board[i][j]=' ';
        }
    }

}

TicTacToe::TicTacToe(TicTacToe &T1)
{
    capacity=T1.capacity;
    p1x=T1.p1x;
    p2x=T1.p2x;
    p1=T1.p1;
    p2=T1.p2;
    Board=new char*[capacity];
    for(int i=0; i<capacity; i++)
    {
        Board[i]=new char[capacity];
    }
    for (int i=0; i<capacity;i++)
    {
        for(int j=0; j<capacity; j++)
        {
            Board[i][j]=' ';
        }
    }
}

void TicTacToe::setName(string x, string y)
{
    p1=x;
    p2=y;
}

void TicTacToe::printBoard()
{
    for (int i=0; i<capacity;i++)
    {
        cout<<"-------------------"<<endl;
        for(int j=0; j<capacity; j++)
            cout<<"|    "<<Board[i][j];
            cout<<"|"<<endl;
    }
    cout<<"-------------------"<<endl;
}

void TicTacToe::tooglePlayer(int &x)
{
    if(x==0)
    {
        check=p1x;
        x=1;
    }
    else
    {
        check=p2x;
        x=0;
    }
}

void TicTacToe::playerMove(int ff)
{
    if(ff>0&&ff<=3)
    {
        Board[0][ff-1]=check;
    }
    else if(ff>3&&ff<=6)
    {
        Board[1][ff-4]=check;
    }
    else if(ff>6&&ff<=9)
    {
        Board[2][ff-7]=check;
    }
    else
    {
        srand(time(0));
        int rand1, rand2;
        do
        {
             rand1=rand()%3;
             rand2=rand()%3;

        }while(Board[rand1][rand2]!=' ');
        Board[rand1][rand2]=check;
    }
}
void TicTacToe::takeInput(int &in,int turn)
{
    if(turn==0)
    {
        cout<<"Player 1 turn"<<endl;
    }
    else
    {
        cout<<"Player 2 turn"<<endl;
    }
    cin>>in;
}

void TicTacToe::resetBoard()
{
    for (int i=0; i<capacity;i++)
    {
        for(int j=0; j<capacity; j++)
        {
            Board[i][j]=' ';
        }
    }
}

void TicTacToe::checkWinner(int &h)
{
    int r=0;
    int c=0;
    int d=0;
    int s=0;
    for(int i=0; i<capacity; i++)
    {
        for(int j=0; j<capacity; j++)

      {

            if(Board[i][j]==p1x)
            {
                r++;
            }
            if(Board[j][i]==p1x)
            {
                c++;
            }
            if(Board[j][j]==p1x)
            {
                d++;
            }
            if(Board[j][2-j]==p1x)
            {
                s++;
            }

      }
      if(r==3||c==3||d==3||s==3)
            {
                cout<<p1<<" is the Winner. Congratulations!"<<endl;
                h++;
                break;
            }
        else
        {
                r=0;
                c=0;
                d=0;
                s=0;
        }

    }
    if(r==0&&c==0&&d==0&&s==0)
    {
        for(int i=0; i<capacity; i++)
    {
        for(int j=0; j<capacity; j++)

      {

            if(Board[i][j]==p2x)
            {
                r++;
            }
            if(Board[j][i]==p2x)
            {
                c++;
            }
            if(Board[j][j]==p2x)
            {
                d++;
            }
            if(Board[j][2-j]==p2x)
            {
                s++;
            }

      }
      if(r==3||c==3||d==3||s==3)
            {

                cout<<p2<<" is the Winner. Congratulations!"<<endl;
                h++;
                break;
            }
        else
        {
                r=0;
                c=0;
                d=0;
                s=0;
        }

    }
    }
    if(r==0||c==0||d==0||s==0)
    {
    int draw=0;
    for(int i=0; i<capacity; i++)
    {
        for(int j=0; j<capacity; j++)
        {
            if(Board[i][j]!=' ')
            {
                draw++;
            }
        }
    }
    if(draw==9)
    {
        cout<<"Match Draw "<<endl;
        h++;
    }
    }
}

TicTacToe::~TicTacToe()
{
    cout<<"Destructor Called! Game Over "<<endl;
    for(int j=0; j<capacity; j++)
    {
        delete [] Board[j];
    }
    delete [] Board;
}

int main()
{
    int turn =0;
    int WoN=0;
    int input=0;
    string x;
    string y;
    char a;
    char b;
    cout<<"Input the Name of Player 1"<<endl;
    cin>>x;
    cout<<"Input the TOKEN of Player 1"<<endl;
    cin>>a;
    cout<<"Input the Name of Player 2"<<endl;
    cin>>y;
    cout<<"Input the TOKEN of Player 2"<<endl;
    cin>>b;

    TicTacToe obj1(a,b,x,y);

    while(WoN!=1)
    {
    obj1.printBoard();
    obj1.takeInput(input, turn);
    obj1.tooglePlayer(turn);
    obj1.playerMove(input);
    obj1.checkWinner(WoN);
    if(WoN==1)
    {
        int b;
        cout<<"Do You Want to Play again? Press 1 to again other key to end "<<endl;
        cin>>b;
        if(b==1)
        {
            obj1.resetBoard();
            WoN=0;
        }
    }
    system("CLS");
    }
    return 0;
}
