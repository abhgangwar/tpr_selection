                                                                This is Electronic TPR Selection Machine
Following are some guidelines to setup the app and its use.

COMPILING :
   -->On Unix based systems having 'make' utility:
      Just type "make" on terminal and you are ready to use the file "elect.out" in current folder.
   -->Doesn't have make utility:
      just type " g++ elect.cpp functions.cpp graph.cpp term_noecho.cpp -o elect.out "
	  Then you can find elect.out in same folder.Just run this file."

1. The file studentDetails contains the student database( Each line contains Roll no. and  Name seperated by TAB character for a student ).
2. The file "data_.txt" contatins complete detail of which student ( Roll no. ) has voted to whom. File "cnt_.txt" is appended everytime a student votes with a line containing the         
   no. of votes that each condidate has received till then.
3. Everytime the application starts it reads the files "cnt" and "data". So, it will not let a person vote if he/she has voted in any previous execution of program. If you don't
   want this to happen, remove the files ( data, cnt, data_.txt, cnt_.txt ) by running rm.do or manually.

Although the program gives you the final value for all conditates, everytime you run it, you can alsways check where the file data.