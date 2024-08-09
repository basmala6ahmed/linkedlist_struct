#include <stdio.h>
#include <stdlib.h>
struct person
{
    int data;
    struct person* pprev;
    struct person* pnext;

}*pfirst, *plast;
//struct person* pfirst, plast;
struct person * createperson(int data);
void addperson (int data);
void deleteperson(int index);
void insertperson(int data,int index);
int getcount();
struct person* preader;
int main()
{
    addperson(1);
    addperson(2);
    addperson(3);
    addperson(4);
    addperson(5);
    addperson(6);

    printf("count= %d", getcount());
   //insertperson(0,1);
   // for(preader=pfirst; preader!=NULL; preader=preader->pnext)
   //{

     //  printf("\nDATA=%d",preader->data);
   //}
    return 0;
}
struct person * createperson(int data)
{
    struct person * pperson =(struct person*)malloc(sizeof(struct person)); //h3ml blockaya fel memory lel struct person
    if (pperson!= NULL)
    {
        pperson->data=data;
        pperson->pnext=NULL;
        pperson->pprev=NULL;    //access
    }
    return pperson;
};
void addperson (int data)    //add ndht 3ala create
{
    struct person *pperson=createperson(data);
    if(pperson!=NULL)  //list is empty
    {
        if(pfirst== NULL)
        {
            pfirst=plast=pperson;
        }
        else
        {
            plast->pnext=pperson;
            pperson->pprev=plast;
            plast=pperson;

        }

    }
    else
    {
        printf("\n\nNo enough memory space!!\n\n");
    }


}
void deleteperson(int index)
{
    //list is empty
    if(pfirst==NULL)
    {
        printf("list is already EMPTY!!\n\n");
    }
    else
    {
        //is first
        if(index==1)
        {
            pfirst=pfirst->pnext; //khalet ragel yshawr 3ala 2 mesh 1 by accessing
            free(pfirst->pprev);  //keda 2 baa shayl el first fa h3ml free lel prev which is 1 previously
            pfirst->pprev=NULL;

        }
        else
        {
            //in middle

            struct person *pcur=pfirst;
            int i=1;
            for (;  pcur->pnext!=NULL; i++)
            {
                if(i==index)
                {
                    pcur->pnext->pprev=pcur->pprev;
                    pcur->pprev->pnext=pcur->pnext;
                    free(pcur);
                }
                pcur=pcur->pnext;
            }
            if (index>i)
            {
                //index is out of index
                printf("\n\n Out of Range!!\n\n");
            }
            else if(index==i)
            {
                //last
                plast= plast->pprev;
                free(plast->pnext);
                plast->pnext=NULL ;

            }
            else
            {

            }

        }




    }





}

int getcount(){
    struct person *pcur=pfirst;
    int count =0;
    if(pcur!=NULL){
        count=1;
        for(;pcur->pnext!=NULL;count++){
            pcur=pcur->pnext;
        }


    }

return count;

}

 void insertperson(int data,int index){
   struct person* pperson = createperson(data);
   int n=0;
   if(pfirst!=NULL){
    n= getcount();
   }
   else{
    printf("list is empty kindly addperson()to create a list ");
    return;
   }
   if(pperson!=NULL){
    if(index==1){   //first
            pfirst->pprev=pperson;
            pperson->pnext=pfirst;
            pfirst=pperson;

    }
    else if(index==n+1){  //last
        addperson(data);

    }
    else if(index>n+1 || index<1){
        printf("index is out of range ,last person has order %d",n);
    }
    else if(index<=n){       //middle
        struct person* pcur=pfirst; //l pcur da dummy pointer ana cryto hy3od ythrk mn pfirst lhd ma awsl lel ana 3yzo acc to index
        for(int i=1;i<index;i++){
                pcur=pcur->pnext;  //el pointer l pcur el cryto hythrk steps mn awl pfirst lhd

       }

        pcur->pprev->pnext=pperson;
        pperson->pprev=pcur->pprev ;
        pcur->pprev=pperson;
        pperson->pnext=pcur;

    }
    else{

    }

   }
   else{
    printf("\n\n No enough memory space to create new personality!!");
   }




 }


