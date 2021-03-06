#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <termio.h>
#include <memory.h>

void gotoxy(int x, int y)//gotoxy함수 쓰게할수 있게하는 함수
{
    printf("\033[%d;%df",y,x);

    fflush(stdout);
}

void MenuPrint();//메뉴판함수
void Name();//이름입력함수
void Infor();//1.2.3번 누르면 각각 넘어가게함수
void OX_game();//ox게임함수
void buy_things();//돈주는함수
void word_game();//단어게임함수

struct shop//구조체 선언
{
    char name[20];//물건이름
    int money;//돈
    int su;//몇개
};

void gugu();//물건사는함수
void menu_output();//물건출력함수


//구매 목록
#define menu1 "A4 paper"
#define menu2 "poketmon dall"
#define menu3 "24K GOLD pencel"
#define menu4 "nintendo"
#define menu5 "GTA game pack"
#define menu6 "double-deck bed"
#define menu7 "play station"
#define menu_end "8. END"

//구매 목록의 가격
#define M1 30
#define M2 5000
#define M3 10000
#define M4 40000
#define M5 50000
#define M6 300000
#define M7 500000


//메뉴의 최대 개수
#define menumax 8


int game_score=0;//게임점수 0으로 초기화
int my_money=0;//내돈 0원으로 초기화
void ii();//단어게임에서 물건사기함수를 연결할 함수

void start_game()
{//게임시작
    int select;
    system("clear");
    MenuPrint();    
    scanf("%d", &select);//메뉴 1.2.3.번 중 선택
    
    switch(select)                                                      
     {    
        case 1://1번 선택시
            system("clear");//창 깨끗하게
            Name();//Name 함수로 이동
            break;//끝
        case 2://2번 선택시
            system("clear");//창 깨끗하게
            printf("END THE GAME.\n");
            break;//종료
        case 3://3번 선택시
            system("clear");//창 깨끗하게
            { 
                int a;
                time_t   current_time;
                time( &current_time);

                printf( "%ld\n", current_time);
                puts(ctime( &current_time));
                printf("GO BACK: Put any number.\n");
                scanf("%d",&a);
                if (a = 1)
                {
                    start_game();
                }
                system("clear");
            }//case3 종료

        default://아무것도 아닐시
            break;//끝
    }//switch끝
}//strat_game함수 끝

int main(void)
{
    start_game();//게임시작
}

void MenuPrint()
{
    system("clear");
    gotoxy(30,5);  printf("                                                                                            ________________________\n");
    gotoxy(30,6);  printf("                                                                                           1  ____________________  1              \n");
    gotoxy(30,7);  printf("                            o o o                                                          l 1     ___     ___    1 1 \n");
    gotoxy(30,8);  printf("                          o       o     o           o           o                          1 1                    l 1  \n");
    gotoxy(30,9);  printf("                         o               o         o o         o                           1 1      o       o     l 1 \n");
    gotoxy(30,10); printf("                         o                o       o   o       o                            1 1                    1 1\n");
    gotoxy(30,11); printf("                          o o o o          o     o     o     o                             1 1          U         1 1\n");
    gotoxy(30,12); printf("                                  o         o   o       o   o                              1 1                    1 1 \n");
    gotoxy(30,13); printf("                                   o         o o         o o                               1 1____________________1 1\n");
    gotoxy(30,14); printf("                          o       o           o           o                                l  _____________         1\n");
    gotoxy(30,15); printf("                            o o o                                                  ________l [_____________]    O   1________     \n");
    gotoxy(30,16); printf("                                                                                  [________l    _                   1________]\n");
    gotoxy(30,17); printf("            o o o                                                                          l  _l 1_       (X)  __   1 \n");
    gotoxy(30,18); printf("          o       o            o              o           o          o o o o o o           1 [_   _]        _ [__]  1    \n");
    gotoxy(30,19); printf("         o                    o o            o o         o o         o                     l   1_1         [_]      1\n");
    gotoxy(30,20); printf("        o                    o   o          o   o       o   o        o                     1________________________1 \n");
    gotoxy(30,21); printf("        o       o o o       o o o o        o     o     o     o       o o o o o o              1 1               1 1         \n");
    gotoxy(30,22); printf("         o        o        o       o      o       o   o       o      o                        l 1               1 1  \n");
    gotoxy(30,23); printf("          o      o        o         o    o         o o         o     o                        l 1               1 1 \n") ;
    gotoxy(30,24); printf("           o o o         o           o  o           o           o    o o o o o o            __l 1             __1 1 \n");
    gotoxy(30,25); printf("                                                                                           [____1            [____1 \n");
    gotoxy(61,31); printf(" _______________________________________ \n");
    gotoxy(61,32); printf(" __________________MENU_________________ \n");
    gotoxy(61,35); printf("      1   G a m e   S t a r t             \n");
    gotoxy(61,38); printf("      2    E n d    G a m e               \n");
    gotoxy(61,41); printf("      3   C u r r e n t   T i m e         \n");
    gotoxy(61,44); printf("          [Push Number and Enter] \n");
    gotoxy(61,46); printf(" _______________________________________ \n");
    gotoxy(61,47); printf(" _______________________________________ \n");
    }

