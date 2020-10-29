/**** this program reads numbers from a file and computes average, maximum value, and puts them in an output file ****/
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *numbers; // numbers array
    int size, i, sum, max;
    double avg;
    i = max = sum = 0;

    FILE *inputFile = fopen("integers.txt", "r");    // input file
    FILE *outFile   = fopen("answer-hw3.txt", "w");   // output file

    fscanf(inputFile, "%d", &size);   // reading the size of the array

    numbers = malloc(size * sizeof(int));   // allocating memory for the array

    while(fscanf(inputFile,"%d", &numbers[i]) == 1)   // reading the rest of the numbers
    {
        sum += numbers[i];           // calculating running sum and max value
        if (max < numbers[i])
        {
            max = numbers[i];
        }
        i++;
    }

    avg = (double)sum / i;

    printf("Average is : %lf\n", avg);
    printf("Max is : %d\n", max);

    fprintf(outFile, "Average is : %lf\n", avg);
    fprintf(outFile, "Max is : %d\n", max);

    fclose(inputFile);  // closing both files
    fclose(outFile);

    return 0;
}
