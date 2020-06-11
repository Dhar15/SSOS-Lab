/* Question - Design, develop and implement a C/C++/Java program to implement page replacement algorithms LRU and FIFO. 
   Assume suitable input required to demonstrate the results. */
   
 #include<stdio.h>

int findLRU(int time[], int n){
	int i, minimum = time[0], pos = 0;
 
	for(i = 1; i < n; ++i){
		if(time[i] < minimum){
			minimum = time[i];
			pos = i;
		}
	}
	
	return pos;
}

void FIFO(int pages[], int frames[], int pagenum, int framesnum) 
{  
        int i,j=0,k,avail,count=0;
        
        for(int i = 0; i < framesnum; ++i){
    		frames[i] = -1;
    	}
    	
        printf("String\tFrames\n");
	  for(i=0;i<pagenum;i++)
         {
                    printf("%d\t",pages[i]);
                    avail=0;
                    for(k=0;k<framesnum;k++)
			if(frames[k]==pages[i])
                          avail=1;
                    
                    if (avail==0)
                    {
                                frames[j]=pages[i];
                                j=(j+1)%framesnum;
                                count++;
                                for(k=0;k<framesnum;k++)
                                	printf("%d ",frames[k]);
		     }
		     else {
		     	for(k=0;k<framesnum;k++)
                             	printf("%d ",frames[k]);
                    }
                    printf("\n");	
	}
        printf("\nTotal Page Faults= %d",count);
        return 0;
}

void LRU(int pages[],int frames[],int pagenum,int framesnum) 
{
	int flag1,flag2, i, j,pos, faults = 0,counter = 0, time[10];
	
	for(int i = 0; i < framesnum; ++i){
    		frames[i] = -1;
    	}
	printf("String\tFrames\n");
	
	for(i = 0; i < pagenum; ++i)
    	{
    		flag1 = flag2 = 0;
	    	
    	
    		for(j = 0; j < framesnum; ++j)
    		{
    			if(frames[j] == pages[i]){
	    			counter++;
	    			time[j] = counter;
	   			flag1 = flag2 = 1;
	   			break;
   			}
    		}
    	
    		if(flag1 == 0){
			for(j = 0; j < framesnum; ++j){
	    			if(frames[j] == -1){
	    				counter++;
	    				faults++;
	    				frames[j] = pages[i];
	    				time[j] = counter;
	    				flag2 = 1;
	    				break;
	    			}
    			}	
    		}
    	
	    	if(flag2 == 0){
	    		pos = findLRU(time, framesnum);
	    		counter++;
	    		faults++;
	    		frames[pos] = pages[i];
	    		time[pos] = counter;
	    	}
		
		printf("%d\t", pages[i]);	
	    	
	    	for(j = 0; j < framesnum; ++j){
	    		printf("%d ", frames[j]);
	    	}
	    	
	    	printf("\n");
	
 	}
	
    	printf("\nTotal Page Faults = %d", faults);
}

int main()
{
  int framesnum, pagenum, frames[10], pages[30],ch,rep=1;
	printf("Enter number of frames: ");
	scanf("%d", &framesnum);
	
	printf("Enter number of pages: ");
	scanf("%d", &pagenum);
	
	printf("Enter reference string: ");
	
    	for(int i = 0; i < pagenum; ++i){
    		scanf("%d", &pages[i]);
    	}
    	
    	do {
    		printf("\n1.FIFO\n2.LRU\n3.Enter your choice-\n");
    		scanf("%d",&ch);
    		switch(ch)
    		{
    			case 1:
    				FIFO(pages,frames,pagenum,framesnum);
    				break;
    				
    			case 2:
    				LRU(pages,frames,pagenum,framesnum);
    				break;
    				
    			case 3:
    				printf("Invalid Choice\n");
    				
    		}
    		printf("\n\nPress 1 to continue and 0 to exit- ");
    		scanf("%d",&rep);
    	}
    	while(rep==1);
    
    
    return 0;
}
