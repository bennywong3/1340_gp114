time_list.o: time_list.cpp time_list.h
	g++ -c time_list.cpp

layout.o: layout.cpp layout.h
	g++ -c layout.cpp

print_layout.o: print_layout.cpp print_layout.h
	g++ -c print_layout.cpp

occupy.o: occupy.cpp occupy.h time_list.h
	g++ -c occupy.cpp

release.o: release.cpp release.h time_list.h
	g++ -c release.cpp

file_in_out.o: file_in_out.cpp file_in_out.h time_list.h
	g++ -c file_in_out.cpp

main.o: main.cpp
	g++ -c main.cpp

main: main.o time_list.o layout.o print_layout.o occupy.o release.o file_in_out.o
	g++ main.o time_list.o layout.o print_layout.o occupy.o release.o file_in_out.o -o main

clean:
	rm main *.o
