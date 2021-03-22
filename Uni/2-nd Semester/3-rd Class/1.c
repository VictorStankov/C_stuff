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

    FILE* file = fopen("1.bin", "wb");
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
    int N, number, even=0, odd=0;
    FILE* file = fopen("1.bin", "rb");
    if(file == NULL)
        exit(1);
    fread(&N, sizeof(int), 1, file);
    for(N; N>0; --N)
    {
        fread(&number, sizeof(int), 1, file);
        if(number%2 == 0)
            even++;
        else odd++;
    }
    fclose(file);
    printf("Even numbers: %d\t Odd numbers: %d\n", even, odd);
}

void outputToText()
{
    int N, number;

    FILE* file_read = fopen("1.bin", "rb");
    if(file_read == NULL)
        exit(1);
    FILE* file_write = fopen("1.txt", "w");
    if(file_write == NULL)
        exit(2);

    fread(&N, sizeof(int), 1, file_read);
    int arr[N];

    fread(arr, sizeof(int), N, file_read);

    sortArray(arr, N);

	for(int i=0; i<N; ++i)
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
