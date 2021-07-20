#ifndef FUNCTION_H
#define FUNCTION_H

#include <Structure.h>
#include <vector>
#include <fstream>
#include <qmessagebox.h>
#include <LoginAndRegister.h>

void Readfile(vector <Player>& Myplayer)
{
    fstream file("C:/Users/ali/Desktop/project_Snakes and ladders game/file.txt", ios::in);

    Player input;
    QMessageBox msgbox;
    Myplayer.clear();
    if(file)
    {
        while(file)
        {
            file >> input.Username >> input.Password >> input.Score
                 >> input.Info.Name >> input.Info.Lastname >> input.Info.Phonenumber
                 >> input.Info.Birthday.Day >> input.Info.Birthday.Mount >> input.Info.Birthday.Year;

            Myplayer.push_back(input);
        }
    }
    else
    {
        msgbox.setText("No file!");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    file.close();
}

unsigned int CheckLogin (vector <Player>& Myplayer, string user, string pass)
{
    unsigned int i = 0;
    for (; i < Myplayer.size(); i++)
    {
        if (Myplayer.at(i).Username == user && Myplayer.at(i).Password == pass)
            return i+1;
    }
    return 0;
}

unsigned int CheckRegister (vector <Player>& Myplayer, string user)
{
    unsigned int i = 0;
    for (; i < Myplayer.size(); i++)
    {
        if (Myplayer.at(i).Username == user)
            return i+1;
    }
    return 0;
}

void UpdateFile(Player p, vector <Player>& myplayer)
{
    fstream file("C:/Users/ali/Desktop/project_Snakes and ladders game/file.txt", ios::app);
    QMessageBox msgbox;

    if(!file)
    {
        msgbox.setText("No file!");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
//        file.close();
    }
    else
    {
        file << endl << p.Username << ' ' << p.Password << ' ' << p.Score << ' ' << p.Info.Name << ' ' << p.Info.Lastname << ' '
             << p.Info.Phonenumber << ' ' << p.Info.Birthday.Day << ' ' << p.Info.Birthday.Mount << ' ' << p.Info.Birthday.Year ;

        file.close();
        Readfile(myplayer);

        msgbox.setText("ok");
        msgbox.setWindowTitle("ok!");
        msgbox.exec();
    }
}

void ChangeFile(vector <Player>& myplayer)
{
    fstream f("C:/Users/ali/Desktop/project_Snakes and ladders game/file.txt", ios::out);
    f.close();

    fstream file("C:/Users/ali/Desktop/project_Snakes and ladders game/file.txt", ios::app);
    QMessageBox msgbox;

    if(!file)
    {
        msgbox.setText("No file!");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else
    {
        unsigned int i = 0;
        for(; i < myplayer.size() - 2; i++)
        {
            file << myplayer[i].Username << ' ' << myplayer[i].Password << ' ' << myplayer[i].Score << ' ' << myplayer[i].Info.Name
                 << ' ' << myplayer[i].Info.Lastname << ' ' << myplayer[i].Info.Phonenumber << ' ' << myplayer[i].Info.Birthday.Day
                 << ' ' << myplayer[i].Info.Birthday.Mount << ' ' << myplayer[i].Info.Birthday.Year << endl;
        }
        file << myplayer[i].Username << ' ' << myplayer[i].Password << ' ' << myplayer[i].Score << ' ' << myplayer[i].Info.Name
             << ' ' << myplayer[i].Info.Lastname << ' ' << myplayer[i].Info.Phonenumber << ' ' << myplayer[i].Info.Birthday.Day
             << ' ' << myplayer[i].Info.Birthday.Mount << ' ' << myplayer[i].Info.Birthday.Year;

        msgbox.setText("Changes were applied");
        msgbox.setWindowTitle("info");
        msgbox.exec();
    }
    file.close();
}

void change_name (vector <Player>& myplayer, string name, string family)
{
    myplayer[IndexPlayers[4]].Info.Name = name;
    myplayer[IndexPlayers[4]].Info.Lastname = family;
    ChangeFile(myplayer);
}

void change_pass (vector <Player>& myplayer, string pass)
{
    myplayer[IndexPlayers[4]].Password = pass;
    ChangeFile(myplayer);
}

void change_birthday (vector <Player>& myplayer, string day, string mount, string year)
{
    myplayer[IndexPlayers[4]].Info.Birthday.Day = day;
    myplayer[IndexPlayers[4]].Info.Birthday.Mount = mount;
    myplayer[IndexPlayers[4]].Info.Birthday.Year = year;
    ChangeFile(myplayer);
}

void change_phone (vector <Player>& myplayer, string phone)
{
    myplayer[IndexPlayers[4]].Info.Phonenumber = phone;
    ChangeFile(myplayer);
}

void search_name (vector <Player>& myplayer, vector <Player>& Showplayer, string name, string family)
{
    QMessageBox msgbox;
    Player p;
    Showplayer.clear();

    for(unsigned int i = 0; i < myplayer.size()-1; i++)
    {
        if(myplayer[i].Info.Name == name && myplayer[i].Info.Lastname == family)
        {
            p.Info.Name = name;
            p.Info.Lastname = family;
            p.Score = myplayer[i].Score;
            Showplayer.push_back(p);
        }
    }
    if(Showplayer.size() == 0)
    {
        msgbox.setText("Does not exist");
        msgbox.setWindowTitle("search");
        msgbox.exec();
    }
}

void search_user (vector <Player>& myplayer, vector <Player>& Showplayer, string user)
{
    QMessageBox msgbox;
    Player p;
    Showplayer.clear();
    for(unsigned int i = 0; i < myplayer.size()-1; i++)
    {
        if(myplayer[i].Username == user)
        {
            p.Info.Name = myplayer[i].Info.Name;
            p.Info.Lastname = myplayer[i].Info.Lastname;
            p.Score = myplayer[i].Score;
            Showplayer.push_back(p);
        }
    }
    if(Showplayer.size() == 0)
    {
        msgbox.setText("Does not exist");
        msgbox.setWindowTitle("search");
        msgbox.exec();
    }
}

void search_score (vector <Player>& myplayer, vector <Player>& Showplayer, string score)
{
    QMessageBox msgbox;
    Player p;
    Showplayer.clear();
    for(unsigned int i = 0; i < myplayer.size()-1; i++)
    {
        string st = to_string(myplayer[i].Score);
        if(st == score)
        {
            p.Info.Name = myplayer[i].Info.Name;
            p.Info.Lastname = myplayer[i].Info.Lastname;
            p.Score = myplayer[i].Score;
            Showplayer.push_back(p);
        }
    }
    if(Showplayer.size() == 0)
    {
        msgbox.setText("Does not exist");
        msgbox.setWindowTitle("search");
        msgbox.exec();
    }
}

void sort (vector <Player>& Showplayer, bool flag)
{
    int size = Showplayer.size();
    Player temp;

    if(flag)
        for(int i = 0; i < size; i++)
        {
            for(int j = i+1; j < size; j++)
            {
                if(Showplayer[i].Score < Showplayer[j].Score)
                {
                    temp = Showplayer[i];
                    Showplayer[i] = Showplayer[j];
                    Showplayer[j] = temp;
                }
            }
        }
    else
        for(int i = 0; i < size; i++)
        {
            for(int j = i+1; j < size; j++)
            {
                if(Showplayer[i].Score > Showplayer[j].Score)
                {
                    temp = Showplayer[i];
                    Showplayer[i] = Showplayer[j];
                    Showplayer[j] = temp;
                }
            }
        }
}

int check_forget(Player p, vector <Player>& myplayer)
{
    for(unsigned int i = 0; i < myplayer.size(); i++)
    {
        if(p.Username == myplayer[i].Username)
        {
            if(p.Info.Name == myplayer[i].Info.Name &&  p.Info.Lastname == myplayer[i].Info.Lastname &&
               p.Info.Phonenumber == myplayer[i].Info.Phonenumber && p.Info.Birthday.Day == myplayer[i].Info.Birthday.Day &&
               p.Info.Birthday.Mount == myplayer[i].Info.Birthday.Mount && p.Info.Birthday.Year == myplayer[i].Info.Birthday.Year)
            {
               return i+1;
            }
        }
    }
    return 0;
}

#endif // FUNCTION_H
