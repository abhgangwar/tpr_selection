#include <iostream>
#include <fstream>
#include "functions.h"
#include <cstring>


using namespace std;
ifstream fin;

int main()
{
cout<<"int(\\n): "<<int('\n')<<endl;
cout<<"int(\\r): "<<int('\r')<<endl;

char ch[40],tmp[40];
int rno=11456;
get_name(rno,ch);
strcpy(tmp,"NOT_FOUND\r\n");
cout<<"\nstrcmp() is: "<<strcmp(ch,tmp)<<endl;
for(int j=0;j<50;j++)
	{
	cout<<"ch[j]: "<<ch[j]<<" "<<int(ch[j]);getch();
	cout<<"\ttmp[j]: "<<tmp[j]<<int(tmp[j])<<endl;
	getch();
	}
/*while(rno!=11490)
   26         continue;
    27         }
	}

/*while(rno!=11490)
	{
	get_name(rno,ch);
	cout<<"roll no : "<<rno<<"\tname: "<<ch;
	rno++;
	int i=0;
	while(ch[i]!='\0')
		{
		i++;
		continue;
		}
	cout<<"\n last char of name is : "<<ch[i-1]<<"int(ch[i-1]) : "<<int(ch[i-1])<<"int(ch[i-2]): "<<int(ch[i-2])<<"int(ch[i-3]): "<<int(ch[i-3])<<endl;
	getch();
	}
*/
return 0;
}
