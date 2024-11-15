all: akinator

flags = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

akinator: a.exe
	a.exe Akinator.txt Dump.dot

a.exe: main.o TreeInit.o Dump.o ReadCode.o
	g++ main.o

main.o: main.cpp
	g++ -c $(flags) main.cpp

TreeInit.o: TreeInit.cpp
	g++ -c $(flags) TreeInit.cpp

Dump.o: Dump.cpp
	g++ -c $(flags) Dump.cpp

ReadCode.o: ReadCode.cpp
	g++ -c $(flags) ReadCode.cpp

clean:
	rm -rf *.o *.exe
