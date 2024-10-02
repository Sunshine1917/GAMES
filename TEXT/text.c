#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "letters.h"
#include <termios.h>
#include <fcntl.h>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"


//PROTOTYPE OF FUNCTION TO PRINTF LETTERS
void print(char A[9][9], int row, int offset, int width,int *controlador);

//PROTOTYPEOF FUNTION TO PRINT SPACE
void space(int a);

//PROTOTYPE OF FUNCTION TO PRINT SPACE
void print_space(char A[9][7], int row, int offset, int width,int *controlador);

//PROTOTYPE OF FUNCTION TO SWITCH THE TERMINAL TO UNBUFFER MODE
void enableRawMode();

//PROTOTUPE OF FUNCTION TO RESTORETHE TERMINAL TO NORMAL MODE
void disableRawMode(); 

//PROTOTYPE OF FUNCTION TO DETECT IF A KEY IS PRESSED
int kbhit();

//-------HERE STAR THE MAIN FUNCTION-------//
int main(){
char msj[100]; //Varibale to save the msj to be print
int width;     //Variable to save the width of the terminal
int high;  	   //Varaibale to save the high of the terminal

//GET THE SIZE OF THE TERMINAL
struct winsize w;
ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
width = w.ws_col;  // Get the width of the terminal
high = w.ws_row;   // Get the high of the terminal

printf("ESCRIBE EL MENSAJE A MOSTRAR EN PANTALLA\n");
fgets(msj, 100, stdin); //READ CHARACTERS INCLUDE SPACE

enableRawMode();

int length=(strlen(msj))-1;

int row=0;
int controlador=0;
int espacios=0;
int center= high/2 - 4; 
int offset = width; 

while(1){
if(espacios==0){	
 printf("\033[%dB",center);
 espacios=1;
}
for(int contador=0;contador<length;contador++){
switch(msj[contador]){
	case 'A':print(letter_A,row,offset,width,&controlador);break;
	case 'B':print(letter_B,row,offset,width,&controlador);break;
	case 'C':print(letter_C,row,offset,width,&controlador);break;
	case 'D':print(letter_D,row,offset,width,&controlador);break;
	case 'E':print(letter_E,row,offset,width,&controlador);break;
	case 'F':print(letter_F,row,offset,width,&controlador);break;
	case 'G':print(letter_G,row,offset,width,&controlador);break;
	case 'H':print(letter_H,row,offset,width,&controlador);break;
	case 'I':print(letter_I,row,offset,width,&controlador);break;
	case 'J':print(letter_J,row,offset,width,&controlador);break;
	case 'K':print(letter_K,row,offset,width,&controlador);break;
	case 'L':print(letter_L,row,offset,width,&controlador);break;
	case 'M':print(letter_M,row,offset,width,&controlador);break;
	case 'N':print(letter_N,row,offset,width,&controlador);break;
	case 'O':print(letter_O,row,offset,width,&controlador);break;
	case 'P':print(letter_P,row,offset,width,&controlador);break;
	case 'Q':print(letter_Q,row,offset,width,&controlador);break;
	case 'R':print(letter_R,row,offset,width,&controlador);break;
	case 'S':print(letter_S,row,offset,width,&controlador);break;
	case 'T':print(letter_T,row,offset,width,&controlador);break;
	case 'U':print(letter_U,row,offset,width,&controlador);break;
	case 'V':print(letter_V,row,offset,width,&controlador);break;
	case 'W':print(letter_W,row,offset,width,&controlador);break;
	case 'X':print(letter_X,row,offset,width,&controlador);break;
	case 'Y':print(letter_Y,row,offset,width,&controlador);break;
	case 'Z':print(letter_Z,row,offset,width,&controlador);break;
	case 'a':print_space(letter_a,row,offset,width,&controlador);break;
	case 'b':print_space(letter_b,row,offset,width,&controlador);break;
	case 'c':print_space(letter_c,row,offset,width,&controlador);break;
	case 'd':print_space(letter_d,row,offset,width,&controlador);break;
	case 'e':print_space(letter_e,row,offset,width,&controlador);break;
	case 'f':print_space(letter_f,row,offset,width,&controlador);break;
	case 'g':print_space(letter_g,row,offset,width,&controlador);break;
	case 'h':print_space(letter_h,row,offset,width,&controlador);break;
	case 'i':print_space(letter_i,row,offset,width,&controlador);break;
	case 'j':print_space(letter_j,row,offset,width,&controlador);break;
	case 'k':print_space(letter_k,row,offset,width,&controlador);break;
	case 'l':print_space(letter_l,row,offset,width,&controlador);break;
	case 'm':print_space(letter_m,row,offset,width,&controlador);break;
	case 'n':print_space(letter_n,row,offset,width,&controlador);break;
	case 'o':print_space(letter_o,row,offset,width,&controlador);break;
	case 'p':print_space(letter_p,row,offset,width,&controlador);break;
	case 'q':print_space(letter_q,row,offset,width,&controlador);break;
	case 'r':print_space(letter_r,row,offset,width,&controlador);break;
	case 's':print_space(letter_s,row,offset,width,&controlador);break;
	case 't':print_space(letter_t,row,offset,width,&controlador);break;
	case 'u':print_space(letter_u,row,offset,width,&controlador);break;
	case 'v':print_space(letter_v,row,offset,width,&controlador);break;
	case 'w':print_space(letter_w,row,offset,width,&controlador);break;
	case 'x':print_space(letter_x,row,offset,width,&controlador);break;
	case 'y':print_space(letter_y,row,offset,width,&controlador);break;
	case 'z':print_space(letter_z,row,offset,width,&controlador);break;
	case ' ':print_space(space_L,row,offset,width,&controlador);break;
	default: break;
	}//End of the switch
} //End of for

	printf("\n");
	row++;
	controlador=0;
	if(row == 8) {
	usleep(100000);
	system("clear"); 
	offset--; // Mover texto hacia la izquierda	
	row=0;
	espacios=0;
	}
	if (offset > 0) {
        space(offset); // Añadir espacio si el texto aún no ha entrado
    }
	if (offset < -9 * length) {
            offset = width; // Reiniciar el desplazamiento desde la derecha
        }
	if (kbhit()) {
            break;
        }
	}//End of the while
	disableRawMode();
	 return 0;
}//End of the main

