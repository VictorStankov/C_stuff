#include <stdio.h>
#include <stdlib.h>

void createFile();
void countEvensOdds();
void outputToText();
void sortArray(int arr[], int N);

int main()
{
	createFile();
	countEvensOdds();
	outputToText();
	return 0;
}

void createFile()
{
    int N, input;

    FILE* file = fopen("2.bin", "wb");
    if(file == NULL)
        exit(1);

    scanf("%d", &N);
    fwrite(&N, sizeof(int), 1, file);
    for(N; N>0; --N)
    {
        scanf("%d", &input);
        fwrite(&input, sizeof(int), 1, file);
    }
    fclose(file);
}

void countEvensOdds()
{
    int number, even=0, odd=0, arr[100];
    FILE* file = fopen("2.bin", "rb");
    if(file == NULL)
        exit(1);
    while(fread(&number, sizeof(int), 1, file) == 1)
    {
            if(number == EOF)
                break;
            if(number%2 == 0)
                even++;
            else odd++;
    }
    fclose(file);
    printf("Even numbers: %d\t Odd numbers: %d\n", even, odd);
}

void outputToText()
{
    int N, number, arr[1000], i=0;

    FILE* file_read = fopen("2.bin", "rb");
    if(file_read == NULL)
        exit(1);
    FILE* file_write = fopen("2.txt", "w");
    if(file_write == NULL)
        exit(2);

    while(fread(&number, sizeof(int), 1, file_read) == 1)
    {
        arr[i] = number;
        ++i;
    }

    N = i;
    sortArray(arr, N);

	for(i=0; i<N; ++i)
        fprintf(file_write, i==N-1 ? "%d" : "%d, ", arr[i]);

    fclose(file_read);
    fclose(file_write);
}

void sortArray(int arr[], int N)
{
    for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(arr[j] > arr[i])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
