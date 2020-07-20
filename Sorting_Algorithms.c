// Theo b

#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//function initilization
int initN(); // memory allocation
void initValues(int );
void insertionSort(int );
void swap(int *, int *);
void selectionSort(int [], int );
void bubbleSort(int [], int );
void merge_sort(int  , int );
void merge(int , int , int );
void qsswap(int , int );// swaps table values
void quickSort(int , int );
int menu ();
void printArray(int [],int );


//global variables
int *pinakas,*pinakas2;// tables
double tmp_elapsed=0,elapsed=0; // variables that will help us calculate the elapsed time
unsigned long counter=0,merge_counter=0,quicksort_counter=0; //non negative counters 
clock_t start, end; // variables that initiate and finalize the time frame
int main()
{
       int choice= menu();// bring up the menu 
       if (choice==6)// if the choice is 6 then the program exits
       {
       return 0;//exits
       }

 int N,i;
    srand(time(NULL));// changes the random values for every time tick 
    ///-----------------------------------------------------------------------1.Insertion Sort
    if (choice==1)
    {



    N=initN();//  allocates memory for the table 
  for(i=0; i<50; i++)
    {
        initValues(N);// initializes the table values 

        start=clock();//starts counting elapsed time 
        insertionSort(N);// executes the search 
        end=clock(); // end of counting elapsed time 

        tmp_elapsed=((double) (end - start));
        elapsed=elapsed+tmp_elapsed;//total time for the 50 loops 
    }

     printf("\n Total time of Insertion-Sort: %f ms \n  Average time of  Insertion-Sort: %f ms",elapsed ,elapsed/50 );

    printf("\n Total time of Insertion-Sort: %d \n Average comparison time of  Insertion-Sort: %d",counter,counter/50);



    }else if (choice==2)///-----------------------------------------------------------------------2.Selection Sort
{

        N=initN();//  initializes the table values
    for(i=0; i<50; i++)
    {
        initValues(N);
        start=clock();//starts counting elapsed time
        selectionSort( pinakas,  N);
        end=clock();//ends counting elapsed time
            tmp_elapsed=((double) (end - start));
        elapsed=elapsed+tmp_elapsed;//total time of 50 loops

    }
     printf("\n Total time Selection-Sort: %f ms \n  Average time of Selection-Sort: %f ms",elapsed ,elapsed/50 );

    printf("\n Total  comparison time of Selection-Sort: %d \n Average comparison time of  Selection-Sort: %d",counter,counter/50);

}else if (choice==3)///-----------------------------------------------------------------------3.BubbleSort
{
     N=initN();//  Allocates memory for the table

 for(i=0; i<50; i++)
    {
      initValues(N);
        start=clock();//starts counting elapsed time

    bubbleSort(pinakas,N);
    end=clock();//stops counting elapsed time
            tmp_elapsed=((double) (end - start));
        elapsed=elapsed+tmp_elapsed;//Total time of 50 loops
    }

printf("\n Total time of Bubble-Sort: %f ms \n  Average time of Bubble-Sort: %f ms",elapsed ,elapsed/50 );

    printf("\n Total amount of comparisons for Bubble-Sort: %d \n Average amount of comparisons of Bubble-Sort: %d",counter,counter/50);



 //end of bubblesort
}else if (choice==4)///-----------------------------------------------------------------------4. Merge Sort
{
 pinakas2=(int *)malloc(N*sizeof(int));// allocating memory for the 2nd table that were gonna merge 

 N=initN();
 for(i=0; i<50; i++)
    {
 initValues(N);
        start=clock();//starts counting elapsed time

        merge_sort(0, N-1);

end=clock();//stops counting elapsed time

            tmp_elapsed=((double) (end - start));
        elapsed=elapsed+tmp_elapsed;//Total time of 50 loops
    }


printf("\n Total time of Merge-Sort: %f ms \n  Average time of Merge-Sort: %f ms",elapsed ,elapsed/50 );

    printf("\n Total amount of comparisons in Merge-Sort: %d \n Average amount of comparisons of Merge-Sort: %d",merge_counter,merge_counter/50);

}else if (choice==5){///-----------------------------------------------------------------------5. QuickSort

  N=initN();//  Allocates memory for the table

 for(i=0; i<50; i++)
    {
      initValues(N);
        start=clock();//starts counting elapsed time

    quickSort(0,N-1);
    end=clock();//stops counting elapsed time
            tmp_elapsed=((double) (end - start));
        elapsed=elapsed+tmp_elapsed;//Total time of 50 loops
    }

printf("\n Total time of QuickSort: %f ms \n  Average time of QuickSort: %f ms",elapsed ,elapsed/50 );

    printf("\n Total amount of comparisons in Quicksort: %d \n Average amount of comparisons of Quicksort: %d",quicksort_counter,quicksort_counter/50);




}






}
//------------------------------------------------Table Initialization ------------------------------------
int initN()
{
    int N=0;

    printf("Please insert the size of the table  ! \n");
    scanf("%d",&N);
    pinakas=(int *)malloc(N*sizeof(int)); // allocates memory and returns the size of the table 
    return N;
}
void initValues(int N) // gives random values  (0-50000) to the table 
{
    int i=0;

    for(i=0; i<N; i++)
    {
        pinakas[i]=rand() % 50001;//gives value of  1  to 50.000


    }
}
//------------------------------------------------ INSERTION SORT------------------------------------------
void insertionSort(int N)// execution of insertion sort
{

    int key,i,j;

    for(i=1; i<N; i++)
    {
        key=pinakas[i];

        for(j=i-1; j>-1; j--)/// goes through the table from left to right and starts from i-1 
        {
            if(j>-1&&key>pinakas[j])//left shift of table 
            {
                pinakas[j+1]=pinakas[j];


                counter++; // increasing the counter by one 

            }
            else //if the statement above is false then if has found the optimal spot and stops the loop 
            {
                break;
            }
        }
        pinakas[j+1]=key;//puts the value where it is supposed to be 
    }
}
//---------------------------------Selection Sort--------------------------------------------------------

