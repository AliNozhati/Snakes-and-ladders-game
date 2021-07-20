#ifndef LOGINANDREGISTER_H
#define LOGINANDREGISTER_H

#include <Structure.h>
#include <vector>
using namespace std;

unsigned int CheckLogin (vector <Player>&, string, string);
unsigned int CheckRegister (vector <Player>&, string);
void Readfile (vector <Player>&);
void UpdateFile (Player, vector <Player>&);
void ChangeFile(vector <Player>&);
void change_name (vector <Player>&, string, string);
void change_pass (vector <Player>&, string);
void change_birthday (vector <Player>&, string, string, string);
void change_phone (vector <Player>&, string);
void search_name (vector <Player>&, vector <Player>&, string, string);
void search_user (vector <Player>&, vector <Player>&, string);
void search_score (vector <Player>&, vector <Player>&, string);
void sort (vector <Player>&, bool);
int check_forget(Player,  vector <Player>&);

extern vector <Player> Myplayer;
extern vector <Player> showscore;
extern unsigned int IndexPlayers[5];
extern int CountPlayers, Count;

#endif // LOGINANDREGISTER_H
