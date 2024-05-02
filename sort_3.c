#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


char buf[512];

struct printer
{
  char adder[32];
};
int strcmpo(const char *X, const char *Y)
{
    while (*X)
    {  
      if(*X>=65 && *X <=90)
       { X=X+32;}
      if(*Y>=65 && *Y <=90)
        {Y=Y+32;}
        
      if(*X != *Y) {
            break;
        }

        X++;
        Y++;
    } 
    return *(const unsigned char*)X - *(const unsigned char*)Y;
}
/************************************************** DEFAULT SORT *****************************************************/

void sort(int fd)
{
  int i, n,l;
  struct printer p[10];
  l=0;
  int x=0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    
    for(i=0; i<n; i++){

      if(buf[i] == '\n')
      {
        char save[128];
        int start=x;
        int end=i;  
        int count=0;
        for(int j=start;j<end;j++)
          {
            save[j-start]=buf[j];
            count++;
          }
        save[count]='\0';
        for(int j=0;j<=count;j++)
          {
            p[l].adder[j]=save[j];
          }
        x=i+1;
        l++;
      }
      }  
  }
  
char temp[50];

    for (int i = 1; i<l; i++)
    {
      strcpy(temp,p[i].adder);
      int j=i-1;
      while(j>=0 && (strcmp(p[j].adder, temp ) > 0))
        {
          
          strcpy(p[j+1].adder,p[j].adder);
          j=j-1;
        }
        strcpy(p[j+1].adder,temp);

    }
    
   for(int j=0;j<l;j++)
    {
      printf(1,"%s\n",p[j].adder);
    }
}

/************************************************ NUMERICAL SORT *****************************************************/

void sort_n(int fd)
{
  int i, n,l;
  struct printer p[10];
  l=0;
  int x=0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    
    for(i=0; i<n; i++){

      if(buf[i] == '\n')
      {
        char save[128];
        int start=x;
        int end=i;  
        int count=0;
        for(int j=start;j<end;j++)
          {
            save[j-start]=buf[j];
            count++;
          }
        save[count]='\0';
        for(int j=0;j<=count;j++)
          {
            p[l].adder[j]=save[j];
          }
        x=i+1;
        l++;
      }
      }  
  }
  
  int arr[10];
  for(int i=0;i<l;i++)
    {
      arr[i]=atoi(p[i].adder);
    }
    
int temp;

    for (int i = 1; i<l; i++)
    {
      temp=arr[i];
      int j=i-1;
      while(j>=0 && (temp<arr[j]))
        {
          arr[j+1]=arr[j];
          j=j-1;
        }
        arr[j+1]=temp;

    }

    
   for(int j=0;j<l;j++)
    {
      printf(1,"%d\n",arr[j]);
    }
}

/************************************************* MONTH SORT ******************************************************/

void sort_M(int fd)
{
  int i, n,l;
  struct printer p[10];
  l=0;
  int x=0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    
    for(i=0; i<n; i++){

      if(buf[i] == '\n')
      {
        char save[128];
        int start=x;
        int end=i;  
        int count=0;
        for(int j=start;j<end;j++)
          {
            save[j-start]=buf[j];
            count++;
          }
        save[count]='\0';
        for(int j=0;j<=count;j++)
          {
            p[l].adder[j]=save[j];
          }
        x=i+1;
        l++;
      }
      }  
  }
  
 int check[24];
  struct printer m[24];
  strcpy(m[0].adder,"january");
  strcpy(m[1].adder,"January");
  strcpy(m[2].adder,"february");
  strcpy(m[3].adder,"February");
  strcpy(m[4].adder,"march");
  strcpy(m[5].adder,"March");
  strcpy(m[6].adder,"april");
  strcpy(m[7].adder,"April");
  strcpy(m[8].adder,"may");
  strcpy(m[9].adder,"May");
  strcpy(m[10].adder,"june");
  strcpy(m[11].adder,"June");
  strcpy(m[12].adder,"july");
  strcpy(m[13].adder,"July");
  strcpy(m[14].adder,"august");
  strcpy(m[15].adder,"August");
  strcpy(m[16].adder,"september");
  strcpy(m[17].adder,"September");
  strcpy(m[18].adder,"october");
  strcpy(m[19].adder,"October");
  strcpy(m[20].adder,"november");
  strcpy(m[21].adder,"November");
  strcpy(m[22].adder,"december");
  strcpy(m[23].adder,"December");
  
  
    for (int i = 0; i<l; i++)
    {
      
      if(strcmp(p[i].adder,"january")==0)
       {
         check[0]=1;
       }
       else if(strcmp(p[i].adder,"January")==0)
       {
         check[1]=1;
       }
        else if(strcmp(p[i].adder,"february")==0)
       {
         check[2]=1;
       }
       else if(strcmp(p[i].adder,"February")==0)
       {
         check[3]=1;
       }
        else if(strcmp(p[i].adder,"march")==0)
       {
         check[4]=1;
       }
       else if(strcmp(p[i].adder,"March")==0)
       {
         check[5]=1;
       }
        else if(strcmp(p[i].adder,"april")==0)
       {
         check[6]=1;
       }
       else if(strcmp(p[i].adder,"April")==0)
       {
         check[7]=1;
       }
        else if(strcmp(p[i].adder,"may")==0)
       {
         check[8]=1;
       }
       else if(strcmp(p[i].adder,"May")==0)
       {
         check[9]=1;
       }
      else if(strcmp(p[i].adder,"june")==0)
       {
         check[10]=1;
       }
        else if(strcmp(p[i].adder,"June")==0)
       {
         check[11]=1;
       }
        else  if(strcmp(p[i].adder,"july")==0)
       {
         check[12]=1;
       }
        else if(strcmp(p[i].adder,"July")==0)
       {
         check[13]=1;
       }
         else if(strcmp(p[i].adder,"august")==0)
       {
         check[14]=1;
       }
        else if(strcmp(p[i].adder,"August")==0)
       {
         check[15]=1;
       }
        else if(strcmp(p[i].adder,"september")==0)
       {
         check[16]=1;
       }
        else if(strcmp(p[i].adder,"September")==0)
       {
         check[17]=1;
       }
         else if(strcmp(p[i].adder,"october")==0)
       {
         check[18]=1;
       }
        else if(strcmp(p[i].adder,"October")==0)
       {
         check[19]=1;
       }
         else if(strcmp(p[i].adder,"november")==0)
       {
         check[20]=1;
       }
        else if(strcmp(p[i].adder,"November")==0)
       {
         check[21]=1;
       }
        else if(strcmp(p[i].adder,"december")==0)
       {
         check[22]=1;
       }
        else if(strcmp(p[i].adder,"December")==0)
       {
         check[23]=1;
       }
      else{
         printf(1,"\nThe input months should be in lower case or sentence case or without any beginning and trailing spaces : %s\n ",p[i].adder);
      }
    }
           
   for(int j=0;j<24;j++)
    {
      if(check[j]==1)
      printf(1,"%s\n",m[j].adder);
    }
}

