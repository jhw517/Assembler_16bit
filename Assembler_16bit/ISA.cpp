#include<stdio.h>
#include<string.h>
void pass2(char *,int);
int registers(char[]);
char *del(char[], char);
int chklabel(char[], int);
int labelin(char [],int);

int line=1;
FILE *output=fopen("output.txt","a");
void pass1()
{
	char in[20],opc[20],reg[20],ch1[20];
	char *ch;
	char rm;
	int temp=0,count=0,flag=0;
	FILE *opcode,*regis,*input;
	opcode=fopen("Opcode.txt","r");
	regis=fopen("Registers.txt","r");
	input=fopen("Input.txt","r");
	
	fscanf(input,"%s",in);
//	if(strcmp("START",in)==0)
//	{
	while(strcmp("END",in)!=0)
	{
		temp=0;
		fscanf(input,"%s",in);
		if(strchr(in,':')!=NULL)
		{
			 count++;
			 strcpy(ch1,in);
			 ch=del(ch1,':');
			 strcpy(ch1,ch);
			 temp=chklabel(ch1,count);
			 fscanf(input,"%s",in);
		}
		printf(" %s ",in);
		do
		{
			fscanf(opcode,"%s",opc);
			
			
			if(strcmp(in,opc)==0)
			{
				
				fscanf(opcode,"%s",opc);
				printf("Line No. %d %s",line,opc);
				fprintf(output,"%s ",opc);
				temp=1; line++;
				break;
			}
		
		}while(strcmp("--",opc)!=0);
	
		if(strcmp(in,"END")==0)
		{
			break;
		}
	
		if(temp==0)
		{
			temp=registers(in);
			
		}
			
		if(temp==0)
		{
			
			temp=labelin(in,count);
	
		}
		if(temp==0)
		{
			
			printf("Syntax Error! at Line No from START %d", line);
			
			break;
		}
		rewind(opcode);
	}
//	}
//	else
//	 printf("Start your code With 'START'");

}

int labelin(char *in,int count)
{
	FILE *labelc;
	
	int i=0;
	char labc[20];
	labelc=fopen("LabelWrite1.txt","r");
	do 
	{
		fscanf(labelc,"%s",labc);
		if(strcmp(labc,in)==0)
		{
			
			fscanf(labelc,"%s",labc);
			printf("%s",labc);
			fprintf(labelc,"%s ",labc);
			i++;
			fclose(labelc);
			
			return 1;
			
		}	
		else{ 
		i++;
		}	
	}while(i<10);
	
	return 0;
}
int registers(char *in)
{
	FILE *regis;
	char reg[20];
		
	regis=fopen("Registers.txt","r");
	do
	{
		fscanf(regis,"%s",reg);
		
		if(strcmp(reg,in)==0)
		{
			fscanf(regis,"%s",reg);
			printf("%s",reg);
			fprintf(output,"%s ",reg);
			return 1;
			
		}
	}while(strcmp(reg,"--")!=0);
	
	return 0;
}


int chklabel(char *in,int count)
{
	
	FILE *clabel;
	char clab[20];
	int i=0;
	
	clabel=fopen("LabelWrite1.txt","r");
	do
	{
		
		fscanf(clabel,"%s",clab);
		
		
		if(strcmp(clab,in)==0)
		{
		fscanf(clabel,"%s",clab);
	
		printf(" %s",clab);
		fprintf(output,"%s ",clab);
		fclose(clabel);
		return 1;
	    }
	   
	    i++;
	    
	    fscanf(clabel,"%s",clab);
	}while(i!=count+1);
	fclose(clabel);
	return 0;
}

void pass2(char *ch,int count)
{
	FILE *labelw,*label;
	char lab[20],cp[20];
	strcpy(cp,ch);
		
	label=fopen("Label.txt","r");
	labelw=fopen("LabelWrite.txt","a+");
	for(int i=0;i<count;i++)
	{
	fscanf(label,"%s",lab);
	
	}
	
	fprintf(labelw,"\n%s ", cp);
	fprintf(labelw," %s", lab);
		
	fclose(label);
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
   
}

int main()
{
	pass1();
	fclose(output);
	return 0;
}
