#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>




void dnd();
void menu();
void ins();

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
            {   //delay(500);
                //rectangle(10,220,260,288);
                //delay(500);
                dnd();
               // cleardevice();
            //break;
            }
            if(x>=10&&x<=260&&y>=298&&y<=348)
            {
                ins();
            }
           }


        }
    ///calling game function


    getch();
    closegraph();
    return 0;

}
void menu()
{
    readimagefile("menu.jpg", 0, 0, 800,600);
    setcolor(GREEN);
    settextstyle(4,0,5);
    delay(1000);
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
             menu();
            //cleardevice();
            break;
            }

           }
}

void dnd()
{

    int y2=0,y=0,c,d,x=230,key,s=0;
    int yl=400,yr=520,p=0;
    int nbyl=yl+200, nbyr=yr+200,nl=0,nr=0;//new bar =nb
    //c=yl-y-20;
    c=0;




    while(1)
    {
          ///display


        rectangle(50,50,750,550);
        setactivepage(p);
        setvisualpage(1-p);
        cleardevice();
      // readimagefile("hh.jpg", 0, 0, 800,600);


        ///keyboard setup

    if (kbhit())

        {

        // get keyboard data

        key = toupper(getch());


        // is player moving left

       if (GetAsyncKeyState(VK_LEFT)) ///press left to move the ball left
            x=x-5;

        // is player moving right
        if (GetAsyncKeyState(VK_RIGHT)) ///press right to move the ball right
            x=x+5;



        }
    ///ball

    setcolor(3);  ///color of the ball
    setfillstyle(SOLID_FILL, 3);
    circle(x, c, 20); ///size of the ball
    floodfill(x, c, 3);

    ///ball movement
    if(x>330&&x<470)//if the ball moves outside of left stair
    {
        delay(5);
        c++;//the center of Y axis increases to get the ball down

    }
    else
    {

                if((c==yl-y-20&&x<330)||(c==nbyl-nl-20&&x<330)||(c==yr-y2-20&&x>470)||(c==nbyr-nl-20&&x>470))
                    {
                    c--;
                    }
                else
                    c++;

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



    y++;
    nl++;
    y2++;
    nr++;

    if(yl-y==50)//if the left stair touches the upper display
    {
        y=0;//then the decrease is stopped
        yl=550;

    }

    if(nbyl-nl==50)//if the second left stair touches the upper display
    {
        nl=0;
        nbyl=550;

    }
     if(nbyr-nr==50)//if the second right stair touches the upper display
    {
        nr=0;
        nbyr=550;
    }

    if(yr-y2==50)//if the right stair touches the upper display
        {
            y2=0;
            yr=550;
        }


    delay(5);
    p=1-p;

    }
}
