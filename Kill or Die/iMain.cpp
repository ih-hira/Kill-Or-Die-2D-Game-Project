# include "iGraphics.h"
int x=50,y=100,start=0,z=0;
int mode=0,namelen,count_down=5,countTime;
int name_box_col1,name_box_col2,name_box_col3 ;
char playerName[150], tempName[100];
int bullet_x=x+120,bullet_y=y+180,bullet_time,bullet_mode=0;
int mouse_pos_x,mouse_pos_y;
int total_time=120,game_time;
char shoting_time[100]="120";
int option_pos_x,option_pos_y;
int z1_x=1300,z1_y=400,z1_time;
int z2_x=1300,z2_y=200,z2_time;
int count=0;
char score[1000]="0";
char countdown[10]="5";
int op_1_c1=64,op_1_c2=128,op_1_c3=128;
int op_2_c1=64,op_2_c2=128,op_2_c3=128;
int op_3_c1=64,op_3_c2=128,op_3_c3=128;
int op_4_c1=64,op_4_c2=128,op_4_c3=128;
void HomePage()
{
		iShowBMP(0,0,"Home.bmp");
		iSetColor(op_1_c1,op_1_c2,op_1_c3);
		iFilledRectangle(130,340,220,32);
		iSetColor(255,0,0);
		iText(190,350, "Start Game", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(op_2_c1,op_2_c2,op_2_c3);
		iRectangle(130,270,220,32);
		iSetColor(255,0,0);
		iText(180,280, "How To Play", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(op_3_c1,op_3_c2,op_3_c3);
		iRectangle(130,200,220,32);
		iSetColor(255,0,0);
		iText(210,210, "Option", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(op_4_c1,op_4_c2,op_4_c3);
		iRectangle(130,130,220,32);
		iSetColor(255,0,0);
		iText(190,140, "Exit Game", GLUT_BITMAP_TIMES_ROMAN_24);
}

void nameBox()
{
	iSetColor(name_box_col1,name_box_col2,name_box_col3);
	iText(320,400,"Enter Your Name",GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(250,350,300,30);
	iSetColor(100,100,100);
	iText(230, 300, "Click to activate the box, enter to finish.");
}
void gameWindow()
{
	iShowBMP(0,0,"bg.bmp");
	iShowBMPWOBGWP(bullet_x,bullet_y,"bullet.bmp",16777215);
	iShowBMPWOBGWP(x,y,"ss.bmp",16777215);
	iShowBMPWOBGWP(z1_x,z1_y,"zom1.1.bmp",000000);
	iShowBMPWOBGWP(z2_x,z2_y,"z2.bmp",16777215);
	iSetColor(255,255,255);
	iText(580,680,"Time: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(640,680,shoting_time,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1085,680,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1150,680,score,GLUT_BITMAP_TIMES_ROMAN_24);
}
void shooterPosition(int x1, int y1)
{
	if(y1>200)
	{
		y1=200;
	}
	if(x1>200)
	{
		x=200;
	}
}

void iDraw()
{
	iClear();
	if(start==0)
	{
		HomePage();
		
	}
	if(start==1)
	{
		int i=0;
		iShowBMP(0,0,"bg.bmp");
		iSetColor(255,255,255);
		iText(640,360,countdown,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	/*if(start==1)
	{
		iShowBMP(0,0,"Home.bmp");
		nameBox();
		if(mode == 1)
		{
			iSetColor(255, 255, 255);
			iText(255,360,tempName);
		}
	}*/
	if(start==2)
	{
		gameWindow();
	}
	
}

void iPassiveMouseMove(int mx,int my)
{
	x=mx; y=my;
	if(mx>=52 && mx<=450 && my>=332 && my<=390 &&start==0)
		{op_1_c1=128;op_1_c2=128;op_1_c3=128;PlaySound("mClick",NULL,SND_ASYNC);}
	else
		{op_1_c1=64;op_1_c2=128;op_1_c3=128;}

	if(x>200)
		x=200;
	if(y>300)
		y=300;
	if(y<50)
		y=50;
	if(bullet_mode==0)
	{
		bullet_x=x+120;
		bullet_y=y+180;
	}
}

void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(start==2)
		{iResumeTimer(bullet_time);PlaySound("bulletSound",NULL,SND_ASYNC);}
		bullet_mode=1;
		if(mx>=52 && mx<=450 && my>=332 && my<=390 &&start==0)
			{
				start=1; PlaySound("ctd",NULL,SND_ASYNC);iResumeTimer(countTime);
			}
		else if(mx>=252 && mx<=548 && my>=348 && my<=378 && start==1)
			{
				mode=1;
				name_box_col1=255; name_box_col2=255; name_box_col3=255;
			}
		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

void iKeyboard(unsigned char key)
{
	int i;
	if(mode == 1)
	{
		if(key == '\r')
		{
			FILE *fp;
			mode = 0; name_box_col1=100; name_box_col2=100; name_box_col3=100;
			start=2;
			strcpy(playerName, tempName);
			fp = fopen("playerNameList","w");
			fputs(playerName,fp);
			fclose(fp);
			for(i = 0; i < namelen; i++)
				tempName[i] = 0;
			namelen = 0;
			//iResumeTimer(z1_time);
			//iResumeTimer(z2_time);
		}
		else
		{
			tempName[namelen] = key;
			namelen++;
		}
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}

void showTime()
{
	total_time--;
	sprintf(shoting_time,"%d",total_time);
	if(total_time==0) iPauseTimer(game_time);
}

void bullet()
{
	bullet_x+=150;
	if(bullet_x>1280) 
		{
			bullet_mode=0;
			bullet_x=x+120;
			bullet_y=y+180;
			iPauseTimer(bullet_time);
		}
}

void z1Change()
{
	z1_x-=1;
	int f=0;
	if(bullet_x>(z1_x+10) && bullet_x<(z1_x+100) && bullet_y>z1_y && bullet_y<(z1_y+200))
		{
			count++;
			sprintf(score,"%d",count);
			z1_x=1300;z1_y=400;
			 bullet_x=x+120;bullet_y=y+180;
		}
	if(z1_x<0)
		z1_x=1300;
}

void z2Change()
{
	z2_x-=1;
	if(bullet_x>(z2_x+10) && bullet_x<(z2_x+100) && bullet_y>z2_y && bullet_y<(z2_y+200))
		{
			count++;
			sprintf(score,"%d",count);
			z2_x=1300;z2_y=200;
			 bullet_x=x+120;bullet_y=y+180;
		}
	if(z2_x<0)
		z2_x=1300;
}

void countDown()
{
	if(count_down==0)
		{
			start=2;
			iResumeTimer(z1_time);
			iResumeTimer(z2_time);
		}
	sprintf(countdown,"%d",count_down);
	count_down--;
	
}

int main()
{
	game_time=iSetTimer(1000,showTime);
	z1_time=iSetTimer(10,z1Change);
	z2_time=iSetTimer(10,z2Change);
	countTime=iSetTimer(1000,countDown);
	iPauseTimer(z1_time);
	iPauseTimer(z2_time);
	iPauseTimer(countTime);
	bullet_time=iSetTimer(5,bullet);
	iPauseTimer(bullet_time);
	namelen = 0;
	tempName[0]= 0;
	name_box_col1=100; name_box_col2=100; name_box_col3=100;
	iInitialize(1280, 720, "Kill or Die");
	return 0;
}	