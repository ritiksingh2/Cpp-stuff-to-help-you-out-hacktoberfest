#include<iostream>
using namespace std;
const int n=7;

class work
{
public:
	char jobname;
	int Deadline;
	int profit;
};

void Print_work_list(work work_list[n], int size=n)
{
	cout<<"jobname     =    ";
	for(int i=0;i<size;i++)
		cout<<work_list[i].jobname<<"     ";
	cout<<"\nDeadline    =    ";
	for(int i=0;i<size;i++)
		cout<<work_list[i].Deadline<<"     ";
	cout<<"\nprofit      =    ";
	for(int i=0;i<size;i++)
		cout<<work_list[i].profit<<"    ";	
}
int max_deadline(work arr[n])		//Linear Search
{
	int max = arr[0].Deadline;
	for(int i=1;i<n;i++)
		if(arr[i].Deadline > max)
			max = arr[i].Deadline;
	return max;	
}
int sort(work work_list[n]) {			//Bubble sort
	int i, j, max_idx;  
    for (i = 0; i < n-1; i++)  
    {   
        max_idx = i;  
        for (j = i+1; j < n; j++)  
	        if (work_list[j].profit > work_list[max_idx].profit)  
	            max_idx = j;  
		swap(work_list[i],work_list[max_idx]);
    } 	
}

int main()
{
	int i;
	work work_list[] = { {'A',2,60}, {'B',1,80}, {'C',4,20}, {'D',2,40}, {'E',1,20}, {'F',4,2}, {'G',2,50} };
	
	cout<<"	GIVEN INPUT		\n";
	Print_work_list(work_list);		
	cout<<"\n\n\n";
	
	sort(work_list);
	cout<<" AFTER SORTING PROFIT IN DECREASING ORDER \n";
	Print_work_list(work_list);		
	cout<<"\n\n\n";
	
	//search for max deadline
	int size = max_deadline(work_list);
	work output_arry[size] ;
	for(int i=0;i<size;i++)
		output_arry[i].profit = 0;

	//distribute work
	for(i=0;i<n;i++)
	{
		int index = (work_list[i].Deadline)-1;
		while(index >= 0)
		{	
			if(output_arry[index].profit==0)
			{	output_arry[index] = work_list[i];
				break;
			}
			else
				index--;
		}
	}

	cout<<" sequence of work name should we do  :  "	;
	for(i=0;i<size;i++)
		cout<<output_arry[i].jobname<<"  ->  ";
		
	cout<<"\n\n\n       REQUIRED TABLE   \n";
	Print_work_list(output_arry,size);	
	cout<<"\n\n";
	return 0;
}

