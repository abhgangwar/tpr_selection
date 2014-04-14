#include<iostream>
#include<fstream>
#include<cstdlib>
//#include<conio.h>
#include<cstring>
#include"functions.h"
#include"graph.h"
#define MAX_VOTE  90
#define CONV  48
#define MAX_CAND  4
#define CAND_NAMES  {"Arihant", "Narendra", "Nishant", "Tapan"}
using namespace std;

ofstream fout;
ifstream fin;
char cl;

// prototype for function to check whether roll number exists in database or not
int roll_check (int);

class count
{
public:
  int res[MAX_CAND];
  int cnt;
} v_cnt, vcnt_tmp;

int
c_update (int v)
{
  int r = 1;

  fin.open ("cnt", ios::in);
  if (!fin)
    cout << "\nUnable to open file";
  while (fin)
    fin.read ((char *) &vcnt_tmp, sizeof (vcnt_tmp));
  v_cnt = vcnt_tmp;
  fin.close ();
  if (v > MAX_CAND)
    {
      cout << "Unable to determine correct vote ...Please try again" << endl;
      return 0;
    }

  ++v_cnt.res[v - 1];
  ++v_cnt.cnt;
  return 1;
}

int check_roll (int);

class stud
{
public:
  int roll_no;
  int ch;
  char name[40];
  int get_vote ()
  {
    int r = 1;
    string str;
      cout << "\nenter roll no: ";
      getline (cin, str);
      roll_no = atoi (str.c_str ());
      get_name (roll_no, name);
      cout << "\nHello " << name;
    if (!strcmp (name, "NOT_FOUND\r\n"))
      {
	cout <<
	  "\nRoll no. doesn't exist...Don't try to be smart....Machine is smart enough to judge you";
	r = 0;
      }
    else
      {
	if (check_roll (roll_no))
	  {
	    cout <<
	      "\n							Enter Choice [ enter only 1 2 3 or 4]"
	      << endl;
	    cout <<
	      "								1. Arihant"
	      << endl;
	    cout <<
	      "								2. Narendra"
	      << endl;
	    cout <<
	      "								3. Nishant"
	      << endl;
	    cout <<
	      "								4. Tapan"
	      << endl;
	    char temp = getch ();
	    cout << "*";
	    ch = int (temp) - CONV;
	    r = c_update (ch);
	  }
	else
	  {
	    cout <<
	      "\nYou have already voted......don't ever try to fuck a machine you silly";
	    getch ();
	    r = 0;
	  }
      }
    return r;
  }
}

st, stemp;


int
check_roll (int rno)
{
  fin.open ("data", ios::in);
  if (!fin)
    {
      cout << " \nUnable to open data file" << endl;
    }
  while (fin)
    {
      fin.read ((char *) &stemp, sizeof (stemp));
      if (stemp.roll_no == rno)
	{
	  return 0;
	}
    }
  fin.close ();
return 1}

int write_data (void);

int
opmenu ()
{
  int r = 0;
  while (1)
    {
      r = st.get_vote ();
      if (r == 1)
	{
	  write_data ();
	  break;
	}
    }
  return r;
}

int
write_data ()
{
  int r = 0;
  fout.open ("data", ios::app);
  fout.write ((char *) &st, sizeof (st));
  fout.close ();
  fout.open ("data_.txt", ios::app);
  fout << st.roll_no << "\t" << st.ch << endl;
  fout.close ();
  fout.open ("cnt", ios::app);
  fout.write ((char *) &v_cnt, sizeof (v_cnt));
  fout.close ();
  fout.open ("cnt_.txt", ios::app);
  fout << "res[1]	" << v_cnt.res[0] << "	res[2]	" << v_cnt.
    res[1] << "	res[3]	" << v_cnt.res[2] << "	res[4]	" << v_cnt.
    res[3] << endl;
  fout.close ();
  cout << "\nThankyou " << st.
    name << "Your vote has been registered successfully";
  r = 1;
  return r;
}

int
start_vote ()
{
  int r = 0;
  char c = 'y';
  while (1)
    {
      opmenu ();
      cout << "\n\nTotal " << v_cnt.
	cnt << "  no. of votes have been registered" << endl;
      if (v_cnt.cnt > MAX_VOTE)
	{
	  cout << "\nMAXIMUM no of votes have been registered....." << endl;
	  cin.ignore ();
	  r = 1;
	  return r;
	}
      cout << "\nProceed next....[y/n]" << endl;
      cin >> c;
      cin.ignore ();
      if (c == 'n' || c == 'N')
	break;
      system ("clear");
    }
  r = 1;
  return r;
}

int
main ()
{
  int r = 0;
  r = start_vote ();
  if (r == 1)
    cout << " \nVoting Completed successfuly......." <<
      "\n\n\n\n			                  Showing results now.."
      << endl;
  getch ();
  system ("clear");
  cout <<
    "\n\n								$$$$$	RESULTS  $$$$$\n\n\n\n\n";
  string cand_names[] = CAND_NAMES;
  graph (cand_names, v_cnt.res, MAX_CAND);
  getch ();
  return 1;
}
