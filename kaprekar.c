#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void swap (int* i, int* j);

int main (int argc, char * argv[]) {
	int i,j;
	int input_array[4];
	int total_iterations=0;
	int tmp_swap;
	int highest_lowest[4], lowest_highest[4];
	int high_low, low_high;
	int result;

	if (argc != 2){
		printf("usage kaprekar <4digit number>\n");
		return 1;
	}


	input_array[0] = atoi(argv[1]) % 10; //one's place Ex. 4

	input_array[1] = atoi(argv[1]) % 100; //ten's place Ex. 34		input_array[1] = input_array[1] - input_array[0]; //subtract ones place from tens place Ex. 34 - 4
	input_array[1] = input_array[1] / 10; //Ex. 30 / 10 = 3

	input_array[2] = atoi(argv[1]) % 1000;//thousandths place Ex. 234
	input_array[2] = input_array[2] - input_array[1] -input_array[0];// Ex. 234 - 30 - 4 = 200
	input_array[2] = input_array[2] / 100;

	input_array[3] = atoi(argv[1]) % 10000;//tenthousanth's place Ex. 1234
		printf("starting number: %d\n",input_array[3]);
	input_array[3] = input_array[3] - input_array[2] - input_array[1] - input_array[0];//Ex. 1234 - 200 -30 -4 = 1000
	input_array[3] = input_array[3] / 1000;

		for(i=0; i < 4; i++){ 
			for(j=0 ; j < 4 ; j++){
				if(input_array[i] == input_array[j]){
					if(i != j){
						printf("Not a valid starting number!\n digit #%d value %d of input is same as digit %d value %d!\n", i+1, input_array[i], j+1, input_array[j]);
						printf("Please enter a 4 digit number with all unique digits! Ex:1234 NOT 1111\n");
						return 1;
					}
				}
			}
		}

	while(1){
		//Ex 1234

		// printf("%d\n",input_array[0]);
		// printf("%d\n",input_array[1]);
		// printf("%d\n",input_array[2]);
		// printf("%d\n",input_array[3]);




		//sort digits highest to lowest

		for(i=0; i < 4; i++){ 
			for(j=0 ; j < 4 ; j++){
					if(input_array[i] > input_array[j]){
						swap(&input_array[i],&input_array[j]);
					}
			}
		}

		// printf("%d\n",input_array[0]);
		// printf("%d\n",input_array[1]);
		// printf("%d\n",input_array[2]);
		// printf("%d\n",input_array[3]);

		for(i=0; i <4; i++) highest_lowest[i] = input_array[i];

		// printf("%d\n",highest_lowest[0]);
		// printf("%d\n",highest_lowest[1]);
		// printf("%d\n",highest_lowest[2]);
		// printf("%d\n",highest_lowest[3]);

		for(i=0; i < 4; i++){ 
			for(j=0 ; j < 4 ; j++){
					if(input_array[i] < input_array[j]){
						swap(&input_array[i],&input_array[j]);
					}
			}
		}	


		for(i=0; i <4; i++) lowest_highest[i] = input_array[i];

		high_low = (highest_lowest[0] * 1000) + (highest_lowest[1] * 100) + (highest_lowest[2] * 10) + highest_lowest[3];
		printf("sorted highest to lowest: %d\n", high_low);
		low_high = (lowest_highest[0] * 1000) + (lowest_highest[1] * 100) + (lowest_highest[2] * 10) + lowest_highest[3];
		printf("sorted lowest to highest: %d\n", low_high);

		result = high_low - low_high;
		printf("%d - %d = %d\n", high_low, low_high, result);
		total_iterations++;
		if (result == 6174 || total_iterations == 50){
			printf("total iterations to 6174: %d\n\n",total_iterations);
			break;
		}


		input_array[3] = result % 10; //Ex 1234 % 10 = 4

		input_array[2] = result % 100; //ten's place Ex. 1234 % 100 = 34
		input_array[2] = input_array[2] - input_array[3]; //subtract ones place from tens place Ex. 34 - 4
		input_array[2] = input_array[2] / 10; //Ex. 30 / 10 = 3

		input_array[1] = result % 1000;//thousandths place Ex. 234
		input_array[1] = input_array[1] - input_array[2] -input_array[3];// Ex. 234 - 30 - 4 = 200
		input_array[1] = input_array[1] / 100;

		input_array[0] = result % 10000;//tenthousanth's place Ex. 01234 % 10000 = 1234
		input_array[0] = input_array[0] - input_array[1] - input_array[2] - input_array[3];//Ex. 1234 - 200 -30 -4 = 1000
		input_array[0] = input_array[0] / 1000;

		printf("result:%d\n---------------\n", high_low - low_high);

		// printf("%d\n",lowest_highest[0]);
		// printf("%d\n",lowest_highest[1]);
		// printf("%d\n",lowest_highest[2]);
		// printf("%d\n",lowest_highest[3]);

		// printf("%d\n",input_array[0]);
		// printf("%d\n",input_array[1]);
		// printf("%d\n",input_array[2]);
		// printf("%d\n",input_array[3]);
	}
	return 0;
}

void swap (int* i, int* j){
	int tmp;
	tmp = *i;
	*i = *j;
	*j = tmp;
}