/************************************************ REVERSE SORT *****************************************************/


void sort_r(int fd)
{
  int i, n,l;
  struct printer p[10];
  l=0;
  int x=0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    
    for(i=0; i<n; i++){

      if(buf[i] == '\n')
      {
        char save[128];
        int start=x;
        int end=i;  
        int count=0;
        for(int j=start;j<end;j++)
          {
            save[j-start]=buf[j];
            count++;
          }
        save[count]='\0';
        for(int j=0;j<=count;j++)
          {
            p[l].adder[j]=save[j];
          }
        x=i+1;
        l++;
      }
      }  
  }
  
char temp[50];

    for (int i = 1; i<l; i++)
    {
      strcpy(temp,p[i].adder);
      int j=i-1;
      while(j>=0 && (strcmp(p[j].adder, temp ) < 0))
        {
          
          strcpy(p[j+1].adder,p[j].adder);
          j=j-1;
        }
        strcpy(p[j+1].adder,temp);

    }
    
   for(int j=0;j<l;j++)
    {
      printf(1,"%s\n",p[j].adder);
    }
}

/*********************************************** UNIQUE SORT *********************************************************/

void sort_u(int fd)
{
  int i, n,l;
  struct printer p[10];
  l=0;
  int x=0; 
  while((n = read(fd, buf, sizeof(buf))) > 0){
    
    for(i=0; i<n; i++){

      if(buf[i] == '\n')
      {
        char save[128];
        int start=x;
        int end=i;  
        int count=0;
        for(int j=start;j<end;j++)
          {
            save[j-start]=buf[j];
            count++;
          }
        save[count]='\0';
        for(int j=0;j<=count;j++)
          {
            p[l].adder[j]=save[j];
          }
        x=i+1;
        l++;
      }
      }  
  }
  
char temp[50];

    for (int i = 1; i<l; i++)
    {
      strcpy(temp,p[i].adder);
      int j=i-1;
      while(j>=0 && (strcmp(p[j].adder, temp ) > 0))
        {
          
          strcpy(p[j+1].adder,p[j].adder);
          j=j-1;
        }
        strcpy(p[j+1].adder,temp);

    }
    
    for(int j=0;j<l;j++)
    {
      if(j<=l-2 && (strcmp(p[j].adder,p[j+1].adder)==0))
        continue;
      printf(1, "%s\n",p[j].adder);
    }
}

/********************************************* BLANK SORT ********************************************************/


