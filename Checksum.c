#include<stdio.h>
#include<math.h>

int convert(long long p) {
  int dec = 0, i = 0, rem;

  while (p!=0) {
    rem = p % 10;
    p /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

int sender(int arr[10],int n)
{
    int checksum,num,sum=0,i;
    printf("\n****SENDER SIDE****\n");
    for(i=0;i<n;i++)
    num=convert(i);
    sum+=arr[num];
    printf("SUM IS: %d",sum);
    checksum=~sum;    //1's complement of sum
    printf("\nCHECKSUM IS:%d",checksum);
    return checksum;
}
 
void receiver(int arr[10],int n,int sch)
{
    int checksum,sum=0,i;
    printf("\n\n****RECEIVER SIDE****\n");
    for(i=0;i<n;i++)
        sum+=arr[i];
    printf("SUM IS:%d",sum);
    sum=sum+sch;
    checksum=~sum;    //1's complement of sum
    printf("\nCHECKSUM IS:%d",checksum);
}

void main()
{
    int n,sch,rch;
    printf("\nENTER SIZE OF THE STRING:");
    scanf("%d",&n);
    int arr[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY TO CALCULATE CHECKSUM:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sch=sender(arr,n);
    receiver(arr,n,sch);
}
