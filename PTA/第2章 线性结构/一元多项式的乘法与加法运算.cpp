//
#include<cstdlib>
#include<cstdio>
typedef struct PolyNode *Polynomial;
struct PolyNode{
    int coef;
    int expon;
    Polynomial link;
};
void Attach(int c, int e, Polynomial *pRear)
{
    Polynomial P;

    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}
Polynomial ReadPoly()
{
    Polynomial P, Rear;
    int N;
    int c, e;

    scanf("%d",&N);
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while(N--)
    {
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear);
    }
    Rear = P; P = P->link; free(Rear);     /*ɾ����ʱ���ɵ�ͷ���*/
    return P;
}
Polynomial Add(Polynomial P1, Polynomial P2)      //�Ͷ���ʽ������
{
    Polynomial Rear, temp1, temp2, P;
    temp1 = P1;
    temp2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while(temp1 && temp2)
    {
        if(temp1->expon > temp2->expon)
        {
            Attach(temp1->coef, temp1->expon, &Rear);
            temp1 = temp1->link;
        }
        else if(temp1->expon < temp2->expon)
        {
            Attach(temp2->coef, temp2->expon, &Rear);
            temp2 = temp2->link;
        }
        else
        {
            if(temp1->coef + temp2->coef)
            {
                Attach(temp1->coef + temp2->coef, temp1->expon, &Rear);
                temp1 = temp1->link;
                temp2 = temp2->link;
            }
            else
            {
                temp1 = temp1->link;
                temp2 = temp2->link;
            }
        }
    }
    if(temp1)
    {
        Rear->link = temp1;
    }
    else if(temp2)
    {
       Rear->link = temp2;
    }
    Rear = P; P = P->link; free(Rear);    /*ɾ����ʱ���ɵ�ͷ���*/
    return P;
}
Polynomial Mult(Polynomial P1, Polynomial P2)      //�˶���ʽ����Ҫ����0 0
{
    Polynomial P, Rear, temp1, temp2, temp;
    int c, e;

    if(!P1 || !P2) return NULL;

    temp1 = P1;
    temp2 = P2;
    P = (Polynomial)malloc(sizeof(PolyNode));
    P->link = NULL;
    Rear = P;
    while(temp2)   //��ʼ����ʽ��P1�ĵ�һ�����P2��ÿһ��õ�
    {
        Attach(temp1->coef * temp2->coef, temp1->expon + temp2->expon, &Rear);
        temp2 = temp2->link;
    }
    temp1 = temp1->link;
    while(temp1)     //�𲽲��뷨
    {
        temp2 = P2;
        Rear = P;
        while(temp2)
		{
			c = temp1->coef * temp2->coef;
			e = temp1->expon + temp2->expon;
			while(Rear->link && Rear->link->expon > e)	//��Rear����һ�Ϊ������һ���ָ���ȵ�ǰ�ĳ˻�e��ʱ��Rear����
			{									        //Ϊʲôe���Ա�Rearָ��ĵ�ǰ���ָ����
				Rear = Rear->link;					    //��Ϊ�ǵ���������ѵ�ǰ�Ķ���ʽ����Rear����ô���ȶ���ʽ�޷�����һ��������
			}
			if(Rear->link && Rear->link->expon == e)	//ָ����ȵ����
			{
				if(Rear->link->coef + c)				//ϵ����Ӳ�Ϊ��
				{
					Rear->link->coef += c;
				}
                else
                {//ϵ�����Ϊ0���������ʽ
					Rear->link->coef = 0;
					Rear->link->expon = 0;
				}
			}
			else
            {//��ǰ����ʽ��ָ������Rear����һ��ָ��
				temp = (Polynomial)malloc(sizeof(PolyNode));
				temp->coef = c;
				temp->expon = e;
				temp->link = Rear->link;
				Rear->link = temp;
				Rear = Rear->link;
			}
			temp2 = temp2->link;
		}
		temp1 = temp1->link;
	}
	Rear = P; P = P->link; free(Rear);
	return P;
}
void PrintPoly(Polynomial P)
{
    int flag = 0;
    if(!P) {printf("0 0");}
    while(P)
    {
        if(!flag)             /*flag==0,��ʾ�ǿ�ͷ*/
            flag = 1;
        else
            printf(" ");
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}
int main()
{
    Polynomial P1, P2, PP, PS;

    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult(P1, P2);
    PrintPoly(PP);
    PS = Add(P1, P2);
    PrintPoly(PS);

    return 0;
}
