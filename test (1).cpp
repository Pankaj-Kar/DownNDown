#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<bits/stdc++.h>
using namespace std;


int p=0,cnt=0,i,j,r,x,y;
int ara[100];
char name[100];

void dnd();
void menu();
void ins();
void ends(int cnt);
void highscore();
void upscore();
bool func(int i,int j)
{
    return i>j;
}

int main(void)
{
    /* request auto detection */
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

    initwindow(800,600);
    int x,y;

    setbkcolor(7);
    //select drawing color
    setcolor(0);



    ///calling main menu function
    menu();
    while(1)
    {


        if(GetAsyncKeyState(VK_LBUTTON))
        {

            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>=10&&x<=260&&y>=230&&y<=288)
            {
                dnd();
                ends(cnt);
                cnt=0;
                menu();


                // cleardevice();
                //break;
            }
            if((x>=10&&x<=260)&&(y>=298&&y<=356))
            {
                ins();
                delay(100);
            }
             if((x>=10&&x<=260)&&(y>=376&&y<=434))
            {
                highscore();
                delay(100);
            }
            if(x>=10&&x<=260&&y>=474&&y<=542)
            {
                delay(2);
                break;

            }

        }


    }
    ///calling game end function


    //menu();
    //delay(1000);
    //ends(cnt);

    //getch();
    // closegraph();
    return 0;

}
void menu()
{

    readimagefile("menu.jpg", 0, 0, 800,600);
    setcolor(GREEN);
    settextstyle(4,0,5);
    delay(1000);
}
void ends(int cnt)
{

    char ss[50];
    char sp[100];
    char sq[100];
    char sr[100];
    sprintf(ss,"Your Score is : %d",cnt);
    sprintf(sp,"Click the left mouse",cnt);
    sprintf(sq,"button to get back to ",cnt);
    sprintf(sr,"main menu",cnt);
    //readimagefile("hh.jpg", 0, 0, 800,600);
    outtextxy(150,150,ss);
    outtextxy(150,250,sp);
    outtextxy(150,350,sq);
    outtextxy(150,450,sr);
    delay(1000);

    int x,y;
     while(1)
         {
            if(GetAsyncKeyState(VK_LBUTTON))
            {

             getmouseclick(WM_LBUTTONDOWN,x,y);
              menu();
             //cleardevice();
             break;
             }

            }

}
int scorereturn()
{
    return 1;

}

void ins()
{
    int x,y;
    readimagefile("ins.jpg", 0, 0, 800,600);

    while(1)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {

            getmouseclick(WM_LBUTTONDOWN,x,y);
              if((x>=180&&x<=480)&&(y>=400&&y<=550))
            {
                break;

            }

            //cleardevice();

        }

    }
     cleardevice();
                menu();

}

///for updating score
void upscore()
{
    FILE *output= fopen("high score.txt","r");
    for(i=0; i<10; i++)
    {
        fscanf(output,"%d",&ara[i]);

        printf("%d *",ara[i]);
    }
    sort(ara,ara+10,func);
    for(i=0; i<10; i++)
    {
        if(cnt>ara[i])
        {
            fclose(output);
            FILE *output= fopen("high score.txt","w");
            for( j=0; j<i; j++)
                fprintf(output,"%d ",ara[j]);
            fprintf(output,"%d ",cnt);
            for( j=i; j<9; j++)
                fprintf(output,"%d ",ara[j]);
            fclose(output);
            break;
        }
    }
}
///for showing highscore
void highscore()
{
    cleardevice();
    readimagefile("back.jpg", 0, 0, 380,150);
    //setcolor(RED);
    setcolor(8);
    int ii=0,p1=0;
    FILE *input=fopen("high score.txt","r");
    char str[50];

    //setactivepage(p);
    // setvisualpage(1-p);
    for(int i=0; i<10; i++)
    {
        //setactivepage(p);
        //setvisualpage(1-p);
        fscanf(input,"%s",&str);

        settextstyle(BOLD_FONT,HORIZ_DIR,6);
        outtextxy(400,(50+ii),str);
        ii+=50;
        // p=1-p;
    }
    // p=1-p;
    //delay(2000);


    while(1)
    {

        if(GetAsyncKeyState(VK_LBUTTON))
        {

            getmouseclick(WM_LBUTTONDOWN,x,y);
              if((x>=180&&x<=480)&&(y>=400&&y<=550))
            {
                break;

            }


            //cleardevice();
            break;
        }

    }

menu();
fclose(input);


}


