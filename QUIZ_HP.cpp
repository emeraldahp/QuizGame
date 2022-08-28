#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>


//FileHandeling
struct questionMC
{
	char Question[152];
	char Option1[20];
	char Option2[20];
	char Option3[20];
	char Option4[20];
	int CorrectANS;
	int Q_ID;
	int Unused;
};
struct questionMR
{
	char Question[152];
	char Option1[20];
	char Option2[20];
	char Option3[20];
	char Option4[20];
	int CorrectANS;
	int CorrectANS2;
	int Q_ID;
	int Unused;
};
struct questionYN
{
	char Question[152];
	int CorrectANS;
	int Q_ID;
	int Unused;
};
struct questionNum
{
	char Question[152];
	int CorrectANS;
	int Q_ID;
	int Unused;
};
struct profile
{
	char Name[10];
	int TotalScore;
	int HighScoreMC;
	int HighScoreMR;
	int HighScoreYN;
	int HighScoreNum;
	int P_ID;
};
class FHand
{
	questionMC QMC;
	questionMR QMR;
	questionYN QYN;
	questionNum QNum;
	profile P;

	public:
	int count(char filename[20])
	{       int a=0;
		ifstream fin;
		fin.open(filename,ios::in|ios::binary);
		if(filename[2]=='C')
		while(fin.read((char*) &QMC,sizeof(questionMC)))a++;
		else if(filename[2]=='R')
		while(fin.read((char*) &QMR,sizeof(questionMR)))a++;
		else if(filename[2]=='N')
		while(fin.read((char*) &QYN,sizeof(questionYN)))a++;
		else if(filename[2]=='u')
		while(fin.read((char*) &QNum,sizeof(questionNum)))a++;
		else if(filename[2]=='o')
		while(fin.read((char*) &P,sizeof(profile)))a++;
		fin.close();
		return a;
	}
	void ADDaquestionMC(char Question[152],char Option1[20],char Option2[20],char Option3[20],char Option4[20],int CorrectANS,int Q_ID)
	{
		strcpy(QMC.Question,Question);
		strcpy(QMC.Option1,Option1);
		strcpy(QMC.Option2,Option2);
		strcpy(QMC.Option3,Option3);
		strcpy(QMC.Option4,Option4);
		QMC.CorrectANS=CorrectANS;
		QMC.Q_ID=Q_ID;
		QMC.Unused=1;
		ofstream fout;
		fout.open("qMC_file",ios::out|ios::ate|ios::binary);
		fout.seekp((Q_ID-1)*sizeof(questionMC),ios::beg);
		fout.write((char*) &QMC,sizeof(questionMC));
		fout.close();
	}
	void ADDaquestionMR(char Question[152],char Option1[20],char Option2[20],char Option3[20],char Option4[20],int CorrectANS,int CorrectANS2,int Q_ID)
	{
		strcpy(QMR.Question,Question);
		strcpy(QMR.Option1,Option1);
		strcpy(QMR.Option2,Option2);
		strcpy(QMR.Option3,Option3);
		strcpy(QMR.Option4,Option4);
		QMR.CorrectANS=CorrectANS;
		QMR.CorrectANS2=CorrectANS2;
		QMR.Q_ID=Q_ID;
		QMR.Unused=1;
		ofstream fout;
		fout.open("qMR_file",ios::out|ios::ate|ios::binary);
		fout.seekp((Q_ID-1)*sizeof(questionMR),ios::beg);
		fout.write((char*) &QMR,sizeof(questionMR));
		fout.close();
	}
	void ADDaquestionYN(char Question[152],int CorrectANS,int Q_ID)
	{
		strcpy(QYN.Question,Question);
		QYN.CorrectANS=CorrectANS;
		QYN.Q_ID=Q_ID;
		QYN.Unused=1;
		ofstream fout;
		fout.open("qYN_file",ios::out|ios::ate|ios::binary);
		fout.seekp((Q_ID-1)*sizeof(questionYN),ios::beg);
		fout.write((char*) &QYN,sizeof(questionYN));
		fout.close();
	}
	void ADDaquestionNum(char Question[152],int CorrectANS,int Q_ID)
	{
		strcpy(QNum.Question,Question);
		QNum.CorrectANS=CorrectANS;
		QNum.Q_ID=Q_ID;
		QNum.Unused=1;
		ofstream fout;
		fout.open("qNu_file",ios::out|ios::ate|ios::binary);
		fout.seekp((Q_ID-1)*sizeof(questionNum),ios::beg);
		fout.write((char*) &QNum,sizeof(questionNum));
		fout.close();
	}
	void DELaquestionMC(int a)
	{
		int flag=1;
		ifstream fin;
		ofstream fout;
		fin.open("qMC_file",ios::in|ios::ate|ios::binary);
		fin.seekg(0,ios::beg);
		fout.open("temp",ios::out|ios::binary);
		while(fin.read((char*) &QMC,sizeof(questionMC)))
		{
			if(QMC.Q_ID==a)
			flag=2;
			if(QMC.Q_ID!=a)
			{
				if(flag==2)QMC.Q_ID--;
				fout.write((char*) &QMC,sizeof(questionMC));
			}
		}
		fin.close();
		fout.close();
		fin.open("temp",ios::in|ios::ate|ios::binary);
		fin.seekg(0,ios::beg);
		fout.open("qMC_file",ios::out|ios::binary);
		while(fin.read((char*) &QMC,sizeof(questionMC)))
		{
			fout.write((char*) &QMC,sizeof(questionMC));
		}
		fin.close();
		fout.close();

	}
	void DELaquestionMR(int a)
	{
		int flag=1;
		ifstream fin;
		ofstream fout;
		fin.open("qMR_file",ios::in|ios::ate|ios::binary);
		fin.seekg(0,ios::beg);
		fout.open("temp",ios::out|ios::binary);
		while(fin.read((char*) &QMR,sizeof(questionMR)))
		{
			if(QMR.Q_ID==a)
			flag=2;
			if(QMR.Q_ID!=a)
			{
				if(flag==2)QMR.Q_ID--;
				fout.write((char*) &QMR,sizeof(questionMR));
			}
		}
		fin.close();
		fout.close();
		fin.open("temp",ios::in|ios::ate|ios::binary);
		fin.seekg(0,ios::beg);
		fout.open("qMR_file",ios::out|ios::binary);
		while(fin.read((char*) &QMR,sizeof(questionMR)))
		{
			fout.write((char*) &QMR,sizeof(questionMR));
		}
		fin.close();
		fout.close();

	}
	void DELaquestionYN(int a)
	{
		int flag=1;
		ifstream fin;
		ofstream fout;
		fin.open("qYN_file",ios::in|ios::ate|ios::binary);
		fin.seekg(0,ios::beg);
		fout.open("temp",ios::out|ios::binary);
		while(fin.read((char*) &QYN,sizeof(questionYN)))
		{
			if(QYN.Q_ID==a)
			flag=2;
			if(QYN.Q_ID!=a)
			{
				if(flag==2)QYN.Q_ID--;
				fout.write((char*) &QYN,sizeof(questionYN));
			}
		}
		fin.close();
		fout.close();
		fin.open("temp",ios::in|ios::ate|ios::binary);
		fin.seekg(0,ios::beg);
		fout.open("qYN_file",ios::out|ios::binary);
		while(fin.read((char*) &QYN,sizeof(questionYN)))
		{
			fout.write((char*) &QYN,sizeof(questionYN));
		}
		fin.close();
		fout.close();

	}
	void DELaquestionNum(int a)
	{
		int flag=1;
		ifstream fin;
		ofstream fout;
		fin.open("qNu_file",ios::in|ios::ate|ios::binary);
		fin.seekg(0,ios::beg);
		fout.open("temp",ios::out|ios::binary);
		while(fin.read((char*) &QNum,sizeof(questionNum)))
		{
			if(QNum.Q_ID==a)
			flag=2;
			if(QNum.Q_ID!=a)
			{
				if(flag==2)QNum.Q_ID--;
				fout.write((char*) &QNum,sizeof(questionNum));
			}
		}
		fin.close();
		fout.close();
		fin.open("temp",ios::in|ios::ate|ios::binary);
		fin.seekg(0,ios::beg);
		fout.open("qNu_file",ios::out|ios::binary);
		while(fin.read((char*) &QNum,sizeof(questionNum)))
		{
			fout.write((char*) &QNum,sizeof(questionNum));
		}
		fin.close();
		fout.close();

	}
};
void intextInterface(char text[80])
{
	int i;
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);

	setfillstyle(SOLID_FILL,15);
	bar(0,459,639,479);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	setcolor(CYAN);
	outtextxy(6,463,"Type Text and then press semicolen ';' to finish typing");
	setcolor(WHITE);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(10,100,text);
	line(10,124,500,124);
	line(10,125,500,125);

}
int ADDquestionMC()
{
	FHand file;
	char Question[152];
	char Option1[20];
	char Option2[20];
	char Option3[20];
	char Option4[20];
	int CorrectANS;
	int Q_ID;
	int i,j,a,current=1,tempcurrent=0;
	char question[3][52],ch;
	char cht,tq1[100],tq2[100],tq0[160];
	int flagp[2],d,m=0,g=0;
	int flag[5]={0,0,0,0,0};
	int upx[7]={0,120,125,125,125,125,168};
	int upy[7]={0,123,243,283,323,363,403};
	int downx=630;
	int downy[7]={0,233,273,313,353,393,433};
	for(i=0;i<3;i++)
	{	for(j=0;j<52;j++)
			question[i][j]=' ';
			question[i][51]='\0';
	}
	for(j=0;j<20;j++)
	{
		Option1[j]=' ';
	}
	Option1[19]='\0';
	for(j=0;j<20;j++)
	{
		Option2[j]=' ';
	}
	Option2[19]='\0';
	for(j=0;j<20;j++)
	{
		Option3[j]=' ';
	}
	Option3[19]='\0';
	for(j=0;j<20;j++)
	{
		Option4[j]=' ';
	}
	Option4[19]='\0';

	CorrectANS=0;

	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"ADD MCQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	outtextxy(127,240,Option1);
	outtextxy(127,280,Option2);
	outtextxy(127,320,Option3);
	outtextxy(127,360,Option4);
	switch(CorrectANS)
	{
	case 1:outtextxy(170,400,"1");break;
	case 2:outtextxy(170,400,"2");break;
	case 3:outtextxy(170,400,"3");break;
	case 4:outtextxy(170,400,"4");break;
	default:outtextxy(170,400,"Not Selected");
	}
	outtextxy(30,120,"Question :");
	outtextxy(30,240,"Option#1 :");
	outtextxy(30,280,"Option#2 :");
	outtextxy(30,320,"Option#3 :");
	outtextxy(30,360,"Option#4 :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Enter the Question then the Options and finally the # of the Correct option");
	if(CorrectANS<5&&CorrectANS>0)goto O;
	SELECT:
	setcolor(CYAN);
	rectangle(upx[tempcurrent],upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx[current],upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;
		if(current==1&&flag[1]==1&&flag[2]==1&&flag[3]==1&&flag[4]==1)
		current=0;
		else if(current!=1)
		current-=1;
		if(current==0)current=6;
	}
	else if(ch=='s')
	{
		tempcurrent=current;
		if(current==5&&flag[1]==1&&flag[2]==1&&flag[3]==1&&flag[4]==1)
		current=6;
		else if(current!=5)
		current+=1;
		if(current==7)current=1;
	}
	else if(ch=='m')
	{
		goto OUT;
	}
	else if(ch=='\b')return 0;
	goto SELECT;
	OUT:
	if(current==1)
	{
		flagp[0]=flagp[1]=3;
		intextInterface("Type the Question (max 150 chars)");
		i=m=g=0;
		while(1)
		{
			for(d=620;d<634;d++)
			{
				if(getpixel(d,150)==15)
				flagp[0]=15;
				if(getpixel(d,170)==15)
				flagp[1]=15;
			}
			while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT;
				if(i==151)goto V_OUT;
				if((int)cht>=32&&(int)cht<=126)
				{
					Question[i]=cht;
					Question[i+1]='\0';
					if(flagp[0]!=15)
					{
						tq0[i]=cht;
						tq0[i+1]='\0';
					}
					i+=1;

					if(flagp[0]==15&&flagp[1]!=15)
					{
						tq1[m]=cht;
						tq1[m+1]='\0';
						m++;
					}
					if(flagp[1]==15)
					{
						tq2[g]=cht;
						tq2[g+1]='\0';
						g++;
					}
				}
				outtextxy(10,135,tq0);
				if(flagp[0]==15)
				outtextxy(10,155,tq1);
				if(flagp[1]==15)
				outtextxy(10,175,tq2);
				V_OUT:

			}
			delay(40);

		}
		END_TEXT:
		for(i=0;i<3;i++)
		{	for(j=0;j<52;j++)
				question[i][j]=' ';
				question[i][51]='\0';
		}
		a=0;
		for(i=0;i<3;i++)
		for(j=0;j<51;j++,a++)
		{
			if(Question[a]=='\0')goto o1;
			question[i][j]=Question[a];
		}
		o1:
		goto START;
	}
	else if(current==2)
	{
		for(j=0;j<20;j++)
		{
			Option1[j]=' ';
		}
		Option1[19]='\0';
		intextInterface("Type the Option 1 (max 18 chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT1;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Option1[i]=cht;
					Option1[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Option1);
			}
			delay(40);
		}
		END_TEXT1:
		flag[1]=1;
		goto START;
	}
	else if(current==3)
	{
		for(j=0;j<20;j++)
		{
			Option2[j]=' ';
		}
		Option2[19]='\0';
		intextInterface("Type Option 2 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT2;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Option2[i]=cht;
					Option2[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Option2);
			}
			delay(40);
		}
		END_TEXT2:
		flag[2]=1;
		goto START;
	}
	else if(current==4)
	{
		for(j=0;j<20;j++)
		{
			Option3[j]=' ';
		}
		Option3[19]='\0';
		intextInterface("Type Option 3 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT3;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Option3[i]=cht;
					Option3[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Option3);
			}
			delay(40);
		}
		END_TEXT3:
		flag[3]=1;
		goto START;
	}
	else if(current==5)
	{
		for(j=0;j<20;j++)
		{
			Option4[j]=' ';
		}
		Option4[19]='\0';
		intextInterface("Type Option 4 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT4;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Option4[i]=cht;
					Option4[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Option4);
			}
			delay(40);
		}
		END_TEXT4:
		flag[4]=1;
		goto START;
	}
	else if(current==6)
	{
		CANS:
		intextInterface("Type # of the correct option (0~4)");
		cht=getch();
		CorrectANS=((int)cht)-48;
		if(CorrectANS>4||CorrectANS<1)goto CANS;
		goto START;
	}
	O:
	Q_ID=(file.count("qMC_file")+1);
	file.ADDaquestionMC(Question,Option1,Option2,Option3,Option4,CorrectANS,Q_ID);
	setfillstyle(SOLID_FILL,CYAN);
	bar(4,445,635,475);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Your Question was Added Succcessfilly, Press any Key to return to Main Menu");
	getch();
	return 0;
}
int ADDquestionMR()
{
	FHand file;
	char Question[152];
	char Option1[20];
	char Option2[20];
	char Option3[20];
	char Option4[20];
	int CorrectANS;
	int CorrectANS2;
	int Q_ID;
	int i,j,a,current=1,tempcurrent=0;
	char question[3][52],ch;
	char cht,tq1[100],tq2[100],tq0[160];
	int flagp[2],d,m=0,g=0;
	int flag[5]={0,0,0,0,0};
	int upx[7]={0,120,125,125,125,125,168};
	int upy[7]={0,123,243,283,323,363,403};
	int downx=630;
	int downy[7]={0,233,273,313,353,393,433};
	for(i=0;i<3;i++)
	{	for(j=0;j<52;j++)
			question[i][j]=' ';
			question[i][51]='\0';
	}
	for(j=0;j<20;j++)
	{
		Option1[j]=' ';
	}
	Option1[19]='\0';
	for(j=0;j<20;j++)
	{
		Option2[j]=' ';
	}
	Option2[19]='\0';
	for(j=0;j<20;j++)
	{
		Option3[j]=' ';
	}
	Option3[19]='\0';
	for(j=0;j<20;j++)
	{
		Option4[j]=' ';
	}
	Option4[19]='\0';

	CorrectANS=CorrectANS2=0;

	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"ADD MRQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	outtextxy(127,240,Option1);
	outtextxy(127,280,Option2);
	outtextxy(127,320,Option3);
	outtextxy(127,360,Option4);
	switch(CorrectANS)
	{
	case 1:outtextxy(170,400,"1");break;
	case 2:outtextxy(170,400,"2");break;
	case 3:outtextxy(170,400,"3");break;
	case 4:outtextxy(170,400,"4");break;
	default:outtextxy(170,400,"Not Selected");
	}
	switch(CorrectANS2)
	{
	case 1:outtextxy(185,400,"and 1");break;
	case 2:outtextxy(185,400,"and 2");break;
	case 3:outtextxy(185,400,"and 3");break;
	case 4:outtextxy(185,400,"and 4");break;
	}

	outtextxy(30,120,"Question :");
	outtextxy(30,240,"Option#1 :");
	outtextxy(30,280,"Option#2 :");
	outtextxy(30,320,"Option#3 :");
	outtextxy(30,360,"Option#4 :");
	outtextxy(30,400,"Correct Options:");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Enter the Question then the Options and finally the # of the 2 Correct options");
	if(CorrectANS<5&&CorrectANS>0)goto O;
	SELECT:
	setcolor(CYAN);
	rectangle(upx[tempcurrent],upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx[current],upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;
		if(current==1&&flag[1]==1&&flag[2]==1&&flag[3]==1&&flag[4]==1)
		current=0;
		else if(current!=1)
		current-=1;
		if(current==0)current=6;
	}
	else if(ch=='s')
	{
		tempcurrent=current;
		if(current==5&&flag[1]==1&&flag[2]==1&&flag[3]==1&&flag[4]==1)
		current=6;
		else if(current!=5)
		current+=1;
		if(current==7)current=1;
	}
	else if(ch=='m')
	{
		goto OUT;
	}
	else if(ch=='\b')return 0;
	goto SELECT;
	OUT:
	if(current==1)
	{
		flagp[0]=flagp[1]=3;
		intextInterface("Type the Question (max 150 chars)");
		i=m=g=0;
		while(1)
		{
			for(d=620;d<634;d++)
			{
				if(getpixel(d,150)==15)
				flagp[0]=15;
				if(getpixel(d,170)==15)
				flagp[1]=15;
			}
			while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT;
				if(i==151)goto V_OUT;
				if((int)cht>=32&&(int)cht<=126)
				{
					Question[i]=cht;
					Question[i+1]='\0';
					if(flagp[0]!=15)
					{
						tq0[i]=cht;
						tq0[i+1]='\0';
					}
					i+=1;

					if(flagp[0]==15&&flagp[1]!=15)
					{
						tq1[m]=cht;
						tq1[m+1]='\0';
						m++;
					}
					if(flagp[1]==15)
					{
						tq2[g]=cht;
						tq2[g+1]='\0';
						g++;
					}
				}
				outtextxy(10,135,tq0);
				if(flagp[0]==15)
				outtextxy(10,155,tq1);
				if(flagp[1]==15)
				outtextxy(10,175,tq2);
				V_OUT:

			}
			delay(40);

		}
		END_TEXT:
		for(i=0;i<3;i++)
		{	for(j=0;j<52;j++)
				question[i][j]=' ';
				question[i][51]='\0';
		}
		a=0;
		for(i=0;i<3;i++)
		for(j=0;j<51;j++,a++)
		{
			if(Question[a]=='\0')goto o1;
			question[i][j]=Question[a];
		}
		o1:
		goto START;
	}
	else if(current==2)
	{
		for(j=0;j<20;j++)
		{
			Option1[j]=' ';
		}
		Option1[19]='\0';
		intextInterface("Type the Option 1 (max 18 chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT1;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Option1[i]=cht;
					Option1[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Option1);
			}
			delay(40);
		}
		END_TEXT1:
		flag[1]=1;
		goto START;
	}
	else if(current==3)
	{
		for(j=0;j<20;j++)
		{
			Option2[j]=' ';
		}
		Option2[19]='\0';
		intextInterface("Type Option 2 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT2;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Option2[i]=cht;
					Option2[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Option2);
			}
			delay(40);
		}
		END_TEXT2:
		flag[2]=1;
		goto START;
	}
	else if(current==4)
	{
		for(j=0;j<20;j++)
		{
			Option3[j]=' ';
		}
		Option3[19]='\0';
		intextInterface("Type Option 3 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT3;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Option3[i]=cht;
					Option3[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Option3);
			}
			delay(40);
		}
		END_TEXT3:
		flag[3]=1;
		goto START;
	}
	else if(current==5)
	{
		for(j=0;j<20;j++)
		{
			Option4[j]=' ';
		}
		Option4[19]='\0';
		intextInterface("Type Option 4 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT4;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Option4[i]=cht;
					Option4[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Option4);
			}
			delay(40);
		}
		END_TEXT4:
		flag[4]=1;
		goto START;
	}
	else if(current==6)
	{
		CANS:
		intextInterface("Type # of the correct option no.1 (0~4)");
		cht=getch();
		CorrectANS=((int)cht)-48;
		if(CorrectANS>4||CorrectANS<1)goto CANS;
		CANS2:
		intextInterface("Type # of the correct option no.2 (0~4)");
		cht=getch();
		CorrectANS2=((int)cht)-48;

		if(CorrectANS2>4||CorrectANS2<1)goto CANS2;
		else if(CorrectANS==CorrectANS2)goto CANS2;
		goto START;
	}
	O:
	Q_ID=(file.count("qMR_file")+1);
	file.ADDaquestionMR(Question,Option1,Option2,Option3,Option4,CorrectANS,CorrectANS2,Q_ID);
	setfillstyle(SOLID_FILL,CYAN);
	bar(4,445,635,475);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Your Question was Added Succcessfilly, Press any Key to return to Main Menu");
	getch();
	return 0;
}
int ADDquestionYN()
{
	FHand file;
	char Question[152];
	int CorrectANS;
	int Q_ID;
	int i,j,a,current=1,tempcurrent=0;
	char question[3][52],ch;
	char cht,tq1[100],tq2[100],tq0[160];
	int flagp[2],d,m=0,g=0;
	int upx[7]={0,120,168};
	int upy[7]={0,123,403};
	int downx=630;
	int downy[7]={0,233,433};
	for(i=0;i<3;i++)
	{	for(j=0;j<52;j++)
			question[i][j]=' ';
			question[i][51]='\0';
	}
	CorrectANS=0;

	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"ADD Y/NQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	switch(CorrectANS)
	{
	case 1:outtextxy(170,400,"1(True)");break;
	case 2:outtextxy(170,400,"2(False)");break;
	default:outtextxy(170,400,"Not Selected");
	}
	outtextxy(30,120,"Question :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Enter the Question then Whether its True(1) or False(2)");
	if(CorrectANS==1||CorrectANS==2)goto O;
	SELECT:
	setcolor(CYAN);
	rectangle(upx[tempcurrent],upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx[current],upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;
		if(question[0][0]!=' ')
		current-=1;
		if(current==0)current=2;
	}
	else if(ch=='s')
	{
		tempcurrent=current;
		if(question[0][0]!=' ')
		current+=1;
		if(current==3)current=1;
	}
	else if(ch=='m')
	{
		goto OUT;
	}
	else if(ch=='\b')return 0;
	goto SELECT;
	OUT:
	if(current==1)
	{
		flagp[0]=flagp[1]=3;
		intextInterface("Type the Question (max 150 chars)");
		i=m=g=0;
		while(1)
		{
			for(d=620;d<634;d++)
			{
				if(getpixel(d,150)==15)
				flagp[0]=15;
				if(getpixel(d,170)==15)
				flagp[1]=15;
			}
			while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT;
				if(i==151)goto V_OUT;
				if((int)cht>=32&&(int)cht<=126)
				{
					Question[i]=cht;
					Question[i+1]='\0';
					if(flagp[0]!=15)
					{
						tq0[i]=cht;
						tq0[i+1]='\0';
					}
					i+=1;

					if(flagp[0]==15&&flagp[1]!=15)
					{
						tq1[m]=cht;
						tq1[m+1]='\0';
						m++;
					}
					if(flagp[1]==15)
					{
						tq2[g]=cht;
						tq2[g+1]='\0';
						g++;
					}
				}
				outtextxy(10,135,tq0);
				if(flagp[0]==15)
				outtextxy(10,155,tq1);
				if(flagp[1]==15)
				outtextxy(10,175,tq2);
				V_OUT:

			}
			delay(40);

		}
		END_TEXT:
		for(i=0;i<3;i++)
		{	for(j=0;j<52;j++)
				question[i][j]=' ';
				question[i][51]='\0';
		}
		a=0;
		for(i=0;i<3;i++)
		for(j=0;j<51;j++,a++)
		{
			if(Question[a]=='\0')goto o1;
			question[i][j]=Question[a];
		}
		o1:
		goto START;
	}
	else if(current==2)
	{
		CANS:
		intextInterface("Type 1(True) 2(Fales)");
		cht=getch();
		CorrectANS=((int)cht)-48;
		if(CorrectANS!=1&&CorrectANS!=2)goto CANS;
		goto START;
	}
	O:
	Q_ID=(file.count("qYN_file")+1);
	file.ADDaquestionYN(Question,CorrectANS,Q_ID);
	setfillstyle(SOLID_FILL,CYAN);
	bar(4,445,635,475);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Your Question was Added Succcessfilly, Press any Key to return to Main Menu");
	getch();
	return 0;
}
int ADDquestionNum()
{
	FHand file;
	char Question[152];
	int CorrectANS,flag=0;
	int Q_ID;
	int i,j,a,current=1,tempcurrent=0;
	char question[3][52],ch;
	char cht,tq1[100],tq2[100],tq0[160],tn[5];
	int flagp[2],d,m=0,g=0,tnum;
	int upx[7]={0,120,168};
	int upy[7]={0,123,403};
	int downx=630;
	int downy[7]={0,233,433};
	for(i=0;i<3;i++)
	{	for(j=0;j<52;j++)
			question[i][j]=' ';
			question[i][51]='\0';
	}
	CorrectANS=0;

	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"ADD NAQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	if(flag==1)
	outtextxy(170,400,"(Selected)");
	else
	outtextxy(170,400,"0(Default)(Not Selected)");
	outtextxy(30,120,"Question :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Enter the Question then the Numerical Answer.");
	if(flag==1)goto O;
	SELECT:
	setcolor(CYAN);
	rectangle(upx[tempcurrent],upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx[current],upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;
		if(question[0][0]!=' ')
		current-=1;
		if(current==0)current=2;
	}
	else if(ch=='s')
	{
		tempcurrent=current;
		if(question[0][0]!=' ')
		current+=1;
		if(current==3)current=1;
	}
	else if(ch=='m')
	{
		goto OUT;
	}
	else if(ch=='\b')return 0;
	goto SELECT;
	OUT:
	if(current==1)
	{
		flagp[0]=flagp[1]=3;
		intextInterface("Type the Question (max 150 chars)");
		i=m=g=0;
		while(1)
		{
			for(d=620;d<634;d++)
			{
				if(getpixel(d,150)==15)
				flagp[0]=15;
				if(getpixel(d,170)==15)
				flagp[1]=15;
			}
			while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT;
				if(i==151)goto V_OUT;
				if((int)cht>=32&&(int)cht<=126)
				{
					Question[i]=cht;
					Question[i+1]='\0';
					if(flagp[0]!=15)
					{
						tq0[i]=cht;
						tq0[i+1]='\0';
					}
					i+=1;

					if(flagp[0]==15&&flagp[1]!=15)
					{
						tq1[m]=cht;
						tq1[m+1]='\0';
						m++;
					}
					if(flagp[1]==15)
					{
						tq2[g]=cht;
						tq2[g+1]='\0';
						g++;
					}
				}
				outtextxy(10,135,tq0);
				if(flagp[0]==15)
				outtextxy(10,155,tq1);
				if(flagp[1]==15)
				outtextxy(10,175,tq2);
				V_OUT:

			}
			delay(40);

		}
		END_TEXT:
		for(i=0;i<3;i++)
		{	for(j=0;j<52;j++)
				question[i][j]=' ';
				question[i][51]='\0';
		}
		a=0;
		for(i=0;i<3;i++)
		for(j=0;j<51;j++,a++)
		{
			if(Question[a]=='\0')goto o1;
			question[i][j]=Question[a];
		}
		o1:
		goto START;
	}
	else if(current==2)
	{
		NUMBER:
		intextInterface("Type Number <=100 and with sign");
		i=0;
		setfillstyle(SOLID_FILL,CYAN);
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT1;
				if(i==4)break;
				if(i==0)
				{
					if(cht=='+'||cht=='-')
					{
						tn[i]=cht;
						tn[i+1]='\0';
						i++;
					}
				}
				else if((int)cht>=48&&(int)cht<=57)
				{
					tn[i]=cht;
					tn[i+1]='\0';
					i++;
				}
				bar(10,135,30,155);
				outtextxy(10,135,tn);
			}
			delay(40);
		}
		END_TEXT1:
		setfillstyle(SOLID_FILL,WHITE);
		if(tn[0]=='\0')
		tnum=0;
		else if(tn[1]=='\0')
		tnum=0;
		else if(tn[2]=='\0')
		tnum=(int)tn[1]-48;
		else if(tn[3]=='\0')
		tnum=(((int)tn[1]-48)*10)+((int)tn[2]-48);
		else if(tn[4]=='\0')
		{
		tnum=(((int)tn[1]-48)*100)+(((int)tn[2]-48)*10)+((int)tn[2]-48);
		}
		if(tn[0]=='-')
		CorrectANS=(-1)*(tnum);
		else
		CorrectANS=tnum;
		if(CorrectANS>100)goto NUMBER;
		flag=1;
		goto START;
	}
	O:
	Q_ID=(file.count("qNu_file")+1);
	file.ADDaquestionNum(Question,CorrectANS,Q_ID);
	setfillstyle(SOLID_FILL,CYAN);
	bar(4,445,635,475);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Your Question was Added Succcessfilly, Press any Key to return to Main Menu");
	getch();
	return 0;
}