void Name()
{
    int num;//이름 변수
    printf("PUT YOUR NAME ON! : ");
    scanf("%d" , &num);
    system("clear");//창 깨끗하게
    Infor();//Infor함수로 이동
}
void Infor()
{
    char name[20];//이름변수
    int a;//시작,종료 입력 변수
    scanf("%s",name);
    printf("%s! You have to play the game! I will give you money AS MUCH AS you got a SCORE! You can buy things with that money. GOOD LUCK!\n",name);
    printf("\n");
    printf("put 1 to start, put 2 to end.\n");
    scanf("%d", &a);//1번 누르면 시작, 2번 누르면 종료

    switch(a)
    {
        case 1://1번 누를시
            system("clear");//창 깨끗하게
            OX_game();//OX_game함수로 이동
                break;//끝
        case 2://2번 누를시
            printf("END THE GAME.\n");
                break;//끝
    }
}

void OX_game()
{
    int num, answer;//입력변수,정답변수      
    srand(time(NULL));//랜덤함수 난수생성
   
    int i;
    system("clear");
    printf("==========================================================================\n");
    printf("=                                 < OX G a m e >                         =\n");
    printf("=                             First game is OX game.                     =\n");
    printf("=                       Match up the SIX random questions!               =\n");
    printf("=                            Each score is different!                    =\n");
    printf("=                                                                        =\n");
    printf("==========================================================================\n");

    for(i=0;i<6;i++)
    {

        printf("(O=put 1, X=put 2!!)\n");
        printf("\n");
                                  
        switch(rand()%11)//11개의수 중 1개 랜덤으로 고름
        {
            case 0://랜덤수 0이 골라졌을때

                printf("An ASCII code is a method of expressing the symbols used by a person in a computer.\n(score 5)\n");
                answer=1;//답은 1번
                scanf("%d",&num);//1.2번중 답 선택해서 입력
                if(answer==num)//정답과 입력한 숫자가 일치할때
                {
                    printf("GOOD!\n");
                    game_score+=5;//게임점수 5점 증가
                }

            else//오답일 시 실패
                printf("WRONG!\n");
                break;
        case 1://랜덤수 1이 골라졌을때

            printf("'Float' data type and 'short' data type are 'real type'.\n(score 5)\n");
            answer=2;//답은 1번
            scanf("%d",&num);//1.2번중 답 선택해서 입력
            if(answer==num)//정답과 입력한 숫자가 일치할때
            {
                printf("GOOD!\n");
                game_score+=5;//게임점점수 5점 증가
            }
            else//오답일 시 실패
                printf("WRONG!('short' is 'integer data type'.)\n");
                break;
        case 2:

            printf("'a!=b' means if a and b are same, judge as 1, and if a and b are ditterent, judge as 0.\n(score 10)\n");
            answer=1;
            scanf("%d",&num);
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=10;
            }
            else
                printf("WRONG!\n");
                break;
        case 3:

            printf("If the 'if-else' statement is nested, the 'else' matches the nearest 'if'.\n(score 10)\n");
            answer=1;
            scanf("%d",&num);
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=10;
            }
            else
                printf("WRONG!\n");
                break;
        case 4:

            printf("A 'char' array with a maximum value of 4 subscripts is 'char ary[4]';.\n(score 20)\n");
            answer=2;
            scanf("%d",&num);
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=20;
            }
            else
                printf("WRONG!(declared as 'char ary[5]';)\n");
                break;
        case 5:

            printf("The order in which functions are written must be the same as the order in which they are called.\n(score 5)\n");
            answer=2;
            scanf("%d",&num);
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=5;
            }
            else
                printf("WRONG!\n");
                break;

        case 6:

            printf("'Local variables' are used in preference to 'global variables' of the same name.\n(score 10)\n");
            answer=1;
            scanf("%d",&num);
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=10;
            }
            else
                printf("WRONG!\n");
                break;

        case 7:

            printf("The parameter contains a garbage value if not initialized.\n(score 20)\n");
            answer=2;
            scanf("%d",&num);
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=20;
            }
            else
                printf("WRONG!(The parameter is populated when the function is called.)\n");
                break;

        case 8:

            printf("The value of array 'a[2]' declared 'int a[3]={1};' is 0.\n(score 15)\n");
            answer=1;
            scanf("%d",&num);
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=15;
            }
            else
                printf("WRONG!\n");
                break;

        case 9:

            printf("'Pointer variables' can be used in exactly the same way as 'arrays'.\n(score 15)\n");
            answer=1;
            scanf("%d",&num);
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=15;
            }
            else
                printf("WRONG!\n");
                break;

        case 10:

            printf("Passing a 'large array' as a function argument takes a 'long time' to pass data.\n(score 10)\n");
            answer=2;
            scanf("%d",&num);
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=10;
            }
            else
                printf("WRONG!(same time!)\n");
                break;

        case 11:
                
            printf("In 'int a[i]={0};', the array size 'i' uses only 'global variables'.\n(score 15)\n");
            answer=2;
            scanf("%d",&num);
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=15;
            }   
            else
                printf("WRONG!\n");
                break;

            case 12:

                printf("When pointer variable 'p' points to variable 'i', '*(p++);' increases 'i'.\n(score 20)\n");
                answer=2;
                scanf("%d",&num);
                if(answer==num)
                {
                    printf("GOOD!\n");
                    game_score+=20;
                }
                else
                    printf("WRONG! (To add 1 to the value of 'i', '*p++' is the right expression.)\n");
                    break;
        }
    }
    printf("\n\n!!!!Your CURRENT SCORE is %d!!!!\n\n",game_score);//현재 점수 출력
    ii();//ii함수로 이동
}

