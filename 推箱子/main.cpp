#include<cstdio>

char GameMap[100][100];
int n,m,startX,startY,endX,endY;

void move(char step)
{
    if('w'==step)
    {
        if(' '==GameMap[startX-1][startY])
        {
            GameMap[startX][startY]=' ';
            GameMap[--startX][startY]='H';
            goto leave;
        }
        if('O'==GameMap[startX-1][startY])
        {
            if('*'==GameMap[startX-2][startY])
                goto error;
            GameMap[startX][startY]=' ';
            GameMap[--startX][startY]='H';
            GameMap[startX-1][startY]='O';
        }
    }

    if('s'==step)
    {
        if(' '==GameMap[startX+1][startY])
        {
            GameMap[startX][startY]=' ';
            GameMap[++startX][startY]='H';
            goto leave;
        }
        if('O'==GameMap[startX+1][startY])
        {
            if('*'==GameMap[startX+2][startY])
                goto error;
            GameMap[startX][startY]=' ';
            GameMap[++startX][startY]='H';
            GameMap[startX+1][startY]='O';
        }
    }

    if('a'==step)
    {
        if(' '==GameMap[startX][startY-1])
        {
            GameMap[startX][startY]=' ';
            GameMap[startX][--startY]='H';
            goto leave;
        }
        if('O'==GameMap[startX][startY-1])
        {
            if('*'==GameMap[startX][startY-2])
                goto error;
            GameMap[startX][startY]=' ';
            GameMap[startX][--startY]='H';
            GameMap[startX][startY-1]='O';
        }
    }

    if('d'==step)
    {
        if(' '==GameMap[startX][startY+1])
        {
            GameMap[startX][startY]=' ';
            GameMap[startX][++startY]='H';
            goto leave;
        }
        if('O'==GameMap[startX][startY+1])
        {
            if('*'==GameMap[startX][startY+2])
                goto error;
            GameMap[startX][startY]=' ';
            GameMap[startX][++startY]='H';
            GameMap[startX][startY+1]='O';
        }
    }

    error:;
    printf("�����ƶ�\n");

    leave:;
}
void PrintMap()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%c",GameMap[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    char step;
    printf("��������Ϸ����������Ϸ���̵ĳ���\n");
    printf("��������Ϸ��ͼ����*����ʾ�ϰ��X��ʾĿ�꣬O��ʾ���ӣ�H��ʾ������������λ��,�뽫��ͼ�߽���*���\n");
    printf("�����������£�\n6 6\n******\n*  H *\n*  O *\n*  * *\n* X  *\n******\n");
    scanf("%d %d",&n,&m);

    fflush(stdin);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%c",&GameMap[i][j]);
            if('H'==GameMap[i][j])
            {
                startX=i;
                startY=j;
            }
            if('X'==GameMap[i][j])
            {
                endX=i;
                endY=j;
            }
        }
       //fflush(stdin);
        getchar();//��ջس�
        //getchar();
    }

    printf("����wsad����С���ƶ�\n");

    while('O'!=GameMap[endX][endY])
    {
        scanf("%c",&step);
        move(step);
        PrintMap();
    }
    printf("Game Over\n");

    return 0;
}