int MODquestionMC()
{
	FHand file;
	questionMC Q;
	char cht,tq1[100],tq2[100],tq0[160];
	int flagp[2],d,m=0,g=0;
	int Q_ID;
	int totalids=file.count("qMC_file");
	char t[3]={'0','0','\0'};
	intextInterface("Type the question ID (like-01,02,03 i.e. in 2 int)");
	t[0]=getch();
	t[1]=getch();
	if((int)t[1]==';')
	Q_ID=(int)t[0]-48;
	else
	Q_ID=((int)t[1]-48)+(((int)t[0]-48)*10);
	if(Q_ID<=0||Q_ID>totalids)
	{
		if(Q_ID>totalids)
		{
			intextInterface("(Does not Exist) Press any Key to mainMenu");
			getch();
		}
		return 0;
	}
	ifstream fin;
	fin.open("qMC_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionMC),ios::beg);
	fin.read((char*) &Q,sizeof(questionMC));
	fin.close();
	int i,j,a,current=1,tempcurrent=0;
	char question[3][52],ch;
	int flagcs=0;
	int upx[7]={0,120,125,125,125,125,168};
	int upy[7]={0,123,243,283,323,363,403};
	int downx=630;
	int downy[7]={0,233,273,313,353,393,433};
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}
	a=0;
		for(i=0;i<3;i++)
		for(j=0;j<51;j++,a++)
		{
			if(Q.Question[a]=='\0')goto o1;
			question[i][j]=Q.Question[a];
		}
		o1:

	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"MODIFY MCQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	outtextxy(127,240,Q.Option1);
	outtextxy(127,280,Q.Option2);
	outtextxy(127,320,Q.Option3);
	outtextxy(127,360,Q.Option4);
	switch(Q.CorrectANS)
	{
	case 1:outtextxy(170,400,"1");break;
	case 2:outtextxy(170,400,"2");break;
	case 3:outtextxy(170,400,"3");break;
	case 4:outtextxy(170,400,"4");break;
	default:outtextxy(170,400,"Not Selected");
	}
	outtextxy(30,120,"Question :");
	outtextxy(30,240,"Option#1 :");
	outtextxy(30,280,"Option#2 :");
	outtextxy(30,320,"Option#3 :");
	outtextxy(30,360,"Option#4 :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Select any field to Modify and/or correct ans. to finish.");
	if(flagcs==1)goto O;
	SELECT:
	setcolor(CYAN);
	rectangle(upx[tempcurrent],upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx[current],upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;
		current-=1;
		if(current==0)current=6;
	}
	else if(ch=='s')
	{
		tempcurrent=current;
		current+=1;
		if(current==7)current=1;
	}
	else if(ch=='m')
	{
		goto OUT;
	}
	else if(ch=='\b')return 0;
	goto SELECT;
	OUT:
	if(current==1)
	{
		flagp[0]=flagp[1]=3;
		intextInterface("Type the Question (max 150 chars)");
		i=m=g=0;
		while(1)
		{
			for(d=620;d<634;d++)
			{
				if(getpixel(d,150)==15)
				flagp[0]=15;
				if(getpixel(d,170)==15)
				flagp[1]=15;
			}
			while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT;
				if(i==151)goto V_OUT;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Question[i]=cht;
					Q.Question[i+1]='\0';
					if(flagp[0]!=15)
					{
						tq0[i]=cht;
						tq0[i+1]='\0';
					}
					i+=1;

					if(flagp[0]==15&&flagp[1]!=15)
					{
						tq1[m]=cht;
						tq1[m+1]='\0';
						m++;
					}
					if(flagp[1]==15)
					{
						tq2[g]=cht;
						tq2[g+1]='\0';
						g++;
					}
				}
				outtextxy(10,135,tq0);
				if(flagp[0]==15)
				outtextxy(10,155,tq1);
				if(flagp[1]==15)
				outtextxy(10,175,tq2);
				V_OUT:

			}
			delay(40);

		}
		END_TEXT:
		for(i=0;i<3;i++)
		{	for(j=0;j<52;j++)
				question[i][j]=' ';
				question[i][51]='\0';
		}
		a=0;
		for(i=0;i<3;i++)
		for(j=0;j<51;j++,a++)
		{
			if(Q.Question[a]=='\0')goto o2;
			question[i][j]=Q.Question[a];
		}
		o2:
		goto START;
	}
	else if(current==2)
	{
		for(j=0;j<20;j++)
		{
			Q.Option1[j]=' ';
		}
		Q.Option1[19]='\0';
		intextInterface("Type the Option 1 (max 18 chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT1;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Option1[i]=cht;
					Q.Option1[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Q.Option1);
			}
			delay(40);
		}
		END_TEXT1:
		goto START;
	}
	else if(current==3)
	{
		for(j=0;j<20;j++)
		{
			Q.Option2[j]=' ';
		}
		Q.Option2[19]='\0';
		intextInterface("Type Option 2 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT2;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Option2[i]=cht;
					Q.Option2[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Q.Option2);
			}
			delay(40);
		}
		END_TEXT2:
		goto START;
	}
	else if(current==4)
	{
		for(j=0;j<20;j++)
		{
			Q.Option3[j]=' ';
		}
		Q.Option3[19]='\0';
		intextInterface("Type Option 3 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT3;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Option3[i]=cht;
					Q.Option3[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Q.Option3);
			}
			delay(40);
		}
		END_TEXT3:
		goto START;
	}
	else if(current==5)
	{
		for(j=0;j<20;j++)
		{
			Q.Option4[j]=' ';
		}
		Q.Option4[19]='\0';
		intextInterface("Type Option 4 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT4;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Option4[i]=cht;
					Q.Option4[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Q.Option4);
			}
			delay(40);
		}
		END_TEXT4:
		goto START;
	}
	else if(current==6)
	{
		CANS:
		intextInterface("Type # of the correct option (0~4)");
		cht=getch();
		Q.CorrectANS=((int)cht)-48;
		flagcs=1;
		if(Q.CorrectANS>4||Q.CorrectANS<1)goto CANS;
		goto START;
	}
	O:
	file.ADDaquestionMC(Q.Question,Q.Option1,Q.Option2,Q.Option3,Q.Option4,Q.CorrectANS,Q_ID);
	setfillstyle(SOLID_FILL,CYAN);
	bar(4,445,635,475);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Your Question was Modified Succcessfully, Press any Key to return to Main M.");
	getch();
	return 0;
}
int MODquestionMR()
{
	FHand file;
	questionMR Q;
	char cht,tq1[100],tq2[100],tq0[160];
	int flagp[2],d,m=0,g=0;
	int Q_ID;
	int totalids=file.count("qMR_file");
	char t[3]={'0','0','\0'};
	intextInterface("Type the question ID (like-01,02,03 i.e. in 2 int)");
	t[0]=getch();
	t[1]=getch();
	if((int)t[1]==';')
	Q_ID=(int)t[0]-48;
	else
	Q_ID=((int)t[1]-48)+(((int)t[0]-48)*10);
	if(Q_ID<=0||Q_ID>totalids)
	{
		if(Q_ID>totalids)
		{
			intextInterface("(Does not Exist) Press any Key to mainMenu");
			getch();
		}
		return 0;
	}
	ifstream fin;
	fin.open("qMR_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionMR),ios::beg);
	fin.read((char*) &Q,sizeof(questionMR));
	fin.close();
	int i,j,a,current=1,tempcurrent=0;
	char question[3][52],ch;
	int flagcs=0;
	int upx[7]={0,120,125,125,125,125,168};
	int upy[7]={0,123,243,283,323,363,403};
	int downx=630;
	int downy[7]={0,233,273,313,353,393,433};
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}
	a=0;
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:


	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"MODIFY MRQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	outtextxy(127,240,Q.Option1);
	outtextxy(127,280,Q.Option2);
	outtextxy(127,320,Q.Option3);
	outtextxy(127,360,Q.Option4);
	switch(Q.CorrectANS)
	{
	case 1:outtextxy(170,400,"1");break;
	case 2:outtextxy(170,400,"2");break;
	case 3:outtextxy(170,400,"3");break;
	case 4:outtextxy(170,400,"4");break;
	default:outtextxy(170,400,"Not Selected");
	}
	switch(Q.CorrectANS2)
	{
	case 1:outtextxy(185,400,"and 1");break;
	case 2:outtextxy(185,400,"and 2");break;
	case 3:outtextxy(185,400,"and 3");break;
	case 4:outtextxy(185,400,"and 4");break;
	}

	outtextxy(30,120,"Question :");
	outtextxy(30,240,"Option#1 :");
	outtextxy(30,280,"Option#2 :");
	outtextxy(30,320,"Option#3 :");
	outtextxy(30,360,"Option#4 :");
	outtextxy(30,400,"Correct Options:");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Select any field to Modify and/or correct ans. to finish.");
	if(flagcs==1)goto O;
	SELECT:
	setcolor(CYAN);
	rectangle(upx[tempcurrent],upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx[current],upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;
		current-=1;
		if(current==0)current=6;
	}
	else if(ch=='s')
	{
		tempcurrent=current;
		current+=1;
		if(current==7)current=1;
	}
	else if(ch=='m')
	{
		goto OUT;
	}
	else if(ch=='\b')return 0;
	goto SELECT;
	OUT:
	if(current==1)
	{
		flagp[0]=flagp[1]=3;
		intextInterface("Type the Question (max 150 chars)");
		i=m=g=0;
		while(1)
		{
			for(d=620;d<634;d++)
			{
				if(getpixel(d,150)==15)
				flagp[0]=15;
				if(getpixel(d,170)==15)
				flagp[1]=15;
			}
			while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT;
				if(i==151)goto V_OUT;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Question[i]=cht;
					Q.Question[i+1]='\0';
					if(flagp[0]!=15)
					{
						tq0[i]=cht;
						tq0[i+1]='\0';
					}
					i+=1;

					if(flagp[0]==15&&flagp[1]!=15)
					{
						tq1[m]=cht;
						tq1[m+1]='\0';
						m++;
					}
					if(flagp[1]==15)
					{
						tq2[g]=cht;
						tq2[g+1]='\0';
						g++;
					}
				}
				outtextxy(10,135,tq0);
				if(flagp[0]==15)
				outtextxy(10,155,tq1);
				if(flagp[1]==15)
				outtextxy(10,175,tq2);
				V_OUT:

			}
			delay(40);

		}
		END_TEXT:
		for(i=0;i<3;i++)
		{	for(j=0;j<52;j++)
				question[i][j]=' ';
				question[i][51]='\0';
		}
		a=0;
		for(i=0;i<3;i++)
		for(j=0;j<51;j++,a++)
		{
			if(Q.Question[a]=='\0')goto o2;
			question[i][j]=Q.Question[a];
		}
		o2:
		goto START;
	}
	else if(current==2)
	{
		for(j=0;j<20;j++)
		{
			Q.Option1[j]=' ';
		}
		Q.Option1[19]='\0';
		intextInterface("Type the Option 1 (max 18 chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT1;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Option1[i]=cht;
					Q.Option1[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Q.Option1);
			}
			delay(40);
		}
		END_TEXT1:
		goto START;
	}
	else if(current==3)
	{
		for(j=0;j<20;j++)
		{
			Q.Option2[j]=' ';
		}
		Q.Option2[19]='\0';
		intextInterface("Type Option 2 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT2;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Option2[i]=cht;
					Q.Option2[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Q.Option2);
			}
			delay(40);
		}
		END_TEXT2:
		goto START;
	}
	else if(current==4)
	{
		for(j=0;j<20;j++)
		{
			Q.Option3[j]=' ';
		}
		Q.Option3[19]='\0';
		intextInterface("Type Option 3 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT3;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Option3[i]=cht;
					Q.Option3[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Q.Option3);
			}
			delay(40);
		}
		END_TEXT3:
		goto START;
	}
	else if(current==5)
	{
		for(j=0;j<20;j++)
		{
			Q.Option4[j]=' ';
		}
		Q.Option4[19]='\0';
		intextInterface("Type Option 4 (Max 18Chars)");
		i=0;
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT4;
				if(i==19)break;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Option4[i]=cht;
					Q.Option4[i+1]='\0';
					i+=1;
				}
				outtextxy(10,135,Q.Option4);
			}
			delay(40);
		}
		END_TEXT4:
		goto START;
	}
	else if(current==6)
	{
		CANS:
		intextInterface("Type # of the correct option no.1 (0~4)");
		cht=getch();
		Q.CorrectANS=((int)cht)-48;
		if(Q.CorrectANS>4||Q.CorrectANS<1)goto CANS;
		CANS2:
		intextInterface("Type # of the correct option no.2 (0~4)");
		cht=getch();
		Q.CorrectANS2=((int)cht)-48;

		if(Q.CorrectANS2>4||Q.CorrectANS2<1)goto CANS2;
		else if(Q.CorrectANS==Q.CorrectANS2)goto CANS2;
		flagcs=1;
		goto START;
	}
	O:
	file.ADDaquestionMR(Q.Question,Q.Option1,Q.Option2,Q.Option3,Q.Option4,Q.CorrectANS,Q.CorrectANS2,Q_ID);
	setfillstyle(SOLID_FILL,CYAN);
	bar(4,445,635,475);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Your Question was Modified Succcessfilly, Press any Key to return to Main M.");
	getch();
	return 0;
}
int MODquestionYN()
{
	FHand file;
	questionYN Q;
	char cht,tq1[100],tq2[100],tq0[160];
	int flagp[2],d,m=0,g=0;
	int Q_ID;
	int totalids=file.count("qYN_file");
	char t[3]={'0','0','\0'};
	intextInterface("Type the question ID (like-01,02,03 i.e. in 2 int)");
	t[0]=getch();
	t[1]=getch();
	if((int)t[1]==';')
	Q_ID=(int)t[0]-48;
	else
	Q_ID=((int)t[1]-48)+(((int)t[0]-48)*10);
	if(Q_ID<=0||Q_ID>totalids)
	{
		if(Q_ID>totalids)
		{
			intextInterface("(Does not Exist) Press any Key to mainMenu");
			getch();
		}
		return 0;
	}
	ifstream fin;
	fin.open("qYN_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionYN),ios::beg);
	fin.read((char*) &Q,sizeof(questionYN));
	fin.close();
	int i,j,a,current=1,tempcurrent=0;
	char question[3][52],ch;
	int flagcs=0;
	int upx[7]={0,120,168};
	int upy[7]={0,123,403};
	int downx=630;
	int downy[7]={0,233,433};
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}
	a=0;
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:

	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"MODIFY Y/NQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	switch(Q.CorrectANS)
	{
	case 1:outtextxy(170,400,"1(True)");break;
	case 2:outtextxy(170,400,"2(False)");break;
	default:outtextxy(170,400,"Not Selected");
	}
	outtextxy(30,120,"Question :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Modify the Question then Whether its True(1) or False(2)");
	if(flagcs==1)goto O;
	SELECT:
	setcolor(CYAN);
	rectangle(upx[tempcurrent],upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx[current],upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;
		current-=1;
		if(current==0)current=2;
	}
	else if(ch=='s')
	{
		tempcurrent=current;
		current+=1;
		if(current==3)current=1;
	}
	else if(ch=='m')
	{
		goto OUT;
	}
	else if(ch=='\b')return 0;
	goto SELECT;
	OUT:
	if(current==1)
	{
		flagp[0]=flagp[1]=3;
		intextInterface("Type the Question (max 150 chars)");
		i=m=g=0;
		while(1)
		{
			for(d=620;d<634;d++)
			{
				if(getpixel(d,150)==15)
				flagp[0]=15;
				if(getpixel(d,170)==15)
				flagp[1]=15;
			}
			while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT;
				if(i==151)goto V_OUT;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Question[i]=cht;
					Q.Question[i+1]='\0';
					if(flagp[0]!=15)
					{
						tq0[i]=cht;
						tq0[i+1]='\0';
					}
					i+=1;

					if(flagp[0]==15&&flagp[1]!=15)
					{
						tq1[m]=cht;
						tq1[m+1]='\0';
						m++;
					}
					if(flagp[1]==15)
					{
						tq2[g]=cht;
						tq2[g+1]='\0';
						g++;
					}
				}
				outtextxy(10,135,tq0);
				if(flagp[0]==15)
				outtextxy(10,155,tq1);
				if(flagp[1]==15)
				outtextxy(10,175,tq2);
				V_OUT:

			}
			delay(40);

		}
		END_TEXT:
		for(i=0;i<3;i++)
		{	for(j=0;j<52;j++)
				question[i][j]=' ';
				question[i][51]='\0';
		}
		a=0;
		for(i=0;i<3;i++)
		for(j=0;j<51;j++,a++)
		{
			if(Q.Question[a]=='\0')goto o2;
			question[i][j]=Q.Question[a];
		}
		o2:
		goto START;
	}
	else if(current==2)
	{
		CANS:
		intextInterface("Type 1(True) 2(False)");
		cht=getch();
		Q.CorrectANS=((int)cht)-48;
		if(Q.CorrectANS!=1&&Q.CorrectANS!=2)goto CANS;
		flagcs=1;
		goto START;
	}
	O:
	file.ADDaquestionYN(Q.Question,Q.CorrectANS,Q_ID);
	setfillstyle(SOLID_FILL,CYAN);
	bar(4,445,635,475);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Your Question was Modified Succcessfilly, Press any Key to return to Main M.");
	getch();
	return 0;
}
int MODquestionNum()
{
	FHand file;
	questionNum Q;
	char cht,tq1[100],tq2[100],tq0[160],tn[5];
	int flagp[2],d,m=0,g=0,tnum;
	int Q_ID;
	int totalids=file.count("qNu_file");
	char t[3]={'0','0','\0'};
	intextInterface("Type the question ID (like-01,02,03 i.e. in 2 int)");
	t[0]=getch();
	t[1]=getch();
	if((int)t[1]==';')
	Q_ID=(int)t[0]-48;
	else
	Q_ID=((int)t[1]-48)+(((int)t[0]-48)*10);
	if(Q_ID<=0||Q_ID>totalids)
	{
		if(Q_ID>totalids)
		{
			intextInterface("(Does not Exist) Press any Key to mainMenu");
			getch();
		}
		return 0;
	}
	ifstream fin;
	fin.open("qNu_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionNum),ios::beg);
	fin.read((char*) &Q,sizeof(questionNum));
	fin.close();
	int i,j,a,current=1,tempcurrent=0;
	char question[3][52],ch;
	int flagcs=0;
	int upx[7]={0,120,168};
	int upy[7]={0,123,403};
	int downx=630;
	int downy[7]={0,233,433};
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}
	a=0;
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:


	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"MODIFY NAQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	outtextxy(170,400,"(Selected)");

	outtextxy(30,120,"Question :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Modify the Question then the Numerical Answer.");
	if(flagcs==1)goto O;
	SELECT:
	setcolor(CYAN);
	rectangle(upx[tempcurrent],upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx[current],upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;

		current-=1;
		if(current==0)current=2;
	}
	else if(ch=='s')
	{
		tempcurrent=current;

		current+=1;
		if(current==3)current=1;
	}
	else if(ch=='m')
	{
		goto OUT;
	}
	else if(ch=='\b')return 0;
	goto SELECT;
	OUT:
	if(current==1)
	{
		flagp[0]=flagp[1]=3;
		intextInterface("Type the Question (max 150 chars)");
		i=m=g=0;
		while(1)
		{
			for(d=620;d<634;d++)
			{
				if(getpixel(d,150)==15)
				flagp[0]=15;
				if(getpixel(d,170)==15)
				flagp[1]=15;
			}
			while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT;
				if(i==151)goto V_OUT;
				if((int)cht>=32&&(int)cht<=126)
				{
					Q.Question[i]=cht;
					Q.Question[i+1]='\0';
					if(flagp[0]!=15)
					{
						tq0[i]=cht;
						tq0[i+1]='\0';
					}
					i+=1;

					if(flagp[0]==15&&flagp[1]!=15)
					{
						tq1[m]=cht;
						tq1[m+1]='\0';
						m++;
					}
					if(flagp[1]==15)
					{
						tq2[g]=cht;
						tq2[g+1]='\0';
						g++;
					}
				}
				outtextxy(10,135,tq0);
				if(flagp[0]==15)
				outtextxy(10,155,tq1);
				if(flagp[1]==15)
				outtextxy(10,175,tq2);
				V_OUT:

			}
			delay(40);

		}
		END_TEXT:
		for(i=0;i<3;i++)
		{	for(j=0;j<52;j++)
				question[i][j]=' ';
				question[i][51]='\0';
		}
		a=0;
		for(i=0;i<3;i++)
		for(j=0;j<51;j++,a++)
		{
			if(Q.Question[a]=='\0')goto o2;
			question[i][j]=Q.Question[a];
		}
		o2:
		goto START;
	}
	else if(current==2)
	{
		NUMBER:
		intextInterface("Type Number <=100 and with sign");
		i=0;
		setfillstyle(SOLID_FILL,CYAN);
		while(1)
		{       while(kbhit())
			{
				cht=getch();
				if(cht==';')goto END_TEXT1;
				if(i==4)break;
				if(i==0)
				{
					if(cht=='+'||cht=='-')
					{
						tn[i]=cht;
						tn[i+1]='\0';
						i++;
					}
				}
				else if((int)cht>=48&&(int)cht<=57)
				{
					tn[i]=cht;
					tn[i+1]='\0';
					i++;
				}
				bar(10,135,30,155);
				outtextxy(10,135,tn);
			}
			delay(40);
		}
		END_TEXT1:
		setfillstyle(SOLID_FILL,WHITE);
		if(tn[0]=='\0')
		tnum=0;
		else if(tn[1]=='\0')
		tnum=0;
		else if(tn[2]=='\0')
		tnum=(int)tn[1]-48;
		else if(tn[3]=='\0')
		tnum=(((int)tn[1]-48)*10)+((int)tn[2]-48);
		else if(tn[4]=='\0')
		{
		tnum=(((int)tn[1]-48)*100)+(((int)tn[2]-48)*10)+((int)tn[2]-48);
		}
		if(tn[0]=='-')
		Q.CorrectANS=(-1)*(tnum);
		else
		Q.CorrectANS=tnum;
		if(Q.CorrectANS>100)goto NUMBER;
		flagcs=1;
		goto START;
	}
	O:
	file.ADDaquestionNum(Q.Question,Q.CorrectANS,Q_ID);
	setfillstyle(SOLID_FILL,CYAN);
	bar(4,445,635,475);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Your Question was Modified Succcessfilly, Press any Key to return to Main M.");
	getch();
	return 0;
}
int SHOWquestionMC()
{
	FHand file;
	questionMC Q;
	int i,j,a,Q_ID;
	char question[3][52],ch;
	ifstream fin;
	int totalids=file.count("qMC_file");
	for(Q_ID=1;Q_ID<=totalids;Q_ID++)
	{
	fin.open("qMC_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionMC),ios::beg);
	fin.read((char*) &Q,sizeof(questionMC));
	fin.close();
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}
	a=0;
		for(i=0;i<3;i++)
		for(j=0;j<51;j++,a++)
		{
			if(Q.Question[a]=='\0')goto o1;
			question[i][j]=Q.Question[a];
		}
		o1:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"VIEW MCQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	outtextxy(127,240,Q.Option1);
	outtextxy(127,280,Q.Option2);
	outtextxy(127,320,Q.Option3);
	outtextxy(127,360,Q.Option4);
	switch(Q.CorrectANS)
	{
	case 1:outtextxy(170,400,"1");break;
	case 2:outtextxy(170,400,"2");break;
	case 3:outtextxy(170,400,"3");break;
	case 4:outtextxy(170,400,"4");break;
	default:outtextxy(170,400,"Not Selected");
	}
	outtextxy(30,120,"Question :");
	outtextxy(30,240,"Option#1 :");
	outtextxy(30,280,"Option#2 :");
	outtextxy(30,320,"Option#3 :");
	outtextxy(30,360,"Option#4 :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	if(Q_ID==totalids)
	outtextxy(30,444,"This is last Question.Press any Key to >MainMenu");
	else
	outtextxy(30,444,"Press any Key to view next Question.");
	ch=getch();
	if(ch=='\b')return 0;
	}
	return 0;
}
int SHOWquestionMR()
{
	FHand file;
	questionMR Q;
	int i,j,a,Q_ID;
	char question[3][52],ch;
	ifstream fin;
	int totalids=file.count("qMR_file");
	for(Q_ID=1;Q_ID<=totalids;Q_ID++)
	{
	fin.open("qMR_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionMR),ios::beg);
	fin.read((char*) &Q,sizeof(questionMR));
	fin.close();
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}
	a=0;
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:


	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"VIEW MRQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	outtextxy(127,240,Q.Option1);
	outtextxy(127,280,Q.Option2);
	outtextxy(127,320,Q.Option3);
	outtextxy(127,360,Q.Option4);
	switch(Q.CorrectANS)
	{
	case 1:outtextxy(170,400,"1");break;
	case 2:outtextxy(170,400,"2");break;
	case 3:outtextxy(170,400,"3");break;
	case 4:outtextxy(170,400,"4");break;
	default:outtextxy(170,400,"Not Selected");
	}
	switch(Q.CorrectANS2)
	{
	case 1:outtextxy(185,400,"and 1");break;
	case 2:outtextxy(185,400,"and 2");break;
	case 3:outtextxy(185,400,"and 3");break;
	case 4:outtextxy(185,400,"and 4");break;
	}

	outtextxy(30,120,"Question :");
	outtextxy(30,240,"Option#1 :");
	outtextxy(30,280,"Option#2 :");
	outtextxy(30,320,"Option#3 :");
	outtextxy(30,360,"Option#4 :");
	outtextxy(30,400,"Correct Options:");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	if(Q_ID==totalids)
	outtextxy(30,444,"This is last Question.Press any Key to >MainMenu");
	else
	outtextxy(30,444,"Press any Key to view next Question.");
	ch=getch();
	if(ch=='\b')return 0;
	}
	return 0;
}
int SHOWquestionYN()
{
	FHand file;
	questionYN Q;
	int i,j,a,Q_ID;
	char question[3][52],ch;
	ifstream fin;
	int totalids=file.count("qYN_file");
	for(Q_ID=1;Q_ID<=totalids;Q_ID++)
	{
	fin.open("qYN_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionYN),ios::beg);
	fin.read((char*) &Q,sizeof(questionYN));
	fin.close();
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}
	a=0;
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:

	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"VIEW Y/NQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	switch(Q.CorrectANS)
	{
	case 1:outtextxy(170,400,"1(True)");break;
	case 2:outtextxy(170,400,"2(False)");break;
	default:outtextxy(170,400,"Not Selected");
	}
	outtextxy(30,120,"Question :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	if(Q_ID==totalids)
	outtextxy(30,444,"This is last Question.Press any Key to >MainMenu");
	else
	outtextxy(30,444,"Press any Key to view next Question.");
	ch=getch();
	if(ch=='\b')return 0;
	}
	return 0;
}
int SHOWquestionNum()
{
	FHand file;
	questionNum Q;
	int i,j,a,Q_ID;
	int current;
	char question[3][52],ch,num[4]={'0','0','0','\0'};
	ifstream fin;
	int totalids=file.count("qNu_file");
	for(Q_ID=1;Q_ID<=totalids;Q_ID++)
	{
	fin.open("qNu_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionNum),ios::beg);
	fin.read((char*) &Q,sizeof(questionNum));
	fin.close();
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}
	a=0;
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:


	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"VIEW NAQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);

	if(Q.CorrectANS==0)current=Q.CorrectANS;
	if(Q.CorrectANS>0)
	{
		outtextxy(170,400,"+");
		current=Q.CorrectANS;
	}
	else if(Q.CorrectANS<0)
	{
		outtextxy(170,400,"-");
		current=Q.CorrectANS*(-1);
	}
	if(current<10)
	{
		num[0]='0';
		num[1]='0';
		num[2]=(char)(48+current);
	}
	else if(current<100)
	{
		num[0]='0';
		num[1]=(char)(48+(current/10));
		num[2]=(char)(48+(current%10));
	}
	else if(current==100)
	{
		num[0]='1';
		num[1]='0';
		num[2]='0';
	}
	outtextxy(189,400,num);

	outtextxy(30,120,"Question :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	if(Q_ID==totalids)
	outtextxy(30,444,"This is last Question.Press any Key to >MainMenu");
	else
	outtextxy(30,444,"Press any Key to view next Question.");
	ch=getch();
	if(ch=='\b')return 0;
	}
	return 0;
}
int DELquestionMC()
{
	FHand file;
	questionMC Q;
	int i,j,a,Q_ID;
	char question[3][52],ch;
	ifstream fin;
	int totalids=file.count("qMC_file");
	for(Q_ID=1;Q_ID<=totalids;Q_ID++)
	{
	fin.open("qMC_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionMC),ios::beg);
	fin.read((char*) &Q,sizeof(questionMC));
	fin.close();
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}
	a=0;
		for(i=0;i<3;i++)
		for(j=0;j<51;j++,a++)
		{
			if(Q.Question[a]=='\0')goto o1;
			question[i][j]=Q.Question[a];
		}
		o1:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"VIEW MCQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	outtextxy(127,240,Q.Option1);
	outtextxy(127,280,Q.Option2);
	outtextxy(127,320,Q.Option3);
	outtextxy(127,360,Q.Option4);
	switch(Q.CorrectANS)
	{
	case 1:outtextxy(170,400,"1");break;
	case 2:outtextxy(170,400,"2");break;
	case 3:outtextxy(170,400,"3");break;
	case 4:outtextxy(170,400,"4");break;
	default:outtextxy(170,400,"Not Selected");
	}
	outtextxy(30,120,"Question :");
	outtextxy(30,240,"Option#1 :");
	outtextxy(30,280,"Option#2 :");
	outtextxy(30,320,"Option#3 :");
	outtextxy(30,360,"Option#4 :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	if(Q_ID==totalids)
	outtextxy(30,444,"Press D to delete this ; This is last Question.Press any Key to >MainM.");
	else
	outtextxy(30,444,"Press D to delete this ; Anyother Key to continue Viewing.");
	ch=getch();
	if(ch=='d')
	goto END;
	else if(ch=='\b')return 0;
	}
	END:
	file.DELaquestionMC(Q_ID);
	return 0;
}
int DELquestionMR()
{
	FHand file;
	questionMR Q;
	int i,j,a,Q_ID;
	char question[3][52],ch;
	ifstream fin;
	int totalids=file.count("qMR_file");
	for(Q_ID=1;Q_ID<=totalids;Q_ID++)
	{
	fin.open("qMR_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionMR),ios::beg);
	fin.read((char*) &Q,sizeof(questionMR));
	fin.close();
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}
	a=0;
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:


	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"VIEW MRQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	outtextxy(127,240,Q.Option1);
	outtextxy(127,280,Q.Option2);
	outtextxy(127,320,Q.Option3);
	outtextxy(127,360,Q.Option4);
	switch(Q.CorrectANS)
	{
	case 1:outtextxy(170,400,"1");break;
	case 2:outtextxy(170,400,"2");break;
	case 3:outtextxy(170,400,"3");break;
	case 4:outtextxy(170,400,"4");break;
	default:outtextxy(170,400,"Not Selected");
	}
	switch(Q.CorrectANS2)
	{
	case 1:outtextxy(185,400,"and 1");break;
	case 2:outtextxy(185,400,"and 2");break;
	case 3:outtextxy(185,400,"and 3");break;
	case 4:outtextxy(185,400,"and 4");break;
	}

	outtextxy(30,120,"Question :");
	outtextxy(30,240,"Option#1 :");
	outtextxy(30,280,"Option#2 :");
	outtextxy(30,320,"Option#3 :");
	outtextxy(30,360,"Option#4 :");
	outtextxy(30,400,"Correct Options:");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);

	if(Q_ID==totalids)
	outtextxy(30,444,"Press D to delete this ; This is last Question.Press any Key to >MainM.");
	else
	outtextxy(30,444,"Press D to delete this ; Anyother Key to continue Viewing.");
	ch=getch();
	if(ch=='d')
	goto END;
	else if(ch=='\b')return 0;
	}
	END:
	file.DELaquestionMR(Q_ID);
	return 0;
}
int DELquestionYN()
{
	FHand file;
	questionYN Q;
	int i,j,a,Q_ID;
	char question[3][52],ch;
	ifstream fin;
	int totalids=file.count("qYN_file");
	for(Q_ID=1;Q_ID<=totalids;Q_ID++)
	{
	fin.open("qYN_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionYN),ios::beg);
	fin.read((char*) &Q,sizeof(questionYN));
	fin.close();
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}


	a=0;
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:

	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"VIEW Y/NQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	switch(Q.CorrectANS)
	{
	case 1:outtextxy(170,400,"1(True)");break;
	case 2:outtextxy(170,400,"2(False)");break;
	default:outtextxy(170,400,"Not Selected");
	}
	outtextxy(30,120,"Question :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);

	if(Q_ID==totalids)
	outtextxy(30,444,"Press D to delete this ; This is last Question.Press any Key to >MainM.");
	else
	outtextxy(30,444,"Press D to delete this ; Anyother Key to continue Viewing.");
	ch=getch();
	if(ch=='d')
	goto END;
	else if(ch=='\b')return 0;
	}
	END:
	file.DELaquestionYN(Q_ID);
	return 0;
}
int DELquestionNum()
{
	FHand file;
	questionNum Q;
	int i,j,a,Q_ID;
	char question[3][52],ch;
	ifstream fin;
	int totalids=file.count("qNu_file");
	for(Q_ID=1;Q_ID<=totalids;Q_ID++)
	{
	fin.open("qNu_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionNum),ios::beg);
	fin.read((char*) &Q,sizeof(questionNum));
	fin.close();
	for(i=0;i<3;i++)                                      //resetting question
	{
		for(j=0;j<52;j++)
			question[i][j]=' ';
		question[i][51]='\0';
	}


	a=0;
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:


	START:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"VIEW NAQ");
	bar(0,100,639,104);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(122,120,question[0]);
	outtextxy(122,160,question[1]);
	outtextxy(122,200,question[2]);
	outtextxy(170,400,"(Selected)");

	outtextxy(30,120,"Question :");
	outtextxy(30,400,"Correct Option :");
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);

	if(Q_ID==totalids)
	outtextxy(30,444,"Press D to delete this ; This is last Question.Press any Key to >MainM.");
	else
	outtextxy(30,444,"Press D to delete this ; Anyother Key to continue Viewing.");
	ch=getch();
	if(ch=='d')
	goto END;
	else if(ch=='\b')return 0;
	}
	END:
	file.DELaquestionNum(Q_ID);
	return 0;
}
//endFileHandeling
int PLAYquizMC(int profileID)
{
	randomize();

	FHand file;
	questionMC Q;
	ifstream fin;
	ofstream fout;
	profile P;

	int Q_ID;
	int i,j,a,m;
	int totalcorrect=0;
	int lifel=0,lifel_tempsel=0;
	int current=1,tempcurrent=0;
	int upx[7]={0,61,331,61,331,196};
	int upy[7]={0,186,186,246,246,311};
	int downx[7]={0,309,579,309,579,444};
	int downy[7]={0,234,234,294,294,359};
	int flag[11]={0,0,0,0,0,0,0,0,0,0,0};
	int flagl=0;
	int totalids=file.count("qMC_file");

	char question[3][52],ch;

	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	if(totalids<10)
	{
		settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
		settextjustify(CENTER_TEXT,TOP_TEXT);
		outtextxy(320,100,"THERE SHOULD BE MORE THEN 10 QUESTION");
		outtextxy(320,150,"U CAN ADD QUESTIONS USING OPTIONS FUNCTION IN MAIN MAENU");
		settextjustify(LEFT_TEXT,TOP_TEXT);
		getch();
		return 0;
	}
	bar(0,0,639,30);                                      //timerBAR
	setcolor(3);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(4,0,"TIMER");
	setcolor(WHITE);
	for(i=0;i<3;i++)
	{
		rectangle(65-i,50-i,575+i,160+i);             //Question
		rectangle(65-i,190-i,305+i,230+i);            //Options
		rectangle(335-i,190-i,575+i,230+i);
		rectangle(65-i,250-i,305+i,290+i);
		rectangle(335-i,250-i,575+i,290+i);
		rectangle(200-i,315-i,440+i,355+i);           //Life
	}
	setcolor(CYAN);
	rectangle(50,4,635,26);
	setfillstyle(SOLID_FILL,15);
	bar(0,459,639,479);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	setcolor(CYAN);
	outtextxy(6,463,"Press W/S/A/D to move Up/Down/Left/Right. Press M to select. Press L for lifeline");

//MEGA LOOP
	for(m=1;m<11;m++)
	{
	getID:
	Q_ID=random(totalids)+1;						       //make loop overloop random q id between total id
	fin.open("qMC_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionMC),ios::beg);
	fin.read((char*) &Q,sizeof(questionMC));
	fin.close();
	if(Q.Unused==0)goto getID;


	for(i=0;i<3;i++)                                      //resetting question
	{	for(j=0;j<52;j++)
			question[i][j]=' ';
			question[i][51]='\0';
	}

	a=0;                                                  //filling question
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:

	setfillstyle(SOLID_FILL,CYAN);
	bar(66,51,574,159);             //Question
	bar(66,191,304,229);            //Options
	bar(336,191,574,229);
	bar(66,251,304,289);
	bar(336,251,574,289);


	setcolor(WHITE);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(100,50,question[0]);
	outtextxy(100,90,question[1]);
	outtextxy(100,130,question[2]);
	outtextxy(73,193,Q.Option1);
	outtextxy(341,193,Q.Option2);
	outtextxy(73,253,Q.Option3);
	outtextxy(341,253,Q.Option4);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(320,318,"LIFELINE 50/ 50");
	settextjustify(LEFT_TEXT,TOP_TEXT);

	//resetting things
	setfillstyle(SOLID_FILL,WHITE);
	bar(51,5,634,25);
	setfillstyle(SOLID_FILL,CYAN);
	current=1;
	rectangle(upx[current],upy[current],downx[current],downy[current]);
	lifel=0;
	SELECT:
	for(i=0;i<584;i++)
	{
		bar(634-i,5,634,25);
		setcolor(WHITE);
		if(lifel==1)
		{
			setcolor(WHITE);
			rectangle(upx[lifel_tempsel],upy[lifel_tempsel],downx[lifel_tempsel],downy[lifel_tempsel]);
		}
		if(lifel==1)
		{
			if(lifel_tempsel!=tempcurrent)
			{
				setcolor(CYAN);
				rectangle(upx[tempcurrent],upy[tempcurrent],downx[tempcurrent],downy[tempcurrent]);
			}
		}
		else
		{
			setcolor(CYAN);
			rectangle(upx[tempcurrent],upy[tempcurrent],downx[tempcurrent],downy[tempcurrent]);
		}
		setcolor(WHITE);
		rectangle(upx[current],upy[current],downx[current],downy[current]);
		while(kbhit())
		{

			ch=getch();
			if(ch=='w')
			{
				if(current>2)
				{
					tempcurrent=current;
					current-=2;
				}
			}
			else if(ch=='s')
			{
				if(current<3)
				{
					tempcurrent=current;
					current+=2;
				}
			}
			else if(ch=='a')
			{
					tempcurrent=current;
					current-=1;
					if(current==0)current=4;
			}
			else if(ch=='d')
			{
					tempcurrent=current;
					current+=1;
					if(current==5)current=1;
			}
			else if(ch=='l')
			{
				if(flagl==0)
				{
					lifel=1;
					rectangle(upx[5],upy[5],downx[5],downy[5]);
					flagl=1;
				}


			}
			else if(ch=='m')
			{
				if(lifel==1&&lifel_tempsel==0)
				lifel_tempsel=current;
				if(lifel==1&&current==lifel_tempsel)continue;
				goto NXT_QUE;

			}
			else if(ch=='\b')goto OUT;
		}
		delay(60);

	}
	NXT_QUE:

	fout.open("qMC_file",ios::out|ios::ate|ios::binary);
	fout.seekp((Q_ID-1)*sizeof(questionMC),ios::beg);
	Q.Unused=0;
	fout.write((char*) &Q,sizeof(questionMC));
	fout.close();

	setcolor(CYAN);
	rectangle(upx[lifel_tempsel],upy[lifel_tempsel],downx[lifel_tempsel],downy[lifel_tempsel]);
	rectangle(upx[5],upy[5],downx[5],downy[5]);
	rectangle(upx[current],upy[current],downx[current],downy[current]);
	if(lifel==1)
	{
		if(current==Q.CorrectANS||lifel_tempsel==Q.CorrectANS)flag[m]=1;
		else flag[m]=0;
	}
	else
	{
		if(current==Q.CorrectANS)flag[m]=1;
		else flag[m]=0;
	}
	lifel=0;
	}//forloopMEGA

	cleardevice();
	setbkcolor(3);
	setcolor(WHITE);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(320,0,"RESULTS");
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,50,639,54);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	for(i=0;i<10;i++)
	{
		switch(i+1)
		{
		case 1:	outtextxy(40,65+i*33,"Question #1  :");break;
		case 2:	outtextxy(40,65+i*33,"Question #2  :");break;
		case 3:	outtextxy(40,65+i*33,"Question #3  :");break;
		case 4:	outtextxy(40,65+i*33,"Question #4  :");break;
		case 5:	outtextxy(40,65+i*33,"Question #5  :");break;
		case 6:	outtextxy(40,65+i*33,"Question #6  :");break;
		case 7:	outtextxy(40,65+i*33,"Question #7  :");break;
		case 8:	outtextxy(40,65+i*33,"Question #8  :");break;
		case 9:	outtextxy(40,65+i*33,"Question #9  :");break;
		case 10:outtextxy(40,65+i*33,"Question #10 :");break;
		}
		if(flag[i+1]==1)
		{
			outtextxy(170,65+i*33,"Correct");
			totalcorrect+=1;
		}
		else outtextxy(170,65+i*33,"InCorrect/Not Answered");
		if(i==9)
		{
			switch(totalcorrect)
			{
			case 0:	outtextxy(40,65+11*33,"Total           :  0(correct), 10(incorrect)");break;
			case 1:	outtextxy(40,65+11*33,"Total           :  1(correct), 9(incorrect)");break;
			case 2:	outtextxy(40,65+11*33,"Total           :  2(correct), 8(incorrect)");break;
			case 3:	outtextxy(40,65+11*33,"Total           :  3(correct), 7(incorrect)");break;
			case 4:	outtextxy(40,65+11*33,"Total           :  4(correct), 6(incorrect)");break;
			case 5:	outtextxy(40,65+11*33,"Total           :  5(correct), 5(incorrect)");break;
			case 6:	outtextxy(40,65+11*33,"Total           :  6(correct), 4(incorrect)");break;
			case 7:	outtextxy(40,65+11*33,"Total           :  7(correct), 3(incorrect)");break;
			case 8:	outtextxy(40,65+11*33,"Total           :  8(correct), 2(incorrect)");break;
			case 9:	outtextxy(40,65+11*33,"Total           :  9(correct), 1(incorrect)");break;
			case 10:outtextxy(40,65+11*33,"Total           :  10(correct), 0(incorrect)");break;
			}
		}

	}
	fin.open("profile",ios::in|ios::ate|ios::binary);
	fout.open("profile",ios::out|ios::ate|ios::binary);
	fout.seekp((profileID-1)*sizeof(profile),ios::beg);
	fin.seekg((profileID-1)*sizeof(profile),ios::beg);
	fin.read((char*) &P,sizeof(profile));
	if(P.HighScoreMC<totalcorrect)
	P.HighScoreMC=totalcorrect;
	fout.write((char*) &P,sizeof(profile));
	fout.close();
	fin.close();
	getch();
	OUT:            //between resetting unused and results

	fin.open("qMC_file",ios::in|ios::ate|ios::binary);
	fin.seekg(0,ios::beg);
	fout.open("temp",ios::out|ios::binary);
	while(fin.read((char*) &Q,sizeof(questionMC)))
	{
		Q.Unused=1;
		fout.write((char*) &Q,sizeof(questionMC));

	}
	fin.close();
	fout.close();
	fin.open("temp",ios::in|ios::ate|ios::binary);
	fin.seekg(0,ios::beg);
	fout.open("qMC_file",ios::out|ios::binary);
	while(fin.read((char*) &Q,sizeof(questionMC)))
	{
		fout.write((char*) &Q,sizeof(questionMC));
	}
	fin.close();
	fout.close();

	return 0;
}
int PLAYquizMR(int profileID)
{
	randomize();

	profile P;
	FHand file;
	questionMR Q;
	ifstream fin;
	ofstream fout;

	int Q_ID;
	int i,j,a,m;
	int totalcorrect=0;
	int tempa=0,tempans=0;
	int current=1,tempcurrent=0;
	int upx[7]={0,61,331,61,331};
	int upy[7]={0,186,186,246,246};
	int downx[7]={0,309,579,309,579};
	int downy[7]={0,234,234,294,294};
	int flag[11]={0,0,0,0,0,0,0,0,0,0,0};
	int totalids=file.count("qMR_file");

	char question[3][52],ch;

	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	if(totalids<10)
	{
		settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
		settextjustify(CENTER_TEXT,TOP_TEXT);
		outtextxy(320,100,"THERE SHOULD BE MORE THEN OR 10 QUESTION");
		outtextxy(320,150,"U CAN ADD QUESTIONS USING OPTIONS FUNCTION IN MAIN MAENU");
		settextjustify(LEFT_TEXT,TOP_TEXT);
		getch();
		return 0;
	}
	bar(0,0,639,30);                                      //timerBAR
	setcolor(3);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(4,0,"TIMER");
	setcolor(WHITE);
	for(i=0;i<3;i++)
	{
		rectangle(65-i,50-i,575+i,160+i);             //Question
		rectangle(65-i,190-i,305+i,230+i);            //Options
		rectangle(335-i,190-i,575+i,230+i);
		rectangle(65-i,250-i,305+i,290+i);
		rectangle(335-i,250-i,575+i,290+i);
	}
	setcolor(CYAN);
	rectangle(50,4,635,26);
	setfillstyle(SOLID_FILL,15);
	bar(0,459,639,479);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	setcolor(CYAN);
	outtextxy(6,463,"Press W/S/A/D to move Up/Down/Left/Right. Press M to select.");

//MEGA LOOP
	for(m=1;m<11;m++)
	{
	getID:
	Q_ID=random(totalids)+1;						       //make loop overloop random q id between total id
	fin.open("qMR_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionMR),ios::beg);
	fin.read((char*) &Q,sizeof(questionMR));
	fin.close();
	if(Q.Unused==0)goto getID;


	for(i=0;i<3;i++)                                      //resetting question
	{	for(j=0;j<52;j++)
			question[i][j]=' ';
			question[i][51]='\0';
	}

	a=0;                                                  //filling question
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:

	setfillstyle(SOLID_FILL,CYAN);
	bar(66,51,574,159);             //Question
	bar(66,191,304,229);            //Options
	bar(336,191,574,229);
	bar(66,251,304,289);
	bar(336,251,574,289);


	setcolor(WHITE);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(100,50,question[0]);
	outtextxy(100,90,question[1]);
	outtextxy(100,130,question[2]);
	outtextxy(73,193,Q.Option1);
	outtextxy(341,193,Q.Option2);
	outtextxy(73,253,Q.Option3);
	outtextxy(341,253,Q.Option4);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);

	//resetting things
	setfillstyle(SOLID_FILL,WHITE);
	bar(51,5,634,25);
	setfillstyle(SOLID_FILL,CYAN);
	current=1;
	rectangle(upx[current],upy[current],downx[current],downy[current]);
	tempa=0;
	tempans=0;
	SELECT:
	for(i=0;i<584;i++)
	{
		bar(634-i,5,634,25);
		setcolor(WHITE);
		if(tempa==1)
		{
			setcolor(WHITE);
			rectangle(upx[tempans],upy[tempans],downx[tempans],downy[tempans]);
		}
		if(tempa==1)
		{
			if(tempans!=tempcurrent)
			{
				setcolor(CYAN);
				rectangle(upx[tempcurrent],upy[tempcurrent],downx[tempcurrent],downy[tempcurrent]);
			}
		}
		else
		{
			setcolor(CYAN);
			rectangle(upx[tempcurrent],upy[tempcurrent],downx[tempcurrent],downy[tempcurrent]);
		}
		setcolor(WHITE);
		rectangle(upx[current],upy[current],downx[current],downy[current]);
		while(kbhit())
		{

			ch=getch();
			if(ch=='w')
			{
				if(current>2)
				{
					tempcurrent=current;
					current-=2;
				}
			}
			else if(ch=='s')
			{
				if(current<3)
				{
					tempcurrent=current;
					current+=2;
				}
			}
			else if(ch=='a')
			{
					tempcurrent=current;
					current-=1;
					if(current==0)current=4;
			}
			else if(ch=='d')
			{
					tempcurrent=current;
					current+=1;
					if(current==5)current=1;
			}
			else if(ch=='m')
			{
				if(tempans==0)
				tempa=1;
				if(tempa==1&&tempans==0)
				tempans=current;
				if(tempa==1&&current==tempans)continue;
				goto NXT_QUE;

			}
			else if(ch=='\b')goto OUT;
		}
		delay(60);

	}
	NXT_QUE:

	fout.open("qMR_file",ios::out|ios::ate|ios::binary);
	fout.seekp((Q_ID-1)*sizeof(questionMR),ios::beg);
	Q.Unused=0;
	fout.write((char*) &Q,sizeof(questionMR));
	fout.close();

	setcolor(CYAN);
	rectangle(upx[tempans],upy[tempans],downx[tempans],downy[tempans]);
	rectangle(upx[current],upy[current],downx[current],downy[current]);
	if((current==Q.CorrectANS&&tempans==Q.CorrectANS2)||(current==Q.CorrectANS2&&tempans==Q.CorrectANS))flag[m]=1;
	tempa=0;
	tempans=0;
	}//forloopMEGA

	cleardevice();
	setbkcolor(3);
	setcolor(WHITE);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(320,0,"RESULTS");
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,50,639,54);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	for(i=0;i<10;i++)
	{
		switch(i+1)
		{
		case 1:	outtextxy(40,65+i*33,"Question #1  :");break;
		case 2:	outtextxy(40,65+i*33,"Question #2  :");break;
		case 3:	outtextxy(40,65+i*33,"Question #3  :");break;
		case 4:	outtextxy(40,65+i*33,"Question #4  :");break;
		case 5:	outtextxy(40,65+i*33,"Question #5  :");break;
		case 6:	outtextxy(40,65+i*33,"Question #6  :");break;
		case 7:	outtextxy(40,65+i*33,"Question #7  :");break;
		case 8:	outtextxy(40,65+i*33,"Question #8  :");break;
		case 9:	outtextxy(40,65+i*33,"Question #9  :");break;
		case 10:outtextxy(40,65+i*33,"Question #10 :");break;
		}
		if(flag[i+1]==1)
		{
			outtextxy(170,65+i*33,"Correct");
			totalcorrect+=1;
		}
		else outtextxy(170,65+i*33,"InCorrect/Not Answered");
		if(i==9)
		{
			switch(totalcorrect)
			{
			case 0:	outtextxy(40,65+11*33,"Total           :  0(correct), 10(incorrect)");break;
			case 1:	outtextxy(40,65+11*33,"Total           :  1(correct), 9(incorrect)");break;
			case 2:	outtextxy(40,65+11*33,"Total           :  2(correct), 8(incorrect)");break;
			case 3:	outtextxy(40,65+11*33,"Total           :  3(correct), 7(incorrect)");break;
			case 4:	outtextxy(40,65+11*33,"Total           :  4(correct), 6(incorrect)");break;
			case 5:	outtextxy(40,65+11*33,"Total           :  5(correct), 5(incorrect)");break;
			case 6:	outtextxy(40,65+11*33,"Total           :  6(correct), 4(incorrect)");break;
			case 7:	outtextxy(40,65+11*33,"Total           :  7(correct), 3(incorrect)");break;
			case 8:	outtextxy(40,65+11*33,"Total           :  8(correct), 2(incorrect)");break;
			case 9:	outtextxy(40,65+11*33,"Total           :  9(correct), 1(incorrect)");break;
			case 10:outtextxy(40,65+11*33,"Total           :  10(correct), 0(incorrect)");break;
			}
		}
	}
	fin.open("profile",ios::in|ios::ate|ios::binary);
	fout.open("profile",ios::out|ios::ate|ios::binary);
	fout.seekp((profileID-1)*sizeof(profile),ios::beg);
	fin.seekg((profileID-1)*sizeof(profile),ios::beg);
	fin.read((char*) &P,sizeof(profile));
	if(P.HighScoreMR<totalcorrect)
	P.HighScoreMR=totalcorrect;
	fout.write((char*) &P,sizeof(profile));
	fout.close();
	fin.close();
	getch();
	OUT:            //between resetting unused and results

	fin.open("qMR_file",ios::in|ios::ate|ios::binary);
	fin.seekg(0,ios::beg);
	fout.open("temp",ios::out|ios::binary);
	while(fin.read((char*) &Q,sizeof(questionMR)))
	{
		Q.Unused=1;
		fout.write((char*) &Q,sizeof(questionMR));

	}
	fin.close();
	fout.close();
	fin.open("temp",ios::in|ios::ate|ios::binary);
	fin.seekg(0,ios::beg);
	fout.open("qMR_file",ios::out|ios::binary);
	while(fin.read((char*) &Q,sizeof(questionMR)))
	{
		fout.write((char*) &Q,sizeof(questionMR));
	}
	fin.close();
	fout.close();

	return 0;
}
int PLAYquizYN(int profileID)
{
	randomize();

	profile P;
	FHand file;
	questionYN Q;
	ifstream fin;
	ofstream fout;

	int Q_ID;
	int i,j,a,m;
	int totalcorrect=0;
	int current=1,tempcurrent=0;
	int upx[7]={0,61,331};
	int upy[7]={0,186,186};
	int downx[7]={0,309,579};
	int downy[7]={0,234,234};
	int flag[11]={0,0,0,0,0,0,0,0,0,0,0};
	int totalids=file.count("qYN_file");

	char question[3][52],ch;

	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	if(totalids<10)
	{
		settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
		settextjustify(CENTER_TEXT,TOP_TEXT);
		outtextxy(320,100,"THERE SHOULD BE MORE THEN OR 10 QUESTION");
		outtextxy(320,150,"U CAN ADD QUESTIONS USING OPTIONS FUNCTION IN MAIN MAENU");
		settextjustify(LEFT_TEXT,TOP_TEXT);
		getch();
		return 0;
	}
	bar(0,0,639,30);                                      //timerBAR
	setcolor(3);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(4,0,"TIMER");
	setcolor(WHITE);
	for(i=0;i<3;i++)
	{
		rectangle(65-i,50-i,575+i,160+i);             //Question
		rectangle(65-i,190-i,305+i,230+i);            //Options
		rectangle(335-i,190-i,575+i,230+i);
	}
	setcolor(WHITE);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(73,193,"Yes/True");
	outtextxy(341,193,"No/False");
	setcolor(CYAN);
	rectangle(50,4,635,26);
	setfillstyle(SOLID_FILL,15);
	bar(0,459,639,479);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	setcolor(CYAN);
	outtextxy(6,463,"Press A/D to move Left/Right(YES/NO). Press M to select.");

//MEGA LOOP
	for(m=1;m<11;m++)
	{
	getID:
	Q_ID=random(totalids)+1;						       //make loop overloop random q id between total id
	fin.open("qYN_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionYN),ios::beg);
	fin.read((char*) &Q,sizeof(questionYN));
	fin.close();
	if(Q.Unused==0)goto getID;


	for(i=0;i<3;i++)                                      //resetting question
	{	for(j=0;j<52;j++)
			question[i][j]=' ';
			question[i][51]='\0';
	}

	a=0;                                                  //filling question
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:

	setfillstyle(SOLID_FILL,CYAN);
	bar(66,51,574,159);             //Question

	setcolor(WHITE);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(100,50,question[0]);
	outtextxy(100,90,question[1]);
	outtextxy(100,130,question[2]);

	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);

	//resetting things
	setfillstyle(SOLID_FILL,WHITE);
	bar(51,5,634,25);
	setfillstyle(SOLID_FILL,CYAN);
	current=1;
	rectangle(upx[current],upy[current],downx[current],downy[current]);
	SELECT:
	for(i=0;i<584;i++)
	{
		bar(634-i,5,634,25);
		setcolor(CYAN);
		rectangle(upx[tempcurrent],upy[tempcurrent],downx[tempcurrent],downy[tempcurrent]);
		setcolor(WHITE);
		rectangle(upx[current],upy[current],downx[current],downy[current]);
		while(kbhit())
		{

			ch=getch();
			if(ch=='a')
			{
					tempcurrent=current;
					if(current==2)current=1;
			}
			else if(ch=='d')
			{
					tempcurrent=current;
					if(current==1)current=2;
			}
			else if(ch=='m')
			{
				goto NXT_QUE;
			}
			else if(ch=='\b')goto OUT;
		}
		delay(60);

	}
	NXT_QUE:

	fout.open("qYN_file",ios::out|ios::ate|ios::binary);
	fout.seekp((Q_ID-1)*sizeof(questionYN),ios::beg);
	Q.Unused=0;
	fout.write((char*) &Q,sizeof(questionYN));
	fout.close();

	setcolor(CYAN);
	rectangle(upx[current],upy[current],downx[current],downy[current]);
	if(current==Q.CorrectANS)flag[m]=1;
	}//forloopMEGA

	cleardevice();
	setbkcolor(3);
	setcolor(WHITE);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(320,0,"RESULTS");
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,50,639,54);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	for(i=0;i<10;i++)
	{
		switch(i+1)
		{
		case 1:	outtextxy(40,65+i*33,"Question #1  :");break;
		case 2:	outtextxy(40,65+i*33,"Question #2  :");break;
		case 3:	outtextxy(40,65+i*33,"Question #3  :");break;
		case 4:	outtextxy(40,65+i*33,"Question #4  :");break;
		case 5:	outtextxy(40,65+i*33,"Question #5  :");break;
		case 6:	outtextxy(40,65+i*33,"Question #6  :");break;
		case 7:	outtextxy(40,65+i*33,"Question #7  :");break;
		case 8:	outtextxy(40,65+i*33,"Question #8  :");break;
		case 9:	outtextxy(40,65+i*33,"Question #9  :");break;
		case 10:outtextxy(40,65+i*33,"Question #10 :");break;
		}
		if(flag[i+1]==1)
		{
			outtextxy(170,65+i*33,"Correct");
			totalcorrect+=1;
		}
		else outtextxy(170,65+i*33,"InCorrect/Not Answered");
		if(i==9)
		{
			switch(totalcorrect)
			{
			case 0:	outtextxy(40,65+11*33,"Total           :  0(correct), 10(incorrect)");break;
			case 1:	outtextxy(40,65+11*33,"Total           :  1(correct), 9(incorrect)");break;
			case 2:	outtextxy(40,65+11*33,"Total           :  2(correct), 8(incorrect)");break;
			case 3:	outtextxy(40,65+11*33,"Total           :  3(correct), 7(incorrect)");break;
			case 4:	outtextxy(40,65+11*33,"Total           :  4(correct), 6(incorrect)");break;
			case 5:	outtextxy(40,65+11*33,"Total           :  5(correct), 5(incorrect)");break;
			case 6:	outtextxy(40,65+11*33,"Total           :  6(correct), 4(incorrect)");break;
			case 7:	outtextxy(40,65+11*33,"Total           :  7(correct), 3(incorrect)");break;
			case 8:	outtextxy(40,65+11*33,"Total           :  8(correct), 2(incorrect)");break;
			case 9:	outtextxy(40,65+11*33,"Total           :  9(correct), 1(incorrect)");break;
			case 10:outtextxy(40,65+11*33,"Total           :  10(correct), 0(incorrect)");break;
			}
		}
	}
	fin.open("profile",ios::in|ios::ate|ios::binary);
	fout.open("profile",ios::out|ios::ate|ios::binary);
	fout.seekp((profileID-1)*sizeof(profile),ios::beg);
	fin.seekg((profileID-1)*sizeof(profile),ios::beg);
	fin.read((char*) &P,sizeof(profile));
	if(P.HighScoreYN<totalcorrect)
	P.HighScoreYN=totalcorrect;
	fout.write((char*) &P,sizeof(profile));
	fout.close();
	fin.close();
	getch();
	OUT:            //between resetting unused and results

	fin.open("qYN_file",ios::in|ios::ate|ios::binary);
	fin.seekg(0,ios::beg);
	fout.open("temp",ios::out|ios::binary);
	while(fin.read((char*) &Q,sizeof(questionYN)))
	{
		Q.Unused=1;
		fout.write((char*) &Q,sizeof(questionYN));

	}
	fin.close();
	fout.close();
	fin.open("temp",ios::in|ios::ate|ios::binary);
	fin.seekg(0,ios::beg);
	fout.open("qYN_file",ios::out|ios::binary);
	while(fin.read((char*) &Q,sizeof(questionYN)))
	{
		fout.write((char*) &Q,sizeof(questionYN));
	}
	fin.close();
	fout.close();

	return 0;
}
int PLAYquizNum(int profileID)
{
	randomize();

	profile P;
	FHand file;
	questionNum Q;
	ifstream fin;
	ofstream fout;

	int Q_ID;
	int i,j,a,m;
	int totalcorrect=0;
	int current=1;
	int flag[11]={0,0,0,0,0,0,0,0,0,0,0};
	int totalids=file.count("qNu_file");

	char question[3][52],ch,num[4]={'0','0','0','\0'};

	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	if(totalids<10)
	{
		settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
		settextjustify(CENTER_TEXT,TOP_TEXT);
		outtextxy(320,100,"THERE SHOULD BE MORE THEN OR 10 QUESTION");
		outtextxy(320,150,"U CAN ADD QUESTIONS USING OPTIONS FUNCTION IN MAIN MAENU");
		settextjustify(LEFT_TEXT,TOP_TEXT);
		getch();
		return 0;
	}
	bar(0,0,639,30);                                      //timerBAR
	setcolor(3);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(4,0,"TIMER");
	setcolor(WHITE);
	for(i=0;i<3;i++)
	{
		rectangle(65-i,50-i,575+i,160+i);             //Question
		rectangle(290-i,240-i,350+i,280+i);
	}
	//make arrows here;
	setcolor(CYAN);
	rectangle(50,4,635,26);
	setfillstyle(SOLID_FILL,15);
	bar(0,459,639,479);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	setcolor(CYAN);
	outtextxy(6,463,"Press W/S to Increase/Decrease Magnitude , N to make it negetive, M to select.");

//MEGA LOOP
	for(m=1;m<11;m++)
	{
	getID:
	Q_ID=random(totalids)+1;						       //make loop overloop random q id between total id
	fin.open("qNu_file",ios::in|ios::ate|ios::binary);
	fin.seekg((Q_ID-1)*sizeof(questionNum),ios::beg);
	fin.read((char*) &Q,sizeof(questionNum));
	fin.close();
	if(Q.Unused==0)goto getID;


	for(i=0;i<3;i++)                                      //resetting question
	{	for(j=0;j<52;j++)
			question[i][j]=' ';
			question[i][51]='\0';
	}

	a=0;                                                  //filling question
	for(i=0;i<3;i++)
	for(j=0;j<51;j++,a++)
	{
		if(Q.Question[a]=='\0')goto o1;
		question[i][j]=Q.Question[a];
	}
	o1:

	setfillstyle(SOLID_FILL,CYAN);
	bar(66,51,574,159);             //Question

	setcolor(WHITE);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(100,50,question[0]);
	outtextxy(100,90,question[1]);
	outtextxy(100,130,question[2]);

	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);

	//resetting things
	setfillstyle(SOLID_FILL,WHITE);
	bar(51,5,634,25);
	setfillstyle(SOLID_FILL,CYAN);
	flag[0]=0;
	current=1;
	outtextxy(310,245,"001");
	SELECT:
	for(i=0;i<584;i++)
	{
		bar(634-i,5,634,25);
		setfillstyle(SOLID_FILL,CYAN);
		bar(291,241,349,269);
		setcolor(WHITE);
		if(current==0)outtextxy(297,245," ");
		else if(flag[0]==0)
		{
			outtextxy(297,245,"+");
		}
		else if(flag[0]==1)
		{
			outtextxy(297,245,"-");
		}
		if(current<10)
		{
			num[0]='0';
			num[1]='0';
			num[2]=(char)(48+current);
		}
		else if(current<100)
		{
			num[0]='0';
			num[1]=(char)(48+(current/10));
			num[2]=(char)(48+(current%10));
		}
		else if(current==100)
		{
			num[0]='1';
			num[1]='0';
			num[2]='0';
		}
		outtextxy(310,245,num);
		while(kbhit())
		{

			ch=getch();
			if(ch=='w')
			{
				current+=1;
				if(current==(101))current=100;
			}
			else if(ch=='s')
			{
				current-=1;
				if(current==-1)current=0;
			}
			else if(ch=='n')
			{
				if(flag[0]==0)flag[0]=1;
				else if(flag[0]==1)flag[0]=0;
			}
			else if(ch=='m')
			{
				goto NXT_QUE;
			}
			else if(ch=='\b')goto OUT;
		}
		delay(60);

	}
	NXT_QUE:

	fout.open("qNu_file",ios::out|ios::ate|ios::binary);
	fout.seekp((Q_ID-1)*sizeof(questionNum),ios::beg);
	Q.Unused=0;
	fout.write((char*) &Q,sizeof(questionNum));
	fout.close();

	setfillstyle(SOLID_FILL,CYAN);
	bar(291,241,349,279);
	if(flag[0]==1)current=current*(-1);
	if(current==Q.CorrectANS)flag[m]=1;
	}//forloopMEGA

	cleardevice();
	setbkcolor(3);
	setcolor(WHITE);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(320,0,"RESULTS");
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,50,639,54);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	for(i=0;i<10;i++)
	{
		switch(i+1)
		{
		case 1:	outtextxy(40,65+i*33,"Question #1  :");break;
		case 2:	outtextxy(40,65+i*33,"Question #2  :");break;
		case 3:	outtextxy(40,65+i*33,"Question #3  :");break;
		case 4:	outtextxy(40,65+i*33,"Question #4  :");break;
		case 5:	outtextxy(40,65+i*33,"Question #5  :");break;
		case 6:	outtextxy(40,65+i*33,"Question #6  :");break;
		case 7:	outtextxy(40,65+i*33,"Question #7  :");break;
		case 8:	outtextxy(40,65+i*33,"Question #8  :");break;
		case 9:	outtextxy(40,65+i*33,"Question #9  :");break;
		case 10:outtextxy(40,65+i*33,"Question #10 :");break;
		}
		if(flag[i+1]==1)
		{
			outtextxy(170,65+i*33,"Correct");
			totalcorrect+=1;
		}
		else outtextxy(170,65+i*33,"InCorrect/Not Answered");
		if(i==9)
		{
			switch(totalcorrect)
			{
			case 0:	outtextxy(40,65+11*33,"Total           :  0(correct), 10(incorrect)");break;
			case 1:	outtextxy(40,65+11*33,"Total           :  1(correct), 9(incorrect)");break;
			case 2:	outtextxy(40,65+11*33,"Total           :  2(correct), 8(incorrect)");break;
			case 3:	outtextxy(40,65+11*33,"Total           :  3(correct), 7(incorrect)");break;
			case 4:	outtextxy(40,65+11*33,"Total           :  4(correct), 6(incorrect)");break;
			case 5:	outtextxy(40,65+11*33,"Total           :  5(correct), 5(incorrect)");break;
			case 6:	outtextxy(40,65+11*33,"Total           :  6(correct), 4(incorrect)");break;
			case 7:	outtextxy(40,65+11*33,"Total           :  7(correct), 3(incorrect)");break;
			case 8:	outtextxy(40,65+11*33,"Total           :  8(correct), 2(incorrect)");break;
			case 9:	outtextxy(40,65+11*33,"Total           :  9(correct), 1(incorrect)");break;
			case 10:outtextxy(40,65+11*33,"Total           :  10(correct), 0(incorrect)");break;
			}
		}
	}
	fin.open("profile",ios::in|ios::ate|ios::binary);
	fout.open("profile",ios::out|ios::ate|ios::binary);
	fout.seekp((profileID-1)*sizeof(profile),ios::beg);
	fin.seekg((profileID-1)*sizeof(profile),ios::beg);
	fin.read((char*) &P,sizeof(profile));
	if(P.HighScoreNum<totalcorrect)
	P.HighScoreNum=totalcorrect;
	fout.write((char*) &P,sizeof(profile));
	fout.close();
	fin.close();
	getch();
	OUT:            //between resetting unused and results

	fin.open("qNu_file",ios::in|ios::ate|ios::binary);
	fin.seekg(0,ios::beg);
	fout.open("temp",ios::out|ios::binary);
	while(fin.read((char*) &Q,sizeof(questionNum)))
	{
		Q.Unused=1;
		fout.write((char*) &Q,sizeof(questionNum));

	}
	fin.close();
	fout.close();
	fin.open("temp",ios::in|ios::ate|ios::binary);
	fin.seekg(0,ios::beg);
	fout.open("qNu_file",ios::out|ios::binary);
	while(fin.read((char*) &Q,sizeof(questionNum)))
	{
		fout.write((char*) &Q,sizeof(questionNum));
	}
	fin.close();
	fout.close();

	return 0;
}
int Help()
{
	cleardevice();
	int current=1,tempcurrent=0;
	int upx=201;
	int upy[5]={0,130,170};
	int downx=431;
	int downy[]={0,161,201};
	int i,a;
	char ch;
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"HELP");
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(320,130,"CONTROLS");
	outtextxy(320,170,"HOW TO PLAY");

	setfillstyle(SOLID_FILL,15);
	bar(0,100,639,104);
	for(i=133;i<=173;i+=40)
		for(a=0;a<2;a++)
			rectangle(204-a,i-a,428+a,i+25+a);

	settextjustify(LEFT_TEXT,TOP_TEXT);
	setfillstyle(SOLID_FILL,15);
	bar(0,459,639,479);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	setcolor(0);
	outtextxy(6,463,"Press W/S to move Up/Down. Press M to select");
	setcolor(15);

	SELECT:
	setcolor(CYAN);
	rectangle(upx,upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx,upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;
		current-=1;
		if(current==0)current=2;
	}
	else if(ch=='s')
	{
		tempcurrent=current;
		current+=1;
		if(current==3)current=1;
	}
	else if(ch=='m')
	{
		return current;
	}
	else if(ch=='\b') return 0;
	goto SELECT;

}
void Controls_Help()
{
	int i;
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(320,0,"CONTROLS");
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,50,639,54);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(320,65+1*33,"W/S/A/D are the default movement keys i.e. to move the selector box.");
	outtextxy(320,65+3*33,"Sometimes only W/S or A/D are useable.");
	outtextxy(320,65+4*33,"Press M to Select the option.");
	outtextxy(320,65+5*33,"Most of the time u can press BACKSPACE to return back to MainMenu.");
	settextjustify(LEFT_TEXT,TOP_TEXT);
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Press any Key to Return to the MainMenu");
	getch();
}
void HowToPlay_Help(int a)
{
	int i;
	char line1[4][30]={"MULTIPLE CHOICE TYPE - QUIZ",
			 "MULTIPLE RESPONSE TYPE - QUIZ",
			 "YES/NO TYPE-QUIZ",
			 "NUMERICAL ANS TYPE _ QUIZ"};
	char line2[4][56]={"Select Anyone Option to continue to next Question",
			 "Select Anytwo Options to continue",
			 "Select Anyone Option either true or false to continue",
			 "Select Any number(Magnitude with direction) to continue"}  ;
	char line3[4][41]={"Only one Option can be selected out of 4",
			 "Both of them must be True.",
			 "Either true of false can be selected.",
			 "Press N to change Direction/sign."};
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(320,0,"RULES/HELP");
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,50,639,54);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(320,65+2*33,"A Total of 10 Questions will be asked.");
	outtextxy(320,65+0*33,line1[a-1]);
	outtextxy(320,65+3*33,line2[a-1]);
	outtextxy(320,65+4*33,line3[a-1]);
	if(a==1)
	{
		outtextxy(320,65+5*33,"LIFELINE");
		outtextxy(320,65+6*33,"Press L to activate the Lifeline 50/50");
		outtextxy(320,65+7*33,"It can be used only once per Game");
		outtextxy(320,65+8*33,"After activating this You get the ability to select 2 answers");
		outtextxy(320,65+9*33,"if u r not sure which of them is true. Ur choice is marked");
		outtextxy(320,65+10*33,"correct if one of them is true/correct.");
	}
	else
	outtextxy(320,65+6*33,"Results are shown at the end of the game.");
	settextjustify(LEFT_TEXT,TOP_TEXT);
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Press any Key to Continue");
	getch();
}
void About()
{
	int i;
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(320,0,"ABOUT");
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,50,639,54);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(320,65+0*33,"THIS GAME IS CREATED BY HIMANSHU");
	outtextxy(320,65+1*33,"This is a Quiz Game");
	outtextxy(320,65+2*33,"This Game has 4 type of quiz Namely");
	outtextxy(320,65+3*33,"1.Multiple Choice Question  ");
	outtextxy(320,65+4*33,"2.Multiple Response Question");
	outtextxy(320,65+5*33,"3.YES/NO Type Quiz         ");
	outtextxy(320,65+6*33,"4.Numerical Type Question  ");
	outtextxy(320,65+7*33,"All of which store there question in different files");
	outtextxy(320,65+8*33,"Which are then randomly selected during quiz");
	outtextxy(320,65+9*33,"User can modify the Contents of those file with");
	outtextxy(320,65+10*33,"Functions - ADD/MODIFY/DELETE and view them with SHOW");
	settextjustify(LEFT_TEXT,TOP_TEXT);
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Press any Key to Return to the MainMenu");
	getch();
}


