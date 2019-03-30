#include<stdio.h>
#include<string.h>
#include"tools.h" //written by my self

int global_client_number = 0; //global veriate, to record the global_client_number of client

void Menu(struct tourist t[]); //the menu of the user interface
int Add(struct tourist t[]); //add info
int Input(struct tourist t[]); //to scan the information(info) of tourist

int Output(struct tourist t[], int i); //print a tourist's info
int Print(struct tourist t[]); //print all tourist's info

int Edit(struct tourist t[]); //edit info

int Search(struct tourist t[]); //search info
int SearchByName(struct tourist t[]);
int SearchByTime(struct tourist t[]);
int SearchBySite(struct tourist t[]);

int Delete(struct tourist t[]); //delete info
int DeleteByName(struct tourist t[]);
int DeleteByTime(struct tourist t[]);
int DeleteBySite(struct tourist t[]);

int Order(struct tourist t[]); //order info
int OrderByName(struct tourist t[]); //order by name
int OrderByTime(struct tourist t[]); //order by time
int OrderBySite(struct tourist t[]); //order by site


int main() //the entrance of programe
{
    struct tourist client[10]; //define tourist array
    Menu(client);
    return 0;
}

void Menu(struct tourist t[]) //the menu of the user interface
{
    system("cls");
    fflush(stdin); //clear cache
    bar(); //print # * 40
    printf("Tourist Information Management System\n");
    printf("Input a number to execute command which be tabbed\n\n");
    printf("1.Add the information of tourist\n");
    printf("2.Delete the information of tourist\n");
    printf("3.Edit the information of tourist\n");
    printf("4.Search the information of tourist\n");
    printf("5.Sort the information of tourist\n");
    printf("6.Display the information of tourist\n");
    printf("0.Exit!!!\n");
    printf("What would you wanna do ?: ");
    fflush(stdin);
    switch(getchar()) //switch 
    {
        case '1': Add(t); break;
        case '2': Delete(t); break;
        case '3': Edit(t); break;
        case '4': Search(t); break;
        case '5': Order(t); break;
        case '6': Print(t); break;
        case '0':system("cls"); printf("Thanks for your use !!!"); Sleep(1500); goto loop; //to break the loop of menu
        default:printf("There is something wrong with your input, please try again\n"); Sleep(1500); break;
    }
    Menu(t);
loop:;
} //end of menu

int Add(struct tourist t[]) //add
{
    while(1)
    {
        system("cls");
        global_client_number++;
        Input(t);
        Upload(t, global_client_number);
        printf("Continue[y/n] ? : ");
        fflush(stdin);//clear buffer
        char sign = getchar();
        if(sign == 'N' || sign == 'n') //???
        {
            printf("Saving\n");
            loading(25);
            break;
        }
 //       else
 //       global_client_number++; //the number of client plus one
    }
    return Ok;
} //end of add

int Input(struct tourist t[]) //input
{
    printf("Please input %dth information of tourist\n", global_client_number); //I fucked it up
    printf("Name : ");
    scanf("%s",t[global_client_number].name);
    getchar();
    printf("Scenic : ");
    scanf("%s",t[global_client_number].placename);
    getchar();
    printf("sex : ");
    scanf("%c",&t[global_client_number].sex);
    getchar();
    printf("Identification :");
    scanf("%I64d",&t[global_client_number].pernum);
    getchar();
    printf("Phone No. : ");
    scanf("%s",t[global_client_number].phone);
    getchar();
    printf("Date : ");
    scanf("%d%d%d",&t[global_client_number].time.year,&t[global_client_number].time.month,&t[global_client_number].time.day);
    getchar();
    printf("DoT : ");
    scanf("%d",&t[global_client_number].dot);
    return Ok;
}//end of input

int Output(struct tourist t[], int i)
{
    printf("%6.6s",t[i].name);
    printf("%10.10s ",t[i].placename);
    printf("\t%c ",t[i].sex);
    printf("%I64d ",t[i].pernum);
    printf("%11.11s ",t[i].phone);
    printf("%4d-%02d-%02d ",t[i].time.year,t[i].time.month,t[i].time.day);
    printf("\t%d",t[i].dot);
   return Ok;
} //end of output