int cnt = 0;//word_game의 누적 횟수 0으로 초기화

void ii()
{
    word_game();//word_game으로 이동

    if ((cnt-1)<=10)//cnt-1이 6보다 작거나 같으면
    {
        game_score+=50;//게임점수 50점 추가
    }
    else if((cnt-1)>10 && (cnt-1)<=13)//6보다 크고 11보다 작거나같으면
    {
        game_score+=40;//게임점수 40점 추가
    }
    else if((cnt-1)>14 && (cnt-1)<=17)
    {
        game_score+=30;
    }
    else if((cnt-1)>18 && (cnt-1)<=20)
    {
        game_score+=20;
    }
    else if((cnt-1)>20 && (cnt-1)<=23)
    {
        game_score+=10;
    }
    else
    {
        game_score+=5;
    }

    buy_things();//buy_things함수로 이동
}//ii함수 종료

void word_game()
{
    char put[50];//입력단어 배열
    int cnt = 0;//시도횟수 0으로 초기화
    char *ans[] = {"parameter", "double", "main", "&pt", "fgets", "while"}; //   정답 단어 등록
    int wnum = sizeof(ans)/sizeof(char *);  // 정답 단어의 개수
    int i; //문자를 차례대로 비교하기 위한 변수
    int l;//길이
    char *word; //임의의 단어 포인터 배열
    char *pword;//화면에 출력되는 단어 배열
    int sel; // 난수
    srand(time(NULL));                // 시간을 기준으로 초기화되는 난수 생성 함수
    sel = rand() % wnum;             // 0~ wnum-1 범위의 난수 생성
    word = ans[sel];                 // 임의의 단어 포인터
    l = strlen(word);                //strlen함수 문자열의 길이구함  단어의 길이
    pword = (char *)malloc(l + 1);   // 단어의 길이 +1 만큼 할당된 메모리 주소를 char형으로 변환하여 화면에 나타나는 단어 배열


    for(i=0; i <l; i++)
        pword[i] = '?';     //  화면에 나타나는 단어 ? 로 초기화
    pword[l] = '\0';

    printf("==========================================================================\n");
    printf("=                         <Word Matching  G a m e>                       =\n");
    printf("=                     Second game is Word Matching game.                 =\n");
    printf("=                        Read and answer the question.                   =\n");
    printf("=                     Match words related to the question.               =\n");
    printf("=                                                                        =\n");
    printf("==========================================================================\n");

    printf("\n=========================\n  ~~10 times: 50 points \n11~~13 times: 40 points \n14~~17 times: 30 points \n18~~20 times: 20 points \n21~~23 times: 10 points \nOther: 5 points\n=========================\n");

    /* 정답단어에 따라서 출력되는 문제*/
    {  if(word[0] == 'p')
        printf("<Question> The data the function needs to perform its work (given from the outside)");
        if(word[0] == 'd')
            printf("<Question> Variable to handle integer types");
        if(word[0] == 'm')
            printf("<Question> What function must be present in every C language program?");
        if(word[0] == '&')
            printf("<Question> When you declare variables as follows,What are the different values?\n int a[5]=1,2,3,4,5;\n int *pt=a;\n < *pt, **a, &&a, &pt>\n");
        if(word[1] == 'g')
            printf("<Question> A function that reads and returns a single line from a file");
        if(word[1] == 'w')
            printf("<Question> The name of the loop");
    }
    while (1)
    {
        printf("\nMatching word : %s  ", pword);

        fgets(put, sizeof(put), stdin);  //  문자입력

        cnt++;                                    // 시도 회수 카운트

        for(i=0; i <l; i++)
            if(pword[i] == '?' && word[i] == put[0])   // 입력된 문자가 아직 가려져 있고 입력한 문자가 정답 단어에 있으면
                pword[i] = put[0]; //?에 입력한 문자 출력
        

        for(i=0; i <l; i++)
            if(pword[i] == '?') //?인 문자가 있으면 반복
                break;


        if(i == l) {      // 가려진 문자가 없으면(정답단어를 맞췄으면)
            printf("\nCompleted '%s' only %d times\n\n", pword, cnt-1);
            put[strlen(put)-1] = '\0';
           return 0;
        }
    }
    return 0;                                                                                                                                        
}