void StartPage()
{
	int flag=1;
	setbkcolor(3);
	for(int i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	for(i=0;i<20;i++)
		rectangle(37+i,50+i,147-i,150-i);
	for(i=0;i<20;i++)
		line(92+i,100,148+i,175);
	bar(185,50,205,150);
	bar(205,130,276,150);
	bar(276,50,296,150);
	bar(333,50,444,70);
	bar(333,130,444,150);
	bar(378,70,398,130);
	bar(481,50,592,70);
	bar(481,130,592,150);
	for(i=0;i<30;i++)
		line(592-i,70,511-i,130);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	setfillstyle(SOLID_FILL,3);
	do
	{
		if(kbhit())flag=0;
		bar(120,350,520,450);
		delay(100);
		outtextxy(220,350,"Press Any Key to Continue");
		delay(300);
	}while(flag);
	out:
	getch();
}
int MainMenu(int profileID)
{
	cleardevice();

	profile P;
	ifstream fin;

	int i,k,j,l;
	char ch='e';
	int tempsel=0,current=1;
	char option[7][20]={" ","Start Game","Options/Settings","Help","HighScores","Profiles","About"};
	char description[7][45]={" ",
			       "Choose the type of Quiz and start the game",
			       "ADD/SHOW/REMOVE/MODIFY a question",
			       "How to play the game",
			       "See the Highscores of the players",
			       "Change Profile",
			       "Know About game"};
	int upx[7]={0,58,258,458,58,258,458};
	int upy[7]={0,148,148,148,268,268,268};
	int downx[7]={0,182,382,582,182,382,582};
	int downy[7]={0,232,232,232,352,352,352};
	setfillstyle(SOLID_FILL,15);
	setbkcolor(3);
	setcolor(WHITE);
	for(i=0;i<4;i++)
	rectangle(0+i,0+i,639-i,479-i);
	bar(0,100,639,104);
	setcolor(8);
	for(l=150;l<=270;l+=120)
	for(k=180,i=60;i<=460,k<=580;i+=200,k+=200)
	{
		for(j=0;j<4;j++)
		rectangle(i+j,l+j,k-j,(l+80)-j);
	}
	setcolor(15);
	bar(0,396,639,400);
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	setcolor(8);
	outtextxy(40,0,"MAIN MENU");

	setcolor(WHITE);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(440,24,"Welcome");
	line(440,50,560,50);
	line(440,51,560,51);
	line(430,10,430,90);
	fin.open("profile",ios::in|ios::ate|ios::binary);
	fin.seekg(sizeof(profile)*(profileID-1),ios::beg);
	fin.read((char*) &P,sizeof(profile));
	outtextxy(442,45,P.Name);
	fin.close();

	setcolor(2);
	for(i=158;i<=222;i++)
	line(85,190,145,i);
	setcolor(15);
	setfillstyle(SOLID_FILL,9);
	for(j=165;j<215;j+=20)
	bar(280,j,360,j+10);
	setfillstyle(SOLID_FILL,14);
	setcolor(14);
	for(i=0;i<5;i++)
		circle(520,219,4-i);
	for(i=0;i<9;i++)
		circle(520,181,24-i);
	bar(515,203,524,211);
	setfillstyle(SOLID_FILL,3);
	bar(515,213,491,181);
	setfillstyle(SOLID_FILL,7);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(7);
	outtextxy(73,282,"1.____");
	outtextxy(73,302,"2.____");
	outtextxy(73,322,"3.____");
	for(i=0;i<12;i++)
	{
		circle(297,294,12-i);
		circle(345,295,12-i);
	}
	circle(297,294,13);
	bar(294,306,300,311);
	bar(342,306,348,311);
	bar(284,311,310,342);
	bar(333,311,357,342);
	for(i=0;i<7;i++)
	{
		line(284,311+i,275,335+i);
		line(310,311+i,319,335+i);
		line(333,311+i,324,335+i);
		line(357,311+i,366,335+i);
	}
	for(i=0;i<2;i++)
	{
		rectangle(480+i,278+i,535-i,328-i);
		rectangle(495+i,293+i,560-i,342-i);
	}
	for(i=0;i<40;i+=10)
		line(505,332-i,550,332-i);
	setfillstyle(SOLID_FILL,CYAN);
	bar(482,280,533,326);
	for(i=0;i<40;i+=10)
		line(490,288+i,525,288+i);
	setcolor(8);
	setfillstyle(SOLID_FILL,8);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	floodfill(100,50,DARKGRAY);
	floodfill(80,50,DARKGRAY);
	floodfill(140,50,DARKGRAY);
	floodfill(190,50,DARKGRAY);
	floodfill(260,50,DARKGRAY);
	floodfill(320,50,DARKGRAY);
	floodfill(280,50,DARKGRAY);
	floodfill(363,50,DARKGRAY);
	setfillstyle(SOLID_FILL,15);
	bar(0,459,639,479);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	setcolor(0);
	outtextxy(6,463,"Press W/S/A/D to move Up/Down/Left/Right. Press M to select. BACKSPACE to Exit.");
	setcolor(15);
	setfillstyle(SOLID_FILL,CYAN);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);

	SELECT:
	setcolor(CYAN);
	rectangle(upx[tempsel],upy[tempsel],downx[tempsel],downy[tempsel]);
	rectangle(upx[tempsel]-1,upy[tempsel]-1,downx[tempsel]+1,downy[tempsel]+1);
	bar(5,401,400,458);
	setcolor(WHITE);
	rectangle(upx[current],upy[current],downx[current],downy[current]);
	rectangle(upx[current]-1,upy[current]-1,downx[current]+1,downy[current]+1);
	outtextxy(30,400,option[current]);
	rectangle(30,424,400,425);
	outtextxy(30,420,description[current]);
	ch=getch();
	if(ch=='w')
	{
		if(current>3)
		{
		tempsel=current;
		current-=3;
		}
	}
	else if(ch=='s')
	{
		if(current<4)
		{
		tempsel=current;
		current+=3;
		}
	}
	else if(ch=='a')
	{
		tempsel=current;
		current-=1;
		if(current==0)current=6;
	}
	else if(ch=='d')
	{
		tempsel=current;
		current+=1;
		if(current==7)current=1;
	}
	else if(ch=='m')
	{
		return current;
	}
	else if(ch=='\b')return 0;
	goto SELECT;
}