void sort_b(int fd)
{
  int i, n,l;
  struct printer p[10];
  l=0;
  int x=0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    
    for(i=0; i<n; i++){

      if(buf[i] == '\n')
      {
        char save[128];
        int start=x;
        int end=i;  
        int count=0;
        for(int j=start;j<end;j++)
          {
            save[j-start]=buf[j];
            count++;
          }
        save[count]='\0';
        for(int j=0;j<=count;j++)
          {
            p[l].adder[j]=save[j];
          }
        x=i+1;
        l++;
      }
      }  
  }
 
  struct printer blank[10];
  for (int i = 0; i<l; i++)
    {
   
    char st[32];
      int k=0;
    for(int j=0;p[i].adder[j]!='\0';j++)
      {
        if(p[i].adder[j]==' ')
          continue;
        st[k++]=p[i].adder[j];
       
      }
      st[k]='\0';
      strcpy(blank[i].adder,st);
      
    }
   
char temp[50];

    for (int i = 1; i<l; i++)
    {
      strcpy(temp,p[i].adder);
      int j=i-1;
      while(j>=0 && (strcmp(blank[j].adder, blank[i].adder ) >= 0))
        {
          
          strcpy(p[j+1].adder,p[j].adder);
          j=j-1;
        }
        strcpy(p[j+1].adder,temp);

    }
     for(int j=0;j<l;j++)
    {
      printf(1,"%s\n",p[j].adder);
    }
   
}

/*********************************************** OUTPUT SORT ********************************************************/

void sort_o(int fd,int dfd)
{
  int i, n,l;
  struct printer p[10];
  l=0;
  int x=0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    
    for(i=0; i<n; i++){

      if(buf[i] == '\n')
      {
        char save[128];
        int start=x;
        int end=i;  
        int count=0;
        for(int j=start;j<end;j++)
          {
            save[j-start]=buf[j];
            count++;
          }
        save[count]='\0';
        for(int j=0;j<=count;j++)
          {
            p[l].adder[j]=save[j];
          }
        x=i+1;
        l++;
      }
      }  
  }
  
char temp[50];

    for (int i = 1; i<l; i++)
    {
      strcpy(temp,p[i].adder);
      int j=i-1;
      while(j>=0 && (strcmp(p[j].adder, temp ) > 0))
        {
          
          strcpy(p[j+1].adder,p[j].adder);
          j=j-1;
        }
        strcpy(p[j+1].adder,temp);

    }
    
   for(int j=0;j<l;j++)
    {
      printf(dfd,"%s\n",p[j].adder);
    }
}



/*************************************************** MAIN PROGRAM ***************************************************/

int
main(int argc, char *argv[])
{
  int startTicks = uptime();
  int fd;
  if(argc <= 1){
    printf(1,"Invalid arguments");
  }
  else if(argc==2)
  {
    if((fd = open(argv[1], 0)) < 0){
      printf(1,"Insertion sort: cannot open %s\n", argv[1]);
    }
    sort(fd);
  } else if(argc==3 && strcmp("-r",argv[1])==0)
  {
    
    if((fd = open(argv[2], 0)) < 0){
      printf(1, "Insertion sort: cannot open %s\n", argv[2]);
      exit();
    }
    sort_r(fd);
    close(fd);
  }else if(argc==3 && strcmp("-n",argv[1])==0)
  {
    
    if((fd = open(argv[2], 0)) < 0){
      printf(1, "Insertion sort: cannot open %s\n", argv[2]);
      exit();
    }
    sort_n(fd);
    close(fd);
  }
  else if(argc==3 && strcmp("-M",argv[1])==0)
  {
    
    if((fd = open(argv[2], 0)) < 0){
      printf(1, "Insertion sort: cannot open %s\n", argv[2]);
      exit();
    }
    sort_M(fd);
    close(fd);
  }
   else if(argc==3 && strcmp("-u",argv[1])==0)
  {
    
    if((fd = open(argv[2], 0)) < 0){
      printf(1, "Insertion sort: cannot open %s\n", argv[2]);
      exit();
    }
    sort_u(fd);
    close(fd);
  }
   else if(argc==3 && strcmp("-b",argv[1])==0)
  {
    
    if((fd = open(argv[2], 0)) < 0){
      printf(1, "Insertion sort: cannot open %s\n", argv[2]);
      exit();
    }
    sort_b(fd);
    close(fd);
  }
   else if(argc==4 && strcmp("-o",argv[1])==0)
  {
   
    if((fd = open(argv[3], 0)) < 0){
      printf(1, "Insertion sort: cannot open %s\n", argv[3]);
      exit();
    }
    int dfd;
    if ((dfd = open(argv[2],O_CREATE|O_WRONLY)) < 0) {
    printf(1, "Insertion sort: cannot open destination %s\n", argv[2]);
    exit();
  } 
    sort_o(fd,dfd);
    close(fd);
  }
  else
  {
    printf(1,"INVALID ARGUMENTS");
  }
 int endTicks = uptime();

   int seconds = (endTicks - startTicks)/100;
   int partial_seconds = (endTicks - startTicks)%100;
   printf(1,"\n\n\n\n***************************************************************\n\n\n");
   printf(1, " Ran in %d.", seconds);
   if (partial_seconds < 10)
   printf(1, "0");
   printf(1, "%d\n", partial_seconds);
    exit();

}