int Print(struct tourist t[]) //print
{
    printf("Name\tScenic\tSex\tIdentification\tPhone\t\tdate\tDoT\n\n");
    for(int i = 1; i <= global_client_number; i++)
    {
        Output(t, i); //used function output
        printf("\n");
    }
    printf("\n");
    fflush(stdin);
    system("pause");
    return Ok;
} //end of print

int Edit(struct tourist t[]) //edit //???????????????? ???????
{
  system("cls");
  int m,i;
  char sel='y';
  i=SearchByName(t);
  if(i<0)
    printf("Not found it\n");
  else
  {
    printf("The information of tourist is : \n");
    Output(t,i);
    while(sel=='y')
     {
       printf("\n\nWhich info do you wanna edit ? : \n");
       printf("1.Name\n");
       printf("2.Scenic\n");
       printf("3.Sex\n");
       printf("4.Identification\n");
       printf("5.Phone No.\n");
       printf("6.Date\n");
       printf("7.DoT\n");
       scanf("%d",&m);
       getchar();
       switch(m)
           {
             case 1:printf("Name : \n");
                    scanf("%s",t[i].name);
                    getchar();
                    break;
             case 2:printf("Scenic : \n");
                    scanf("%s",t[i].placename);
                    getchar();
                    break;
             case 3:printf("Sex : \n");
                    scanf("%c",&t[i].sex);
                    getchar();
                    break;
             case 4:printf("Identificaion : \n");
                    scanf("%I64d",&t[i].pernum);
                    getchar();
                    break;
             case 5:printf("Phone No. : \n");
                    scanf("%s",t[i].phone);
                    getchar();
                    break;
             case 6:printf("Date : \n");
                    scanf("%d%d%d",&t[i].time.year,&t[i].time.month,&t[i].time.day);
                    getchar();
                    break;
             case 7:printf("DoT : \n");
                    scanf("%d",&t[i].dot);
                    getchar();
                    break;
           }
       printf("Continue[y/n] ? : ");
       scanf("%c",&sel);
       getchar();
    }
  }
       return Ok;
} //end of edit

int Search(struct tourist t[])
{
    system("cls");
    bar();
    printf("0.Return\n1.Search by name\n2.Search by site\n3.Search by date\n");
    printf("Seclect one ? : ");
    fflush(stdin);
    switch(getchar())
    {
        case '1': printf("Name : "); Output(t, SearchByName(t)); printf("\n"); system("pause"); break;
        case '2': printf("Time : "); Output(t, SearchByTime(t)); printf("\n"); system("pause"); break;
        case '3': printf("Scenic : "); Output(t, SearchBySite(t)); printf("\n"); system("pause"); break;
        default: break;
    }
    return Ok;
} //end of search

int SearchByName(struct tourist t[]) //search by name
{
 //   system("cls");
    fflush(stdin);
 //   int sign = 0; //a mark when name be matched, sign = 1
    char name[20];  //temp virable
    scanf("%s", name);

    for(int i = 1; i <= global_client_number; i++)
    {
        if(strcmp(t[i].name, name) == 0)
 //       sign = 1; //found it
        return i;
    }
    printf("Not found it...");
    return Err;
}//end of SearchByName

int SearchByTime(struct tourist t[]) //Search By Time
{
//    int sign = 0; //a mark when name be matched, sign = 1
    int year, month, day;  //temp virable
    
    fflush(stdin);
    scanf("%d%d%d", &year, &month, &day);

    for(int i = 1; i <= global_client_number; i++)
    {
        if(year == t[i].time.year && month == t[i].time.month && day == t[i].time.day)
//       sign = 1; //found it
        return i;
    }
    printf("Not found it...");
    return Err;
} //end of SearchByTime

int SearchBySite(struct tourist t[]) //search by site
{
//    int sign = 0; //a mark when name be matched, sign = 1
    char placename[40]; //temp virable
    
    fflush(stdin);
    scanf("%s", placename);

    for(int i = 1; i <= global_client_number; i++)
    {
        if(strcmp(t[i].placename, placename) == 0)
 //       sign = 1; //found it
        return i;
    }
    printf("Not found it...");
    return Err;
} //end of SearchBySite