int Options()
{
	int current=1,tempcurrent=0;
	int upx=225;
	int upy[5]={0,130,170,210,250};
	int downx=410;
	int downy[]={0,161,201,241,281};
	int i,a;
	char ch;
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"OPTIONS");
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(320,130,"ADD a Question");
	outtextxy(320,170,"VIEW all Questions");
	outtextxy(320,210,"REMOVE a Question");
	outtextxy(320,250,"MODIFY a Question");
	setfillstyle(SOLID_FILL,15);
	bar(0,100,639,104);
	for(i=133;i<=253;i+=40)
		for(a=0;a<2;a++)
			rectangle(228-a,i-a,407+a,i+25+a);

	settextjustify(LEFT_TEXT,TOP_TEXT);
	setfillstyle(SOLID_FILL,15);
	bar(0,459,639,479);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	setcolor(0);
	outtextxy(6,463,"Press W/S to move Up/Down. Press M to select");
	setcolor(15);

	SELECT:
	setcolor(CYAN);
	rectangle(upx,upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx,upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;
		current-=1;
		if(current==0)current=4;
	}
	else if(ch=='s')
	{
		tempcurrent=current;
		current+=1;
		if(current==5)current=1;
	}
	else if(ch=='m')
	{
		return current;
	}
	else if(ch=='\b')return 0;
	goto SELECT;
}
int Profile(int bs_o, int curr=1)
{

	FHand file;
	profile P;
	ifstream fin;
	ofstream fout;

	int flag[5]={0,0,0,0,0};

	int current=1,tempcurrent=0;
	int upx=201;
	int upy[5]={0,130,170,210,250};
	int downx=431;
	int downy[]={0,161,201,241,281};
	int i,a;
	char ch,cht=' ';

	fout.open("profile",ios::out|ios::ate|ios::noreplace|ios::binary);
	for(i=0;i<4;i++)
	{
		fout.seekp(i*sizeof(profile),ios::beg);
		strcpy(P.Name,"(empty)");
		P.HighScoreMC=0;
		P.HighScoreMR=0;
		P.HighScoreYN=0;
		P.HighScoreNum=0;
		P.TotalScore=0;
		P.P_ID=0;
		fout.write((char*) &P,sizeof(profile));
	}
	fout.close();


	START_INI:
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"SELECT PROFILE");
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	fin.open("profile",ios::in|ios::ate|ios::binary);
	for(i=0;i<4;i++)
	{
		fin.seekg(sizeof(profile)*i,ios::beg);
		fin.read((char*) &P,sizeof(profile));

		if(P.Name[0]!='('||P.Name[1]!='e'||P.Name[2]!='m'||P.Name[3]!='p'||P.Name[4]!='t'||P.Name[5]!='y'||P.Name[6]!=')')flag[i+1]=1;
		outtextxy(320,130+(i*40),P.Name);
	}
	fin.close();
	setfillstyle(SOLID_FILL,15);
	bar(0,100,639,104);
	for(i=133;i<=253;i+=40)
		for(a=0;a<2;a++)
			rectangle(204-a,i-a,428+a,i+25+a);

	settextjustify(LEFT_TEXT,TOP_TEXT);
	setfillstyle(SOLID_FILL,15);
	bar(0,459,639,479);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	setcolor(0);
	outtextxy(6,463,"Press W/S to move Up/Down. M to select profile. BACKSPACE to Exit. N to change Name(if totalscore=0)");
	setcolor(15);

	SELECT:
	setcolor(CYAN);
	rectangle(upx,upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx,upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;
		current-=1;
		if(current==0)current=4;
	}
	else if(ch=='s')
	{
		tempcurrent=current;
		current+=1;
		if(current==5)current=1;
	}
	else if(ch=='m')
	{
		if(flag[current]==1)
		return current;
		else if(flag[current]==0)
		{
			fout.open("profile",ios::out|ios::ate|ios::binary);
			fout.seekp((current-1)*sizeof(profile),ios::beg);
			intextInterface("Type the Profile Name.");
			i=0;
			while(1)
			{       while(kbhit())
				{
					cht=getch();
					if(cht==';')goto END_TEXT;
					if(i==9)break;
					if((int)cht>=32&&(int)cht<=126)
					{
						P.Name[i]=cht;
						P.Name[i+1]='\0';
						i+=1;
					}
					outtextxy(10,135,P.Name);
				}
				delay(40);

			}
			END_TEXT:
			P.HighScoreMC=0;
			P.HighScoreMR=0;
			P.HighScoreYN=0;
			P.HighScoreNum=0;
			P.TotalScore=0;
			P.P_ID=current;
			fout.write((char*) &P,sizeof(profile));
			fout.close();
		}
		goto START_INI;
	}
	else if(ch=='n')
	{

		fin.open("profile",ios::in|ios::ate|ios::binary);
		fout.open("profile",ios::out|ios::ate|ios::binary);
		fout.seekp((current-1)*sizeof(profile),ios::beg);
		fin.seekg((current-1)*sizeof(profile),ios::beg);
		fin.read((char*) &P,sizeof(profile));
		if(P.TotalScore==0)
		{
			intextInterface("Type the Profile Name.");
			i=0;
			while(1)
			{       while(kbhit())
				{
					cht=getch();
					if(cht==';')goto END_TEXT2;
					if(i==9)break;
					if((int)cht>=32&&(int)cht<=126)
					{
						P.Name[i]=cht;
						P.Name[i+1]='\0';
						i+=1;
					}
					outtextxy(10,135,P.Name);
				}
				delay(40);

			}
			END_TEXT2:
		}
		fout.write((char*) &P,sizeof(profile));
		fout.close();
		fin.close();
		goto START_INI;
	}
	else if(ch=='\b')
	{
		if(bs_o==0)exit(0);
		else if(bs_o==1)
		return curr;
	}
	goto SELECT;
}

