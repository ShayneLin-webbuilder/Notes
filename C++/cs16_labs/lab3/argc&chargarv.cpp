#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

int i,sum;

printf("argc = %d\n",argc);
printf("Let's see what is in argv[]\n");
    if(argc>1)
    {
        for(i=1;i<argc;i++)
        {   
            sum += atoi(argv[i]);
            printf("argv[%d] = %s\n",i,argv[i]);
        }
        printf("Total =%d\n",sum);
    }
    return 0;
}