//-------FUNCTION TO PRINTF LETTERS-------//
void print(char A[9][9], int row, int offset, int width,int *controlador){	
		for(int j=0;j<9;j++){
			if (offset + *controlador >= 0 && offset + *controlador < width) {
                printf(MAGENTA "%c" RESET, A[row][j]);
            }
			(*controlador)++;
		}
}

//-------FUNCTION TO PRINTF SPACE-------//
void print_space(char A[9][7], int row, int offset, int width,int *controlador){	
		for(int j=0;j<7;j++){
			if (offset + *controlador >= 0 && offset + *controlador < width) {
                printf(MAGENTA "%c" RESET, A[row][j]);
            }
			(*controlador)++;
		}
}

//-------FUNCTION TO PRINTF SPACE-------//
void space(int a){
	for(int i=0;i<a;i++){
		printf(" ");
	}
}

//-------FUNCTION TO SWITCH THE TERMINAL TO UNBUFFER MODE-------//
void enableRawMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);      // Gets the attributes of the terminal
    term.c_lflag &= ~(ICANON | ECHO);    // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term); // Apply the changes
}

//-------FUNCTION TO RESTORETHE TERMINAL TO NORMAL MODE-------//
void disableRawMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);       // Gets the current attributes of the terminal
    term.c_lflag |= (ICANON | ECHO);      // Reactivate canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);  // Apply the changes
}

//-------FUNCTION TO DETECT IF A KEY IS PRESSED-------//
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt); // Gets the current attributes of the terminal
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}


