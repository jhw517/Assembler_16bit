#include<stdio.h>
#include<string.h>
void label();
char *del(char[], char);

void label()
{
	FILE *labelw,*input,*labelr;
	char in[20],label[20],ch1[20],ch2[20]; int i=0,count=0; char *ch;
	labelw=fopen("LabelWrite1.txt","a");
	labelr=fopen("Label.txt","r");
	input=fopen("Input.txt","r");
	fscanf(input,"%s",in);
	while(strcmp(in,"END")!=0)
	{
		fscanf(input,"%s",in);
		if(strchr(in,':')!=NULL)
		{
			count++;
			 strcpy(ch1,in);
			 //puts(ch1);
			 ch=del(ch1,':');
			 strcpy(ch2,ch);
			 printf("%s Symbol Inserted\n",ch);
			 //printf("woa %s",ch);
			//while(i<10)
			{
				for(int j=0;j<count;j++)
				{
				fscanf(labelr,"%s",label);
			    }
				
					fprintf(labelw,"\n%s ",ch2);
					fprintf(labelw," %s ",label);
				
				i++;
			}
		}
		
	}
	fclose(labelw);
	fclose(labelr);
	fclose(input);
}


char *del(char str[], char ch) {
   int i, j = 0;
   int size;
   char ch1;
   char str1[10];
 
   size = strlen(str);
 
   for (i = 0; i < size; i++) {
      if (str[i] != ch) {
         ch1 = str[i];
         str1[j] = ch1;
         j++;
      }
   }
   str1[j] = '\0';
 	return str1;
   //printf("\ncorrected string is : %s", str1);
}


main()
{
	label();
}

