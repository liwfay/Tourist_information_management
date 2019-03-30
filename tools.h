#include<windows.h> //to use sleep function
#include<time.h> //to use function time()
#include<stdlib.h> //to use sand() and so on

#define Ok 0;
#define Err -1;

struct date
{
    int year;
    int month;
    int day;
};

struct tourist
{
    char placename[40];
    char name[20];
    char sex;
    __int64 pernum;     //Identificaton
    char phone[15];
    struct date time;
    int dot;//出游时长（Duration of travel）
};


int Download(struct tourist t[], int number)
{

	FILE *fp = NULL;
	if((fp = fopen("test.txt","a")) == NULL)
	   return Err;
 	
	fscanf(fp, "%s %s %c %I64d %s %d %d %d %d",
	t[number].name, t[number].placename, &t[number].sex, &t[number].pernum, t[number].phone, 
	&t[number].time.year, &t[number].time.month, &t[number].time.day, &t[number].dot);

   fclose(fp);
   return Ok;
}

int Upload(struct tourist t[], int number)
{
	FILE *fp = NULL;
	if((fp = fopen("test.txt","a")) == NULL)
	   return Err;
 	
	fprintf(fp, "%s %s %c %I64d %s %d %d %d %d\n",
	t[number].name, t[number].placename, t[number].sex, t[number].pernum, t[number].phone, 
	t[number].time.year, t[number].time.month, t[number].time.day, t[number].dot);
   fclose(fp);
   return Ok;
}

int UploadAll(struct tourist t[], int number)
{
	FILE *fp = NULL;
	if((fp = fopen("test.txt","w")) == NULL) //clear test.txt and rewrite
	   return Err;
 	for(int i = 1; i <= number; i++)
	{
	    fprintf(fp, "%s %s %c %I64d %s %d %d %d %d\n",
    t[i].name, t[i].placename, t[i].sex, t[i].pernum, t[i].phone, 
	t[i].time.year, t[i].time.month, t[i].time.day, t[i].dot);
	}
	fclose(fp);
   return Ok;
}
int loading(int num)
{
	printf("\nLoading: ");
	srand(time(NULL));
	
	for(int i = 1; i <= num; i++)
	{
		printf("#");
		Sleep(rand()%200);
	}
	system("cls");
	return Ok;
}

void bar()
{
	for(int i = 1; i <= 40; i++)
	printf("#");
	printf("\n");
}
