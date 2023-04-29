#include<cstdlib>
#include<iostream>
#include <cmath>
#include <conio.h>
#include <cstring>
#include <string>
using namespace std;
class hangm
{
    string p,q,s,t;
    int a,b;
public :
    hangm()
    {
        p="";
        q="";
        s="";
        t="";
        a=0,b=0;
    }
    void score();
    void rules();
    void play();
    void game();
    void details();
    void host1();
    void h();
    void h1();
    void h2();
    void h3();
    void h4();
    void h5();
    void h6();
    void h7();
    void h8();
};
void hangm::score()
{
    cout<<"Scores are as follow "<<endl;
    cout<<p<<" 's score - "<<a<<endl;
    cout<<q<<" 's score - "<<b<<endl;
    cout<<endl<<endl<<"Please press any character to continue"<<endl;
    getch();
    system("cls");
}
void hangm::rules()
{
    cout<<"WELCOME TO HANGMAN   "<<endl<<endl<<endl;
    cout<<"A toss is done to choose the host"<<endl;
    cout<<"The host player chooses a secret word which is typed in (REMEMBER IT TO BE A SINGLE WORD ONLY)"<<endl;
    cout<<"Also a hint is enter by the host regarding the word"<<endl;
    cout<<"Now it is the turn of the other player to guess the word"<<endl;
    cout<<"Blank spaces with the same length of the word would be displayed to the player guessingh"<<endl;
    cout<<"He would enter one letter at a time"<<endl;
    cout<<"If the letter is in the word then it is added to the blank spaces"<<endl;
    cout<<"If guessed incorrectly then a part of the hangman is added"<<endl;
    cout<<"There are 8 parts before the hangman dies so the player guessing could make 7 wrong guesses"<<endl;
    cout<<"After the 8th wrong guesses the host wins and gets a point"<<endl;
    cout<<"If the player guessing completes the word before 8 wrong guesses then he gets a point"<<endl;
    cout<<"After the sub-round the player switches position"<<endl;
    cout<<"Host becomes the player guessing and the player guessing becomes the new host"<<endl;
    cout<<"Same rule is followed as the above sub-round"<<endl;
    cout<<"After this sub-round, round ends and player could leave, see the score or keep playing"<<endl;
    cout<<endl<<endl<<"Please press any character to continue"<<endl;
    getch();
    system("cls");
}
void hangm::details()
{
    cout<<"Input your name player 1"<<endl;
    fflush(stdin);
    getline(cin,p);
    cout<<"Input your name player 2"<<endl;
    fflush(stdin);
    getline(cin,q);
    if(p==q)
    {
        p+=" 1";
        q+=" 2";
        cout<<"As player 1 and player 2 names are same so we are assigning a number with your name"<<endl;
        cout<<"Player 1 - "<<p<<endl;
        cout<<"Player 2 - "<<q<<endl;
    }
    system("cls");
}
void hangm::host1()
{
    int m=0;
    char x='\0',n='\0';
    string h="",g="";
    cout<<"1 - Heads\n2 - Tails"<<endl<<p<<" Please input your choice -"<<endl;
    x=getch();
    while(x!='1'&&x!='2')
    {
        system("cls");
        cout<<"Please input from the choice available only "<<endl<<endl;
        cout<<"1 - Heads\n2 - Tails"<<endl<<p<<" Please input your choice -"<<endl;
        x=getch();
    }
    m=(int)round(rand());
    m+=48;
    if(char(m)==x)
    {
        h=p;
        g=q;
    }
    else
    {
        h=q;
        g=p;
    }
    system("cls");
    cout<<h<<" you won the toss "<<endl<<endl;
    cout<<h<<" please input "<<endl<<"1 - If you want to guess first"<<endl<<"Else any other number for choosing the secret word"<<endl;
    n=getch();
    if(n=='1')
    {
        s=h;
        t=g;
    }
    else
    {
        s=g;
        t=h;
    }
    system("cls");
}
void hangm::game()
{
    string u="",w="",v="",hi="";
    char ch='\0',chr='\0',re='\0';
    int i=0,i1=0,l=0,k=0;
    cout<<t<<" Please enter your secret word - "<<endl;
    fflush(stdin);
    getline(cin,w);
    fflush(stdin);
    i=s.find(' ');
    system("cls");
    while(i!=-1||w[0]=='\n')
    {
        if(i!=-1)
        cout<<"Please enter only a single word only !!!"<<endl<<endl<<endl;
        cout<<t<<" Please enter your secret word - "<<endl;
        fflush(stdin);
        getline(cin,w);
        fflush(stdin);
        i=w.find(' ');
        system("cls");
    }
    u=w;
    l=w.length();
    do
    {
        system("cls");
        if(hi[0]=='\n')
            cout<<t<<" Please re-enter a hint - "<<endl;
        else
            cout<<t<<" Please enter a hint - "<<endl;
    fflush(stdin);
    getline(cin,hi);
    fflush(stdin);
    }
    while(hi[0]=='\n');
    for(int i=0;i<l;i++)
    {
        v+="_";
    }
    for(int j=0;j<8;)
    {
        system("cls");
        cout<<"Your word -->   "<<v<<endl<<endl;
        cout<<"Hint - "<<hi<<endl<<endl<<endl;
        ++k;
        do
        {
        cout<<s<<" please input your "<<k<<" th guess -"<<endl;
        cin>>ch;
        }
        while((ch<65&&ch>90)||(ch<97&&ch>122));
        ch=toupper(ch);
        chr=tolower(ch);
        i=u.find(ch);
        i1=u.find(chr);
        if(i==-1&&i1==-1)
        {
            j++;
            cout<<"Wrong guess !!!"<<endl<<endl<<endl;
        }
        else
        {
            if(i==-1)
            {
                ch=chr;
                i=i1;
            }
            cout<<endl<<endl<<"Your are correct !!!"<<endl<<endl<<endl;
            do
            {
                cout<<i<<endl;
                v[i]=u[i];
                u[i]='_';
                i=u.find(ch);

            }while(i!=-1);
            if(v==w)
            {
                system("cls");
                cout<<"You won this sub-round"<<endl;
                cout<<"The Word was -->"<<endl<<w<<endl;
                if(s==p)
                    a++;
                else
                    b++;
                    cout<<endl<<endl<<"Please press any character to continue"<<endl;
                    getch();
                    system("cls");
                return;
            }
        }
            if(j==0)
                h();
            else if(j==1)
                h1();
            else if(j==2)
                h2();
            else if(j==3)
                h3();
            else if(j==4)
                h4();
            else if(j==5)
                h5();
            else if(j==6)
                h6();
            else if(j==7)
                h7();
            else if(j==8)
            {
                h8();
                cout<<endl<<endl<<endl<<"Sorry "<<s<<" you lost this sub-round "<<endl<<"The Word was -->   "<<w<<endl;
                if(t==p)
                    a++;
                else
                    b++;
                    cout<<endl<<endl<<"Please press any character to continue"<<endl;
                    getch();
                    system("cls");
                return;
            }
            cout<<endl<<endl<<"Please press any character to continue"<<endl;
            getch();
    }
}
void hangm::play()
{
    char z='\0';
    string r="";
    do
    {

        game();
        r=s;
        s=t;
        t=r;
        cout<<"Now it's your turn "<<t<<endl;
        game();
        r=s;
        s=t;
        t=r;
        cout<<"Wanna play again ???"<<endl<<"Enter 1 if yes"<<endl<<"Enter 2 to see the scores"<<endl<<"Else enter any other character to exit"<<endl;
        z=getch();
        system("cls");
        if(z=='2')
        score();
        cout<<"Wanna play again ???"<<endl<<"Enter 1 if yes"<<endl<<"Else enter any other character to exit"<<endl;
        z=getch();
        system("cls");
    }
    while(z=='1');
    z=0;
    cout<<"The final score "<<endl;
    score();
    if(a>b)
        cout<<endl<<endl<<p<<" won "<<endl<<"Congrats !!!"<<endl;
    else if(a>b)
        cout<<endl<<endl<<q<<" won "<<endl<<"Congrats !!!"<<endl;
    else
    {
        cout<<endl<<endl<<p<<" and "<<q<<endl<<"Your score is tied !!!"<<endl;
        cout<<"Wanna play a tie breaker ???"<<endl<<"Enter 1 if yes"<<endl<<"Else enter any other character to exit"<<endl;
        z=getch();
        if(z=='1')
        cout<<"It's your turn "<<t<<endl;
        game();
        cout<<"The final score "<<endl;
        score();
        if(a>b)
            cout<<endl<<endl<<p<<" won "<<endl<<"Congrats !!!"<<endl;
        else if(a>b)
            cout<<endl<<endl<<q<<" won "<<endl<<"Congrats !!!"<<endl;
    }
}

