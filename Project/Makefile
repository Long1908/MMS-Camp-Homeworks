
build: PPM_project.c PPM_header.h PPM_functions.c
	gcc -c PPM_functions.c
	gcc -c PPM_project.c
	gcc PPM_project.o PPM_functions.o -o my_filterEXE

clean:
	rm -r ./PPM_project.o
	rm -r ./PPM_functions.o
	rm -r ./my_filterEXE