void dnd()
{


    int y2=0,y=0,c,d,x=380,key,s=0;
    int yl=400,yr=520,p=0;
    int nbyl=yl+250, nbyr=yr+250,nl=0,nr=0;//new bar =nb
    c=70;
    int v=0;
    char arr[50];
    char li[50];
    int life=3;


    while(1)
    {
        ///display


        rectangle(50,50,750,550);

        setfillstyle(SOLID_FILL, 1);
        bar(50,45,752,50);
        bar(50,550,752,555);
        setfillstyle(SOLID_FILL, 4);
        bar(45,50,50,550);
        bar(750,50,755,550);

        setactivepage(p);
        setvisualpage(1-p);
        cleardevice();
        // readimagefile("hh.jpg", 0, 0, 800,600);


        ///keyboard setup

        if (GetAsyncKeyState(VK_LEFT)) ///press left to move the ball left
            x=x-5;

        // is player moving right
        if (GetAsyncKeyState(VK_RIGHT)) ///press right to move the ball right
            x=x+5;
        ///ball

        setcolor(3);  ///color of the ball
        setfillstyle(SOLID_FILL, 4);
        circle(x, c, 20); ///size of the ball
        floodfill(x, c, 3);

        for(int i=0; i<life; i++)
        {
            if(c>=550)
                c=70;

        }
        ///ball movement
        if((x>345&&x<470)||(x<140||x>670))//if the ball moves outside of left stair
        {
            delay(1);
            c++;//the center of Y axis increases to get the ball down

        }

        else
        {

            if((c==yl-y-20&&x<=330&&x>=130)||(c==nbyl-nl-20&&x<=330&&x>=130)||((c==yr-y2-20)&&(x>=470)&&x<=670)||(c==nbyr-nr-20&&x>=470)&&x<=670)
            {
                v++;
                if(v==1)
                {
                    cnt=cnt+v;


                }
                c--;
            }
            else
            {
                c++;
                v=0;
            }

        }





        ///stair_color
        setcolor(5);
        setfillstyle(SOLID_FILL, 3);
        ///for left stairs

        bar(130,yl-y,330,yl+20-y);   //yl=y of left stair
        bar(130,nbyl-nl,330,nbyl+20-nl);


        ///for right stairs
        bar(470,yr-y2,670,yr+20-y2); //yr= y of right stair
        bar(470,nbyr-nr,670,nbyr+20-nr);
        ///red bar
        // setfillstyle(SOLID_FILL, 4);

       // bar(400,yl-y,420,yl+100-y);
       // bar(380,yr+200-y2,400,yr+100-y2);



        y++;
        nl++;
        y2++;
        nr++;

        if(yl-y==50)//if the left stair touches the upper display
        {
            y=0;//then the decrease is stopped
            yl=550;
            //cnt++;


        }

        if(nbyl-nl==50)//if the second left stair touches the upper display
        {
            nl=0;
            nbyl=550;
            //cnt++;


        }
        if(nbyr-nr==50)//if the second right stair touches the upper display
        {
            nr=0;
            nbyr=550;
            //cnt++;

        }

        if(yr-y2==50)//if the right stair touches the upper display
        {
            y2=0;
            yr=550;
            //cnt++;

        }

        sprintf(arr,"Score : %d",cnt);
        outtextxy(10,10,arr);
        sprintf(li,"Life : %d",life);
        outtextxy(600,10,li);
        delay(5);
        p=1-p;
        if (c==50+20||c==550-20||x==50+20||x==750-20)
        {
            c=70;
            x=380;
            life--;


            if(life==0)
            {   upscore();
                setactivepage(p);
                //setvisualpage(1-p);
                cleardevice();



                break;



            }
        }


    }




}
