PersonalInfo:New.o getPass.o Existing.o trie.o srnHandle.o QFunct.o extract.o shift.o Decrypt.o Encrypt.o PersonalInfo.o
	gcc New.o getPass.o Existing.o trie.o srnHandle.o QFunct.o extract.o shift.o Decrypt.o Encrypt.o PersonalInfo.o -o PersonalInfo
PersonalInfo.o:PersonalInfo.c functions.h
	gcc -c PersonalInfo.c 
Encrypt.o:Encrypt.c functions.h
	gcc -c Encrypt.c 
Decrypt.o:Decrypt.c functions.h
	gcc -c Decrypt.c
shift.o:shift.c functions.h
	gcc -c shift.c
extract.o:extract.c functions.h
	gcc -c extract.c
QFunct.o:QFunct.c functions.h
	gcc -c QFunct.c
srnHandle.o:srnHandle.c functions.h
	gcc -c srnHandle.c
trie.o:trie.c functions.h
	gcc -c trie.c
Existing.o:Existing.c functions.h
	gcc -c Existing.c
getPass.o:getPass.c functions.h
	gcc -c getPass.c
New.o:New.c functions.h
	gcc -c New.c
clean:
	rm *o