int HighScore()
{
	ifstream fin;
	ofstream fout;
	profile P;
	int i;
	char num[4]={' ','0','0','\0'};
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);

	fin.open("profile",ios::in|ios::ate|ios::binary);
	fout.open("profile",ios::out|ios::ate|ios::binary);
	for(i=0;i<4;i++)
	{
		fout.seekp((i)*sizeof(profile),ios::beg);
		fin.seekg((i)*sizeof(profile),ios::beg);
		fin.read((char*) &P,sizeof(profile));
		P.TotalScore=P.HighScoreMC+P.HighScoreMR+P.HighScoreYN+P.HighScoreNum;
		fout.write((char*) &P,sizeof(profile));
	}
	fout.close();
	fin.close();

	setcolor(WHITE);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	fin.open("profile",ios::in|ios::ate|ios::binary);
	for(i=0;i<4;i++)
	{
	fin.seekg((i)*sizeof(profile),ios::beg);
	fin.read((char*) &P,sizeof(profile));
	outtextxy(70,65+(2+(i))*33,P.Name);
	num[1]='0';
	num[2]='0';
	num[1]=(char)(48+(P.HighScoreMC/10));
	num[2]=(char)(48+(P.HighScoreMC%10));
	outtextxy(190,65+(2+(i))*33,num);
	num[1]='0';
	num[2]='0';
	num[1]=(char)(48+(P.HighScoreMR/10));
	num[2]=(char)(48+(P.HighScoreMR%10));
	outtextxy(270,65+(2+(i))*33,num);
	num[1]='0';
	num[2]='0';
	num[1]=(char)(48+(P.HighScoreYN/10));
	num[2]=(char)(48+(P.HighScoreYN%10));
	outtextxy(350,65+(2+(i))*33,num);
	num[1]='0';
	num[2]='0';
	num[1]=(char)(48+(P.HighScoreNum/10));
	num[2]=(char)(48+(P.HighScoreNum%10));
	outtextxy(430,65+(2+(i))*33,num);
	num[1]='0';
	num[2]='0';
	num[1]=(char)(48+(P.TotalScore/10));
	num[2]=(char)(48+(P.TotalScore%10));
	outtextxy(530,65+(2+(i))*33,num);

	}
	fin.close();

	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(320,0,"STATS");
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,50,639,54);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(320,65+0*33,"PLAYER NAME     MC-Q     MR-Q     Y/N-Q    Num-Q      TOTAL");
	settextjustify(LEFT_TEXT,TOP_TEXT);
	bar(0,440,639,444);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(30,444,"Press any Key to Return to the MainMenu");
	getch();
	return 0;
}
int QuestionTYPE()
{
	int current=1,tempcurrent=0;
	int upx=201;
	int upy[5]={0,130,170,210,250};
	int downx=431;
	int downy[]={0,161,201,241,281};
	int i,a;
	char ch;
	cleardevice();
	setbkcolor(3);
	for(i=0;i<4;i++)
		rectangle(0+i,0+i,639-i,479-i);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(BOLD_FONT,HORIZ_DIR,4);
	outtextxy(320,18,"QUESTION TYPE");
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	outtextxy(320,130,"Multiple Choice Question");
	outtextxy(320,170,"Multiple Response Question");
	outtextxy(320,210,"Yes/No Type Question");
	outtextxy(320,250,"Numeric Ans. Question");
	setfillstyle(SOLID_FILL,15);
	bar(0,100,639,104);
	for(i=133;i<=253;i+=40)
		for(a=0;a<2;a++)
			rectangle(204-a,i-a,428+a,i+25+a);

	settextjustify(LEFT_TEXT,TOP_TEXT);
	setfillstyle(SOLID_FILL,15);
	bar(0,459,639,479);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	setcolor(0);
	outtextxy(6,463,"Press W/S to move Up/Down. Press M to select");
	setcolor(15);

	SELECT:
	setcolor(CYAN);
	rectangle(upx,upy[tempcurrent],downx,downy[tempcurrent]);
	setcolor(WHITE);
	rectangle(upx,upy[current],downx,downy[current]);
	ch=getch();
	if(ch=='w')
	{
		tempcurrent=current;
		current-=1;
		if(current==0)current=4;
	}
	else if(ch=='s')
	{
		tempcurrent=current;
		current+=1;
		if(current==5)current=1;
	}
	else if(ch=='m')
	{
		return current;
	}
	else if(ch=='\b') return 0;
	goto SELECT;
}