void buy_things()
{
    printf("\n!!!!Your TOTAL SCORE is %d!!!!\n",game_score);//최종 점수 출력

    if(game_score==155)//게임점수가 155점 이면
    {
        my_money=500000;//50만원 지급
    }
    else if (game_score<155 && game_score>=125)//게임점수가 154~125점 이면
    {
        my_money=450000;//45만원 지급
    }
    else if (game_score<125 && game_score>=105)//게임점수가 124~105점 이면
    {
        my_money=300000;//30만원 지급
    }
    else if (game_score<105 && game_score>=85)
    {
        my_money=100000;
    }
    else if (game_score<85 && game_score>=65)
    {
        my_money=80000;
    }
    else if (game_score<65 && game_score>=45)
    {
        my_money=50000;
    }
    else if (game_score<45 && game_score>=25)
    {
        my_money=10000;
    }
    else//아무것도 아니면
        my_money=30;//30원 지급

    printf("===========================\n    155 score: 500000 won\n154~125 score: 450000 won\n124~105 score: 300000 won\n104~ 85 score: 100000 won\n 84~ 65 score: 80000  won\n 64~ 45 score: 50000  won\n 44~ 25 score: 10000  won\nOthers: 30 won\n===========================\n");
    printf("!!!!You got %d won!!!!\n",my_money);//위에거 설명 출력

    gugu();//gugu함수로 이동
}

