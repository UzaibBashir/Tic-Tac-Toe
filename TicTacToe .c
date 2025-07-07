#include<stdio.h>
void Fpage();       //welcome page
void details(char *name);       //player details
void printbox(char *box);       //print game
void input(char *box, int turn);      //user choise
int check(char *box);       //authentication

int main(){

    char box[] = {'0','1','2','3','4','5','6','7','8','9'};
    char name[20];
    int i;
    int j=10;

    Fpage();
    details(name);
    
    
    for(i=0; i<9; i++){
        if(j){j=0;
        }else{j=10;}

        printf("Turn of: ");
        puts(name+j);
        printbox(box);
        input(box, i);

        int checkin = check(box);
        if(!checkin){
            break;
        }
    }

    int checkin = check(box);

    if(i!=9 || !checkin ){
        printf("\n%s WINS\n", &name+j);
    }else{printf("\nDRAW\n");}

    printbox(box);

    return 0;
}
void Fpage(){
    printf(" \nTIC-TAC-TOE\ndev by:Uzaib\n \nEnter to Start\n");
    char enter;
    scanf("%c", &enter);
}
void details(char *name){
    printf("Enter your Names\n \n");
    printf("player1: ");
    gets(name);
    printf("player2: ");
    gets(name+10);
    printf("\n\n");
}
void printbox(char *box){
    printf(" ___ ___ ___ \n| %c | %c | %c |\n", box[1], box[2], box[3]);
    printf(" ___ ___ ___ \n| %c | %c | %c |\n", box[4], box[5], box[6]);
    printf(" ___ ___ ___ \n| %c | %c | %c |\n", box[7], box[8], box[9]);
    printf(" ___ ___ ___ \n");
}
void input(char *box, int turn){
    int Bno;
    char input;
    printf("Select box: ");
    scanf(" %d", &Bno);
    if(turn%2){
        input='o';
    }else{input='x';}
    
    box[Bno]=input;
}
int check(char *box){
    int j=1;
    //vertical check
    for(int i=1; i<9; i++){
        if(box[i]==box[++i]){
            if(box[i]==box[++i]){
                j=0;
            }
        }
        if(i==2||i==5){i++;}
    }
    //horizantal check
    for(int i=1; j&&(i<4); i++){
        if(box[i]==box[i+3]){
            if(box[i+3]==box[i+6]){
                j=0;
            }
        }
    }
    //diagonal check
    if(box[1]==box[5]){
        if(box[5]==box[9]){
            j=0;
        }
    }
    if(box[3]==box[5]){
        if(box[5]==box[7]){
            j=0;
        }
    }
    
    return j;
}