int main()
{
	int MMoption,Ooption,QuizTYpeOption,Hoption,HtpType,prof;
	int gd=DETECT,gm;
	initgraph(&gd, &gm,"c:/turboc3/bgi");
	StartPage();
	prof=Profile(0);
	MAINMENU:
	MMoption=MainMenu(prof);
	if(MMoption==0)
		goto THE_END;
	if(MMoption==1)
	{
		//StartQuiz();
		QuizTYpeOption=QuestionTYPE();
		if(QuizTYpeOption==0)
		{
			goto MAINMENU;
		}
		if(QuizTYpeOption==1)
		{
			HowToPlay_Help(1);
			PLAYquizMC(prof);
			goto MAINMENU;
		}
		if(QuizTYpeOption==2)
		{
			HowToPlay_Help(2);
			PLAYquizMR(prof);
			goto MAINMENU;
		}
		if(QuizTYpeOption==3)
		{
			HowToPlay_Help(3);
			PLAYquizYN(prof);
			goto MAINMENU;
		}
		if(QuizTYpeOption==4)
		{
			HowToPlay_Help(4);
			PLAYquizNum(prof);
			goto MAINMENU;
		}

	}
	else if(MMoption==2)
	{

		Ooption=Options();
		if(Ooption==0)
		{
			goto MAINMENU;
		}
		if(Ooption==1)
		{
			QuizTYpeOption=QuestionTYPE();
			if(QuizTYpeOption==0)
			{
				goto MAINMENU;
			}
			if(QuizTYpeOption==1)
			{
				ADDquestionMC();
				goto MAINMENU;
			}
			if(QuizTYpeOption==2)
			{
				ADDquestionMR();
				goto MAINMENU;
			}
			if(QuizTYpeOption==3)
			{
				ADDquestionYN();
				goto MAINMENU;
			}
			if(QuizTYpeOption==4)
			{
				ADDquestionNum();
				goto MAINMENU;
			}
		}
		if(Ooption==4)
		{
			QuizTYpeOption=QuestionTYPE();
			if(QuizTYpeOption==0)
			{
				goto MAINMENU;
			}
			if(QuizTYpeOption==1)
			{
				MODquestionMC();
				goto MAINMENU;
			}
			if(QuizTYpeOption==2)
			{
				MODquestionMR();
				goto MAINMENU;
			}
			if(QuizTYpeOption==3)
			{
				MODquestionYN();
				goto MAINMENU;
			}
			if(QuizTYpeOption==4)
			{
				MODquestionNum();
				goto MAINMENU;
			}
		}
		if(Ooption==2)
		{
			QuizTYpeOption=QuestionTYPE();
			if(QuizTYpeOption==0)
			{
				goto MAINMENU;
			}
			if(QuizTYpeOption==1)
			{
				SHOWquestionMC();
				goto MAINMENU;
			}
			if(QuizTYpeOption==2)
			{
				SHOWquestionMR();
				goto MAINMENU;
			}
			if(QuizTYpeOption==3)
			{
				SHOWquestionYN();
				goto MAINMENU;
			}
			if(QuizTYpeOption==4)
			{
				SHOWquestionNum();
				goto MAINMENU;
			}
		}
		if(Ooption==3)
		{
			QuizTYpeOption=QuestionTYPE();
			if(QuizTYpeOption==0)
			{
				goto MAINMENU;
			}
			if(QuizTYpeOption==1)
			{
				DELquestionMC();
				goto MAINMENU;
			}
			if(QuizTYpeOption==2)
			{
				DELquestionMR();
				goto MAINMENU;
			}
			if(QuizTYpeOption==3)
			{
				DELquestionYN();
				goto MAINMENU;
			}
			if(QuizTYpeOption==4)
			{
				DELquestionNum();
				goto MAINMENU;
			}
		}
	}
	if(MMoption==3)
	{
		Hoption=Help();
		if(Hoption==0)
		{
			goto MAINMENU;
		}
		if(Hoption==1)
		{
			Controls_Help();
			goto MAINMENU;
		}
		if(Hoption==2)
		{
			HtpType=QuestionTYPE();
			if(HtpType==0)goto MAINMENU;
			HowToPlay_Help(HtpType);
			goto MAINMENU;
		}
	}
	if(MMoption==6)
	{
		About();
		goto MAINMENU;
	}
	if(MMoption==5)
	{
		prof=Profile(1,prof);
		goto MAINMENU;
	}
	if(MMoption==4)
	{
		HighScore();
		goto MAINMENU;
	}
	getch();
	THE_END:
	closegraph();
	restorecrtmode();
        return 0;
}