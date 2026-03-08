#include <stdio.h>

#define NO_SCORE 5
#define NO_STD 10

typedef struct{
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
}Student;

void readStudent(Student *);
void calcTotal(Student *);
float calcAvg(Student);
void showLessTen(Student);

int main(){

    Student s[NO_STD];
    FILE *fp;
    int i;

    for(i=0;i<NO_STD;i++){
        printf("\nStudent %d\n",i+1);
        readStudent(&s[i]);
    }

    fp=fopen("std10.dat","wb");

    if(fp==NULL){
        printf("File error");
        return 1;
    }

    fwrite(s,sizeof(Student),NO_STD,fp);
    fclose(fp);

    fp=fopen("std10.dat","rb");

    if(fp==NULL){
        printf("File error");
        return 1;
    }

    fread(s,sizeof(Student),NO_STD,fp);
    fclose(fp);

    for(i=0;i<NO_STD;i++){

        printf("\n-----------------------\n");
        printf("%s %s\n",s[i].name,s[i].surname);

        calcTotal(&s[i]);
        printf("Total = %.2f\n",s[i].total);

        printf("Average = %.2f\n",calcAvg(s[i]));

        showLessTen(s[i]);
    }

    return 0;
}

void readStudent(Student *p){

    int i;

    printf("Name : ");
    scanf("%s",p->name);

    printf("Surname : ");
    scanf("%s",p->surname);

    for(i=0;i<NO_SCORE;i++){
        printf("Score %d : ",i+1);
        scanf("%d",&p->score[i]);
    }
}

void calcTotal(Student *p){

    int i;

    p->total=0;

    for(i=0;i<NO_SCORE;i++){
        p->total+=p->score[i];
    }
}

float calcAvg(Student s){
    return s.total/NO_SCORE;
}

void showLessTen(Student s){

    int i,c=0;

    printf("Score < 10");

    for(i=0;i<NO_SCORE;i++){
        if(s.score[i]<10){
            printf("\nTest %d : %d",i+1,s.score[i]);
            c++;
        }
    }

    if(c==0){
        printf(" None");
    }

    printf("\n");
}
