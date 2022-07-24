#include <bits/stdc++.h>
#include<math.h>
using namespace std;

#define setnum 2048
#define waynum 8

int main()
{
    FILE *fp_in = fopen("writes_to_L2.txt","r");
    FILE *fp_out = fopen("rub1.txt","w");
    FILE *fp_out1 = fopen("rub2.txt","w");
    int dat, count=0, setWrites =0;
    long double avg=0,inter_var=0, intra_var=0,var[setnum]= {0},set_var[setnum]={0};
    long int max=0,min;
    int num=1,set[setnum][waynum]={0},maxset=0,maxway=0;
    while(!feof(fp_in))
    {  
        fscanf(fp_in,"%d",&dat);	
        if(dat==-1234)
        {
            fprintf(fp_out,"\n\n Matrix for segment: %d\n\n",num++);
            //fscanf(fp_in,"%d",&dat);	
            if(!feof(fp_in))
            {	
                for(int i=0;i<setnum;i++)
                {
                    fprintf(fp_out,"set: %d ,   ",i);
                    for(int j=0;j<waynum;j++)
                    {
                        fscanf(fp_in,"%d",&dat);		
                        fprintf(fp_out," %d  ,  ",dat);
                        set[i][j] = set[i][j]+dat;	
                    }
                    fprintf(fp_out,"\n");
                }
            }  	
        }	
    }
    min = set[0][0];
    for(int i=0;i<setnum;i++)
    {
        setWrites=0;
        fprintf(fp_out1, "Set %d : ", i);
        for(int j=0;j<waynum;j++)
        {
            fprintf(fp_out1,"%d ,",set[i][j]);
            if(set[i][j]>max)
            {
                max= set[i][j];
                maxset=i;
                maxway=j;
            }
            if(set[i][j]==0)
                count++;
            if(set[i][j]<min)
            {
                min= set[i][j];    
            }
            avg= avg+(set[i][j]);
            setWrites+= set[i][j];
        }
        fprintf(fp_out1,"\tTotal Writes in set = %d\n", setWrites);
    }
    cout<<" \nTotal writes: \t"<<avg<<"\n";
    cout<<"WPKI: \t"<< avg/1000000<<"\n";
    avg= avg/(setnum*waynum);
    for(int i=0;i<setnum;i++)
    {
        for(int j=0; j<waynum; j++)
            var[i] =var[i]+ set[i][j];
        var[i]= var[i]/waynum;
        //cout<<var[i]<<"\n";
    }
    for(int i=0; i<setnum; i++)
    {
        for(int j=0; j<waynum; j++)
            set_var[i]+=(set[i][j]-var[i])*(set[i][j]-var[i]);
        set_var[i]=sqrt(set_var[i]/(waynum-1));
        //cout<<set_var[i]<<"\n";
    }
    for(int i=0; i<setnum; i++)
        intra_var=intra_var+set_var[i];
    cout<<"intra_var=\t"<<intra_var<<"\n";

    intra_var= intra_var/(avg*setnum);
    
    for(int i=0;i<setnum;i++)
        inter_var=inter_var+((var[i]-avg)*(var[i]-avg));
    inter_var=sqrt(inter_var/setnum-1);
    inter_var=inter_var/avg;
    
    cout<<"average = \t"<<avg<<"\nmaximum = \t"<< max<<"\nat set "<<maxset<<" way "<<maxway<<"\nminimum :\t"<<min<<"\nzero count is "<<count;
    cout<<"\n\nIntraset variation =\t"<<intra_var<<"\nInter set variation:\t"<<inter_var<<"\n";
    
    return(0);
}