int Delete(struct tourist t[]) //Delete
{
    system("cls");
    bar();
    printf("0.Return\n1.Delete by name\n2.Delete by time\n3.Delete by site\n");
    printf("Select one ? : ");
    fflush(stdin);
    switch(getchar())
    {
        case '1': DeleteByName(t); break;
        case '2': DeleteByTime(t); break;
        case '3': DeleteBySite(t); break;
        default:break;
    }
    return Ok;
} //end of delete

int DeleteByName(struct tourist t[]) //delete by name
{
    system("cls");
    printf("Name : ");
    int i = SearchByName(t); //used function searchbyname
    for(;i < global_client_number; i++)
    {
        strcpy(t[i].name, t[i+1].name);
        strcpy(t[i].placename, t[i+1].placename);
        t[i].sex = t[i+1].sex;
        t[i].pernum = t[i+1].pernum;
        strcpy(t[i].phone, t[i+1].phone);
        t[i].time.year = t[i+1].time.year;
        t[i].time.month = t[i+1].time.month;
        t[i].time.day = t[i+1].time.day;
    }
    global_client_number--; //when the info be deleted, the number of client minus one
    UploadAll(t, global_client_number);
    loading(25);
    return Ok;
} //end of deletebyname

int DeleteByTime(struct tourist t[]) //delete by time
{
    system("cls");
    printf("Time : ");
    int i = SearchByTime(t);
    for(;i < global_client_number; i++)
    {
        strcpy(t[i].name, t[i+1].name);
        strcpy(t[i].placename, t[i+1].placename);
        t[i].sex = t[i+1].sex;
        t[i].pernum = t[i+1].pernum;
        strcpy(t[i].phone, t[i+1].phone);
        t[i].time.year = t[i+1].time.year;
        t[i].time.month = t[i+1].time.month;
        t[i].time.day = t[i+1].time.day;
    }
    global_client_number--;
    UploadAll(t, global_client_number);
    loading(25);
    return Ok;
} //end of deletebytime

int DeleteBySite(struct tourist t[]) //delete by site
{
    system("cls");
    printf("Scenic : ");
    int i = SearchBySite(t);
    for(;i < global_client_number; i++)
    {
        strcpy(t[i].name, t[i+1].name);
        strcpy(t[i].placename, t[i+1].placename);
        t[i].sex = t[i+1].sex;
        t[i].pernum = t[i+1].pernum;
        strcpy(t[i].phone, t[i+1].phone);
        t[i].time.year = t[i+1].time.year;
        t[i].time.month = t[i+1].time.month;
        t[i].time.day = t[i+1].time.day;
    }
    global_client_number--;
    UploadAll(t, global_client_number);
    loading(25);
    return Ok;
} // end of deletebysite

int Order(struct tourist t[]) //order
{
    system("cls");
    printf("0.Return\n1.Sort by name\n2.Sort by time\n3.Sort by site\n");
    printf("Select one?: ");
    fflush(stdin);
    switch(getchar())
    {
        case '1': OrderByName(t); break;
        case '2': OrderByTime(t); break;
        case '3': OrderBySite(t); break;
        case '0': return Ok;
        default: return Err;
    }
    return Ok;
} //end of order

int OrderByName(struct tourist t[]) //order by name
{
    int i, j;
    for(i=1; i <= global_client_number; i++) //quick sort
    {
        for(j = i+1; j <= global_client_number; j++)
        {
           if(strcmp(t[i].name, t[j].name) > 0) //compare
           {
               strcpy(t[0].name, t[i].name); //exchange (0, i)
               strcpy(t[0].placename, t[i].placename);
               t[0].sex = t[i].sex;
               t[0].pernum = t[i].pernum;
               strcpy(t[0].phone, t[i].phone);
               t[0].time.year = t[i].time.year;
               t[0].time.month = t[i].time.month;
               t[0].time.day = t[i].time.day;
               t[0].dot = t[i].dot;
               
               strcpy(t[i].name, t[j].name); //exchange(i, j)
               strcpy(t[i].placename, t[j].placename);
               t[i].sex = t[j].sex;
               t[i].pernum = t[j].pernum;
               strcpy(t[i].phone, t[j].phone);
               t[i].time.year = t[j].time.year;
               t[i].time.month = t[j].time.month;
               t[i].time.day = t[j].time.day;
               t[i].dot = t[j].dot;
               
               strcpy(t[j].name, t[0].name); //exchange(j, 0)
               strcpy(t[j].placename, t[0].placename);
               t[j].sex = t[0].sex;
               t[j].pernum = t[0].pernum;
               strcpy(t[j].phone, t[0].phone);
               t[j].time.year = t[0].time.year;
               t[j].time.month = t[0].time.month;
               t[j].time.day = t[0].time.day;
               t[j].dot = t[0].dot;
           }
        }
    }
    UploadAll(t, global_client_number);
    loading(25);
    Print(t);
     return Ok;
}

