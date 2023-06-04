//Header Files
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define MAX 100

typedef struct { // array of structures
char n[31];
int q1;
int q2;
int q3;
} REC;

typedef struct { //array of structures with structures
REC st[MAX];
int last;
} LIST;

//Global declaration for LIST
LIST L;

//Function Prototypes
void makenull(); //empties the arrays
void save(); //saves the array into file
void retrieve(); //retrieves array from the file
void insert(char name[31],int quiz1,int quiz2,int quiz3); 	// inserts data to arrays
void del(char name[31]); //deletes from array
void display(); // displays contents of array
int isfull(); // determines if the list is full
int isempty(); //determines if the list empty
int locate(char name[31]); //locates the index of a particular value

int menu();

int main(){
    makenull(); //empties the array
    retrieve(); //retrieves data from file

    int ans;
    printf("\n\n\tWELCOME TO STUDENT GRADE MANAGEMENT!");
    printf("\n\n\tPress any key to continue...");
    getch();	//welcome greetings
    system ("cls");
        while (1) {
        ans= menu();
        switch (ans){ //switch function allows user to have multiple choices
        char name [31];
        int quiz1,quiz2,quiz3;

        case 1:		//case 1 allows us to have access to insert function
        system ("cls");
        printf ("Insert mode\n");
        printf("\nEnter your name: ");
        scanf(" %[^\n]s",name);
        printf("Please input your score in\n");
        printf("QUIZ 1: ");
        scanf("%d", &quiz1);
        printf("QUIZ 2: ");
        scanf("%d",&quiz2);
        printf("QUIZ 3: ");
        scanf("%d",&quiz3);
        printf("\n");
        insert (name,quiz1,quiz2,quiz3);
        break;

        case 2:		//case 2 allows us to have acces to delete function
        system ("cls");
        printf ("Delete mode\n");
        display ();
        printf("Enter the student's name: ");
        scanf("%s",name);
        del (name);
        break;

        case 3: 	//case 3 displays the contents
        display ();
        getch() ;
        break;

        case 4:
            system("cls");
            display();
            printf("Enter the student's name: ");
            scanf("%s",name);	//case 4 lets us exit to the program
           update(name);
           break;
        case 5:
            save();
            exit(0);
        default:
        printf("1-4 only."); getch ();
        }
}
}

void makenull()
{
    L.last = -1;}

void insert(char name[31],int quiz1,int quiz2,int quiz3)
{   int i,p;
        if (isfull ()){
            printf("List is full.");
            getch();
        }
        else{
            if(locate(name)>=0){
                printf("record existing");getch();}
            else{
            p=pos(name);
            for (i=L.last;i>=p;i--){
               strcpy(L.st[i+1].n, L.st[i].n);
               L.st[i+1].q1 = L.st[i].q1;
               L.st[i+1].q2 = L.st[i].q2;
               L.st[i+1].q3 = L.st[i].q3;}



               strcpy(L.st[p].n, name);
               L.st[p].q1 = quiz1;
               L.st[p].q2 = quiz2;
               L.st[p].q3 = quiz3;
               L.last++;}

        }
}
void del(char name[31])
{
    int p;
    if(isempty()){
        printf("List is empty.");
        getch();
    }else{
        p= locate(name);
    if (p<0){
        printf("Not found.");
        getch();
    }else{
        for (int i = p;i<L.last;i++){
        strcpy(L.st[i].n,L.st[i+1].n);
        L.st[i].q1 = L.st[i+1].q1;
        L.st[i].q2 = L.st[i+1].q2;
        L.st[i].q3 = L.st[i+1].q3;
        }
    L.last--;
        }
    }
}
int isfull()
{
    return (L.last == MAX-1);
}

int isempty()
{
    return (L.last == -1);
}

int locate(char name[31]){
    for (int i = 0; i<= L.last; i++)
         if (strcmp(L.st[i].n, name)==0)
                return (i);
    return(-1);
}

void display()
{
    int i;
    float ave;

    system("cls"); //clears our screen
    printf("\tNAME\t\tQUIZ 1\tQUIZ 2\tQUIZ 3\t AVERAGE   REMARKS\n");
    printf("===================================================================\n");
    for(i=0; i<L.last + 1;i++){
    ave =(float)(L.st[i].q1 + L.st[i].q2 + L.st[i].q3)/3;  //calculate the average
    printf(" %d.)\t%s\t\t  %d\t  %d\t %d\t %6.2f\t   %s\n",i+1,L.st[i].n, L.st[i].q1, L.st[i].q2, L.st[i].q3,ave,ave>=75.0 ? "PASSED":"FAILED");}
}

int menu (){
int i, opt;
char *m[] = {"Insert","Delete","Display","Update","Save and Exit"};
system ("cls");
printf("MENU\n");
for (i=0; i<5;i++ )
    printf("%d.) %s\n", i+1, m[i]);
    printf("\n Select (1-5): ");
    scanf(" %d",&opt);
    return (opt);
}

void save (){ // function save
FILE *fp;
int i;
float ave;
fp= fopen ("record.dbf", "w+");
if (fp==NULL){
    printf("File Error. \n");
    system ("pause");
} else {
for (i=0;i<=L.last;i++)
{
    fprintf(fp,"\n%s\t\t  %d\t  %d\t %d\t",L.st[i].n, L.st[i].q1, L.st[i].q2, L.st[i].q3); // prints the elements of list in the file
}
}
fclose(fp);
}

void retrieve (){ // function retrieve
//variables
 FILE *fp;
char name[31];
int quiz1,quiz2,quiz3;
    if ((fp=fopen("record.dbf", "r+"))!=NULL){
    while (!feof (fp)){ //while it is not the end of the file-
            fscanf(fp,"%s %d %d %d\n", name, &quiz1, &quiz2, &quiz3); // scans the record
            if (L.last>=1){insert(name ,quiz1,quiz2,quiz3);} //calls our insert function and passes the parameters
        }
    }
    fclose(fp);
}

int pos(char name[31])
{
int i;
    for (i = 0; i<= L.last; i++) // loop from first index to the last index containing element
         if (strcasecmp(L.st[i].n,name) >0 ) // compare two strings if same it will return the index
                return (i);
    return(i);
}

void update(char name[31])
{

int p,quiz1,quiz2,quiz3;
    if(isempty()){
        printf("List is empty.");
        getch();
    }else{
        p= locate(name);
    if (p<0){
        printf("Not found.");
        getch();
    }else{
        printf("input new grade:\n ");
        printf("quiz 1: ");
        scanf("%d",&quiz1);
        printf("quiz 2: ");
        scanf("%d",&quiz2);
        printf("quiz 3: ");
        scanf("%d",&quiz3);
        L.st[p].q1=quiz1;
        L.st[p].q2=quiz2;
        L.st[p].q3=quiz3;

        }
    }

}