void selectionSort(int pinakas[], int N)
{

    int i, j,min;


    for (i = 0; i < N-1; i++)
    {


        min = i;
        for (j = i+1; j < N; j++) // loop that finds the smallest number 
        {
            counter++;
            if (pinakas[j] < pinakas[min])
            {
                min = j;
            }

        }


        swap(&pinakas[min], &pinakas[i]);///places the smallest element at the start of the table 

    }
}









//--------------------------------------BUBBLE SORT ------------------------------------------------------
void swap(int *a, int *b) // swapping values 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int pinakas[], int N)
{
    int i, j;
    for (i = 0; i < N-1; i++)
    {




        for (j = 0; j < N-(i-1); j++)
        {
                counter++;
            if (pinakas[j] > pinakas[j+1])///puts 2 elements in a bubble and if theyre in the wrong order then they swap positions 
            {
                swap(&pinakas[j], &pinakas[j+1]);
            }

        }
    }

}
//-------------------------------Merge Sort--------------------------------------------
void merge_sort(int left , int right)
{
    int middle;

    if(left < right) //splits the table in smaller parts and then combines them  
    {
      middle = (left + right) / 2;
     merge_sort(left, middle);
     merge_sort(middle+1, right);
      merge(left, middle, right);
   }
   else
   {
      return;
   }
}



void merge(int left, int middle, int right)
{
    int k1,k2,i; // k1 and k2 are counters 

   for(k1 = left, k2 = middle + 1, i = left; k1 <= middle && k2 <= right; i++) ///starts at the start and from the middle of the table simultaneously 
   {
      merge_counter++;
      if(pinakas[k1] > pinakas[k2])
      {
          pinakas2[i] = pinakas[k1++];// puts the value of pinakas[k1] in the pinaka2 table and increases k1 by one  
      }
      else
      {
          pinakas2[i] = pinakas[k2++];
      }
   }

   while(k1 <= middle) // while k1 hasn't reached the middle of the table 
   {
     pinakas2[i++] = pinakas[k1++];
   }

   while(k2 <= right) // while k2 hasn't reached the end of the table 
   {
     pinakas2[i++] = pinakas[k2++];
   }

   for(i = left; i <= right; i++)
   {
     pinakas[i] = pinakas2[i];
   }
}




//-------------------------------Quick sort---------------------------------------------


int section(int left, int right, int pivot) 
{
    int l=left-1;
    int r=right;

    while(1)
    {

          while(r>0 && pinakas[--r]<pivot)
        {
            // finds the element that is smaller than pivot 

        }
        while(pinakas[++l]>pivot)
        {
            // finds the element that is bigger than pivot 

        }



        quicksort_counter++;

        if(l >= r)
        {
            // if the elements are valid valid
            break;//exits the loop 
        }
        else
        {
            qsswap(l,r);//swaps 2 elements 
        }
    }
    //pivot swap 
    qsswap(l,right);
    //returns new pivot 
    return l;
}

void qsswap(int a, int b)
{
    int tmp_val=pinakas[a];
    pinakas[a]=pinakas[b];
    pinakas[b]=tmp_val;
}

void quickSort(int left, int right)
{
    if(right-left<=0)// if the condition is true then the table is sorted 
    {
        return;
    }
    else
    {
        int pivot=pinakas[right];
        int new_pivot=section(left, right, pivot);
        quickSort(left,new_pivot-1); // recursive
        quickSort(new_pivot+1,right);
    }
}
/*void printArray(int pinakas[],int N) // 
{
    int i;
    for (i=0;i<N;i++)
    {
      printf("%d ",pinakas[i])  ;
    }
    printf("\n ")  ;
    }
*/

int menu (){ // Menu Function that returns which option the user picked 
printf("Please pick an option ! \n1. Insertion Sort \n2. Selection Sort \n3.Bubble Sort \n4. Merge Sort \n5. Quick Sort \n6. EXIT \n");
int choice;
do{
scanf("%d",&choice);// reads choice 

if (choice<1 || choice >6) // check if the choice is valid 
{
    printf("Please insert a valid option ! \n \n1. Insertion Sort \n2. Selection Sort \n3.Bubble Sort \n4. Merge Sort \n5. Quick Sort \n6. EXIT \n "); 
}
}while (choice<1 || choice >6);




return choice;
}