int OrderByTime(struct tourist t[]) //order by time
{
    int i, j;
    for(i=1; i <= global_client_number; i++)
    {
        for(j = i+1; j <= global_client_number; j++)
        {
           if(t[i].time.year > t[j].time.year || t[i].time.year == t[j].time.year && t[i].time.month > t[j].time.month ||
           t[i].time.year == t[j].time.year && t[i].time.month == t[j].time.month && t[i].time.day > t[j].time.day)
           {
               strcpy(t[0].name, t[i].name);
               strcpy(t[0].placename, t[i].placename);
               t[0].sex = t[i].sex;
               t[0].pernum = t[i].pernum;
               strcpy(t[0].phone, t[i].phone);
               t[0].time.year = t[i].time.year;
               t[0].time.month = t[i].time.month;
               t[0].time.day = t[i].time.day;
               t[0].dot = t[i].dot;
               
               strcpy(t[i].name, t[j].name);
               strcpy(t[i].placename, t[j].placename);
               t[i].sex = t[j].sex;
               t[i].pernum = t[j].pernum;
               strcpy(t[i].phone, t[j].phone);
               t[i].time.year = t[j].time.year;
               t[i].time.month = t[j].time.month;
               t[i].time.day = t[j].time.day;
               t[i].dot = t[j].dot;
               
               strcpy(t[j].name, t[0].name);
               strcpy(t[j].placename, t[0].placename);
               t[j].sex = t[0].sex;
               t[j].pernum = t[0].pernum;
               strcpy(t[j].phone, t[0].phone);
               t[j].time.year = t[0].time.year;
               t[j].time.month = t[0].time.month;
               t[j].time.day = t[0].time.day;
               t[j].dot = t[0].dot;
           }
        }
    }
    UploadAll(t, global_client_number);
    loading(25);
    Print(t);
     return Ok;
} //end of sortbytime

int OrderBySite(struct tourist t[]) //order by site
{
    int i, j;
    for(i=1; i <= global_client_number; i++)
    {
        for(j = i+1; j <= global_client_number; j++)
        {
           if(strcmp(t[i].placename, t[j].placename) > 0)
           {
               strcpy(t[0].name, t[i].name);
               strcpy(t[0].placename, t[i].placename);
               t[0].sex = t[i].sex;
               t[0].pernum = t[i].pernum;
               strcpy(t[0].phone, t[i].phone);
               t[0].time.year = t[i].time.year;
               t[0].time.month = t[i].time.month;
               t[0].time.day = t[i].time.day;
               t[0].dot = t[i].dot;
               
               strcpy(t[i].name, t[j].name);
               strcpy(t[i].placename, t[j].placename);
               t[i].sex = t[j].sex;
               t[i].pernum = t[j].pernum;
               strcpy(t[i].phone, t[j].phone);
               t[i].time.year = t[j].time.year;
               t[i].time.month = t[j].time.month;
               t[i].time.day = t[j].time.day;
               t[i].dot = t[j].dot;
               
               strcpy(t[j].name, t[0].name);
               strcpy(t[j].placename, t[0].placename);
               t[j].sex = t[0].sex;
               t[j].pernum = t[0].pernum;
               strcpy(t[j].phone, t[0].phone);
               t[j].time.year = t[0].time.year;
               t[j].time.month = t[0].time.month;
               t[j].time.day = t[0].time.day;
               t[j].dot = t[0].dot;
           }
        }
    }
    UploadAll(t, global_client_number);
    loading(25);
    Print(t);
     return Ok;
} //end of orderbysite
