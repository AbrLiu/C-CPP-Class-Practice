#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node* createNewList()//��ʹ���׸��ڵ�
{
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    head->value=0;
    head->next=NULL;
    return head;
}

int addNewNode(struct Node* head,int offset,int value)//offset��ʾ��ӵĽڵ��������еı�ţ�headΪ0�ţ��������εݼ�
{
    int i;
    struct Node *temphead=head;
    for(i=0;i<offset;i++)
    {
        if(temphead->next!=NULL)
        {
            temphead=temphead->next;
        }
        else
        {
            goto error;
        }
    }
    if(temphead->next!=NULL)//������滹�нڵ�Ͳ��룬����ֱ�����
    {
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->value=value;
        temp->next=temphead->next;
        temphead->next=temp;
    }
    else
    {
         struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
         temphead->next=temp;
         temp->value=value;
         temp->next=NULL;
    }

    return 0;

    error:
    printf("Ҫ��ӵĽڵ�ƫ��̫����\n");
    return 1;
}
void printList(struct Node *head)
{
    head=head->next;
    while(head!=NULL)
    {
        printf("%d ",head->value);
        head=head->next;
    }
    printf("\n");
}
int deleteNode(struct Node *head,int offset)
{
    int i;
    struct Node *temphead=head->next;
    struct Node *templast=head->next;
    for(i=0;i<offset;i++)
    {
        if(temphead->next!=NULL)
        {
            temphead=temphead->next;
        }
        else
        {
            goto error;
        }
        if(i!=0)
        {
            templast=templast->next;
        }
    }

    templast->next=temphead->next;
    free(temphead);
    return 0;

    error:
        printf("�±곬����������\n");
        return 1;
}
int main()
{
    struct Node *head=createNewList();
    char step;
    int temp1,temp2;
    while(1)
    {
        printf("��������Ĳ�������a��ʾ���һ���ڵ㣬d��ʾɾ��һ���ڵ㣬p��ʾ��ӡ��������\n");
        fflush(stdin);//ˢ�����뻺������ȥ��\n�ַ�
        scanf("%c",&step);
        switch(step)
        {
            case 'a':
                {
                    printf("��������ӽڵ��λ�ú͸ýڵ��ֵ\n");
                    scanf("%d %d",&temp1,&temp2);
                    addNewNode(head,temp1,temp2);
                    break;
                }
            case 'd':
                {
                    printf("������Ҫɾ���Ľڵ��λ��\n");
                    scanf("%d",&temp1);
                    deleteNode(head,temp1);
                    break;
                }
            case 'p':
                {
                    printList(head);
                    break;
                }
            default:
                {
                    printf("û�и�ָ��\n");
                }
        }
    }
    return 0;
}
