void pass2(char *ch,int count)
{
	FILE *labelw,*label;
	char lab[20],cp[20];
	strcpy(cp,ch);
		//printf("kata   %s",ch);
	label=fopen("Label.txt","r");
	labelw=fopen("LabelWrite.txt","a+");
	for(int i=0;i<count;i++)
	{
	fscanf(label,"%s",lab);
	//printf("\n\n%s",lab);
	}
	//printf("\n\n%s",lab);
	//printf("kata   %s",cp);
	fprintf(labelw,"\n%s ", cp);
	fprintf(labelw," %s", lab);
	//printf("\n\n\n%s",cp);	
	fclose(label);
}





//ch=in;
			 strcpy(ch1,in);
			 //puts(ch1);
			 ch=del(ch1,':');
			 strcpy(ch1,ch);
			 //printf("woa %s",ch);
			 count++;
			pass2(ch,count);
			//temp=chklabel(ch1,count);
			fscanf(input,"%s",in);