void hangm::h()
{
    cout<<"                  "<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 | "<<endl;
    cout<<"                 |"<<endl;
    cout<<"               __|__"<<endl;
}
void hangm::h1()
{
    cout<<"       ___________"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 | "<<endl;
    cout<<"                 |"<<endl;
    cout<<"               __|__"<<endl;
}
void hangm::h2()
{
    cout<<"       ___________"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"   _________     |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |   - -   |    |"<<endl;
    cout<<"  |    ^    |    |"<<endl;
    cout<<"  |  -----  |    |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |_________|    |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 | "<<endl;
    cout<<"                 |"<<endl;
    cout<<"               __|__"<<endl;
}
void hangm::h3()
{
    cout<<"       ___________"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"   _________     |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |   - -   |    |"<<endl;
    cout<<"  |    ^    |    |"<<endl;
    cout<<"  |  -----  |    |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |_________|    |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       ^         |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 | "<<endl;
    cout<<"                 |"<<endl;
    cout<<"               __|__"<<endl;
}
void hangm::h4()
{
    cout<<"       ___________"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"   _________     |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |   - -   |    |"<<endl;
    cout<<"  |    ^    |    |"<<endl;
    cout<<"  |  -----  |    |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |_________|    |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       |\\        |"<<endl;
    cout<<"       | \\       |"<<endl;
    cout<<"       |  \\      |"<<endl;
    cout<<"       |   \\     |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       ^         |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 | "<<endl;
    cout<<"                 |"<<endl;
    cout<<"               __|__"<<endl;
}
void hangm::h5()
{
    cout<<"       ___________"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"   _________     |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |   - -   |    |"<<endl;
    cout<<"  |    ^    |    |"<<endl;
    cout<<"  |  -----  |    |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |_________|    |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"      /|\\        |"<<endl;
    cout<<"     / | \\       |"<<endl;
    cout<<"    /  |  \\      |"<<endl;
    cout<<"   /   |   \\     |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       ^         |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 | "<<endl;
    cout<<"                 |"<<endl;
    cout<<"               __|__"<<endl;
}
void hangm::h6()
{
    cout<<"       ___________"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"   _________     |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |   - -   |    |"<<endl;
    cout<<"  |    ^    |    |"<<endl;
    cout<<"  |  -----  |    |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |_________|    |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"      /|\\        |"<<endl;
    cout<<"     / | \\       |"<<endl;
    cout<<"    /  |  \\      |"<<endl;
    cout<<"   /   |   \\     |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       ^         |"<<endl;
    cout<<"        \\        |"<<endl;
    cout<<"         \\       |"<<endl;
    cout<<"          \\      | "<<endl;
    cout<<"           \\     |"<<endl;
    cout<<"               __|__"<<endl;
}
void hangm::h7()
{
    cout<<"       ___________"<<endl;
    cout<<"                 |"<<endl;
    cout<<"                 |"<<endl;
    cout<<"   _________     |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |   - -   |    |"<<endl;
    cout<<"  |    ^    |    |"<<endl;
    cout<<"  |  -----  |    |"<<endl;
    cout<<"  |         |    |"<<endl;
    cout<<"  |_________|    |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"      /|\\        |"<<endl;
    cout<<"     / | \\       |"<<endl;
    cout<<"    /  |  \\      |"<<endl;
    cout<<"   /   |   \\     |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       |         |"<<endl;
    cout<<"       ^         |"<<endl;
    cout<<"      / \\        |"<<endl;
    cout<<"     /   \\       |"<<endl;
    cout<<"    /     \\      | "<<endl;
    cout<<"   /       \\     |"<<endl;
    cout<<"               __|__"<<endl;
}
void hangm::h8()
{
    cout<<"       ___________ "<<endl;
    cout<<"       |         | "<<endl;
    cout<<"       |         | "<<endl;
    cout<<"   ____|____     | "<<endl;
    cout<<"  |         |    | "<<endl;
    cout<<"  |   * *   |    | "<<endl;
    cout<<"  |    ^    |    | "<<endl;
    cout<<"  |  -----  |    | "<<endl;
    cout<<"  |         |    | "<<endl;
    cout<<"  |_________|    | "<<endl;
    cout<<"       |         | "<<endl;
    cout<<"      /|\\        | "<<endl;
    cout<<"     / | \\       | "<<endl;
    cout<<"    /  |  \\      | "<<endl;
    cout<<"   /   |   \\     | "<<endl;
    cout<<"       |         | "<<endl;
    cout<<"       |         | "<<endl;
    cout<<"       ^         | "<<endl;
    cout<<"      / \\        | "<<endl;
    cout<<"     /   \\       | "<<endl;
    cout<<"    /     \\      | "<<endl;
    cout<<"   /       \\     | "<<endl;
    cout<<"               __|__ "<<endl;
}
int main()
{
    hangm ob;
    ob.rules();
    ob.details();
    ob.host1();
    ob.play();
    return 0;
}
