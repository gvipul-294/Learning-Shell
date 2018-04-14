#include <stdio.h>
void main()
{
    FILE *fptr;
    char input[100];
    fptr = fopen("fileCode.", "w");
 
   if (fptr == NULL)
    {
        printf("File does not exist \n");
        return;
    }
    printf("Enter input\n");
    scanf("%s", input);
    fprintf(fptr,"%s\n", input);
    fclose(fptr);

    printf("Let’s read from the file\n");
    fptr=fopen("fileCode.", "r");
   
 if(fptr==NULL)
    {
        printf("File does not exist \n");
        return;
    }
    printf("File is going to open\n");
    char ch;
    ch=fgetc(fptr);
    while(ch!=EOF)
    {
	printf("%c",ch);
	ch=fgetc(fptr);
    }
    printf("File is going to close\n");
    fclose(fptr);
}