void gugu()
{
    //구조체를 초기화
    struct shop gujo[menumax]={
        {menu1, M1, 0},
        {menu2, M2, 0},
        {menu3, M3, 0},
        {menu4, M4, 0},
        {menu5, M5, 0},
        {menu6, M6, 0},
        {menu7, M7, 0}
    };
    int select/*선택*/, i, money_tot=0/*살물건총합돈*/,pay=0/*낼돈*/;

    for(i=0;i<menumax-1;i++)
        gujo[i].su=0;
        
    menu_output();//메뉴 출력함수
    
    printf("Please select the item you wish to purchase.(in the range of money you have)(1-7) END is 8.\n");
    printf("There is only ONE shopping opportunity. Please choose carefully.\n");//니가 가지고있는돈내에서 사고싶은걸 골라라. 기회는 한번뿐.
    scanf("%d", &select);//사고싶은거 입력

    if(select==8)//8번을 누르면
    {
        printf("\nyou ENDED!\n");//너가 끝냈어!

    }
    else if(select<1 || select>menumax)//1~8번이 아닐시
    {
        printf("\nwrong number!\n\n");//잘못된 숫자!

    }
    printf("you choose %s!\n", gujo[select-1].name);
    while(1)//1~10이외의 값을 받았으면 잘못된숫자! 출력 후 다시 얼마받을거냐고 출력
    {
        printf("How many? (1-10)\n");
        scanf("%d", &gujo[select-1].su);

        if(gujo[select-1].su<1 || gujo[select-1].su>10)   
            printf("\nwrong number!\n\n");      
        else
            break;
    }

    printf("\n-----TOTAL-----\n");
    
    for(i=0;i<menumax-1;i++)//수량을 1개이상 선택했으면 선택사항 출력 반복문
    {
        if(gujo[i].su==0) continue;
        printf("%s = \\%d * %d = \\%d \n", gujo[i].name, gujo[i].money, gujo[i].su, gujo[i].money * gujo[i].su);
        money_tot+=gujo[i].money * gujo[i].su;//총 합계금액을 출력
    }  
    
    printf("total = \\%d\n", money_tot);
    //낼 돈을 입력 받음

    do{
        if(money_tot==0) break; //하나도 안골랐을경우는 입력 받지 않고 반복문을 종료
        printf("\nPut 'how much you pay': ");
        scanf("%d", &pay);
    }while(pay<money_tot);


    printf("you pay : \\%d\n", pay);//니가 낼돈 입력
    printf("change : \\%d - \\%d = \\%d \n", pay, money_tot, pay-money_tot);//거스름돈 출력
    
    if(pay>my_money)//만약 니가 낼돈이 내가가진돈보다 크면
    {
        printf("\n!!!You don't have enough money... Shopping faile!!!!\n");//돈이 부족합니다. 쇼핑실패!!출력
    }
    else
        printf("\nleft money is %d won.",my_money-money_tot);//아니면 니가 물건을 사고 남은돈 출력


    printf("\n----------------------------------------\n");
    printf("        thank you~~~~~~~~~~~~~~\n");//감사합니다~~~~~~~~~~~~~~~~~~~
    printf("----------------------------------------\n");  
}

void menu_output()//메뉴출력함수
{    
    puts("\n-------------------------------");
    printf("1. %s : \\%d\n", menu1, M1);
    printf("2. %s : \\%d\n", menu2, M2);
    printf("3. %s : \\%d\n", menu3, M3);
    printf("4. %s : \\%d\n", menu4, M4);
    printf("5. %s : \\%d\n", menu5, M5);
    printf("6. %s : \\%d\n", menu6, M6);
    printf("7. %s : \\%d\n", menu7, M7);
    puts(menu_end);
    puts("-------------------------------");
}   

