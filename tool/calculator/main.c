#include <stdio.h>
#define no_of_bits 16
int input();
void output(float);
int SIZE = 12;

// methods section

void convertAndAdd(int input1, int input2){

	int decimal1[no_of_bits] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	int decimal2[no_of_bits] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	int output[no_of_bits] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	int temp = input1;
	int index = no_of_bits-1; // 15
	while(temp > 0){
		decimal1[index] = temp % 2;
		temp /= 2;
		index--;
	}
	for (int i = 0; i < no_of_bits; i++){
		printf("%d ", decimal1[i]);
	}
	printf("\n");
	temp = input2;
	index = no_of_bits-1; // 15
	while(temp > 0){
		decimal2[index] = temp % 2;
		temp /= 2;
		index--;
	}
	for (int i = 0; i < no_of_bits; i++){
		printf("%d ", decimal2[i]);
	}
	printf("\n");

	int carry =0;
	// for loop for the add operator
	for (int i = no_of_bits-1; i >= 0; i--){
		if (decimal1[i] == 0 && decimal2[i] == 0 && carry == 0){
		output[i] = 0;
		carry = 0;
		}
		else if (decimal1[i] == 0 && decimal2[i] == 0 && carry == 1){
		output[i] = 1;
		carry = 0;
		}
		else if (decimal1[i] == 0 && decimal2[i] == 1 && carry == 0){
		output[i] = 1;
		carry = 0;
		}
		else if (decimal1[i] == 0 && decimal2[i] == 1 && carry == 1){
		output[i] = 0;
		carry = 1;
		}
		else if (decimal1[i] == 1 && decimal2[i] == 0 && carry == 0){
		output[i] = 1;
		carry = 0;
		}
		else if (decimal1[i] == 1 && decimal2[i] == 0 && carry == 1){
		output[i] = 0;
		carry = 1;
		}
		else if (decimal1[i] == 1 && decimal2[i] == 1 && carry == 0){
		output[i] = 0;
		carry = 1;
		}
		else if (decimal1[i] == 1 && decimal2[i] == 1 && carry == 1){
		output[i] = 1;
		carry = 1;
		}
	}

	for (int i= 0;i<no_of_bits;i++ ){
		printf("%d\t",output[i] );
	}
}

void output(float number)
{
    printf("%f", number);
}

int add(input1, input2) {
  float result = 0;
  int temp1 = input1;
  int temp2 = input2;
  
  while (temp2 != 0) {
      int holder = temp1 & temp2; 
      temp1 = temp1 ^ temp2;
      temp2 = holder << 1;
    }
    result = temp1;
    return result;
}

float subtraction(int input1, int input2) {
  float result = 0;
  int temp1 = input1;
  int temp2 = input2;
  
  while (input2 != 0) {
    int x = (~temp1) & temp2;
 
    temp1 = temp1 ^ temp2;
    temp2 = x << 1;
  }
    result = temp1;
    return result;
}

float multiplication(int input1, int input2) {
  int temp = input1;
  int count = 1;
  float result = 0;
  while (count != input2) {
    temp = add(temp, input1);
     count = add(count, 1);
  }
  result = temp;
  return result;
}

float division(int input1, int input2) {
  float result = 0;
  int temp1 = input1;
  int temp2 = input2;
  int count = 1;
  while (temp1 > temp2) {
    temp1 = subtraction(temp1, temp2);
    count = add(count, 1);

  }
  result = count;
  return result;
}

float modulo(int input1) {
  float result = 0;
  int temp1 = input1;
  result = temp1 & 3;
  return result;
}
float logarithm(int input1, int input2){
  int temp1 = input1;
  int temp2 = input2;
  float result = 0;
  double difference;
  while(temp1!= 1){
         temp1 = division(temp1, temp2);
        result = add(result, 1);;
      }
      if(difference == 1)
          printf("");
          printf("Result of ");
          printf("log");
          printf("%d(", input1);
          printf("%d)", input2);
          printf(": ");
  return result;
}

float exponent(input1, input2) {
  int temp1 = input1;
  int temp2 = input2;
  float result = input1;
  int count = temp2;
  if(temp2 != 0) {
    while(count != 1) {
      result = multiplication(result, temp1);
      count = subtraction(count, 1);
    }
  } else {
      result = 1;
  }
  printf("Result of ");
  printf("%d ", input1);
  printf("to the ");
  printf("%d power: ", input2);
  return result;
}
// menu and switch statement
int main()
{
    float result;
    int choice, num, num1, num2;
    int input1 = 0, input2 = 0, res = 0;
    printf("\t\t\t\tSCIENTIFIC CALCULATOR\n");
    printf("---------------------------------------------------------\n");
    printf("\tPress 1 to calculate the sum of two numbers\n");
    printf("\tPress 2 to calculate the subtraction of two numbers\n");
    printf("\tPress 3 to calculate multiplication of two numbers\n");
    printf("\tPress 4 to calculate division of two evenly divisible numbers\n");
    printf("\tPress 5 to calculate a log\n");
    printf("\tPress 6 to calculate an exponent\n");
    printf("\tpress 7 to calculate N Mod 4\n\n");
    printf("Enter your choice:\t");
    choice = input();
      
    switch (choice) {
    case 1: { // addition
        printf("Enter number:\n");
        input1 = input();
        input2 = input();
        result = add(input1, input2);
        output(result);
        break;
    }
    case 2: { // subtraction
        printf("Enter number:\n");
        input1 = input();
        input2 = input();
        result = subtraction(input1, input2);
        output(result);
        break;
    }
    case 3: { // multiplication
        printf("Enter number:\n");
        input1 = input();
        input2 = input();
        result = multiplication(input1, input2);
        printf("Multiplication: ");
        output(result);
        break;
    }
    case 4: { // division
        printf("Enter number:\n");
        input1 = input();
        input2 = input();
        result = division(input1, input2);
        printf("Division: ");
        output(result);
        break;
    }
    case 5: { // logarithm
      printf("Enter log number:\n");
      num1 = input();
      printf("Enter base number:\n");
      num2 = input();
      result = logarithm(num1, num2);
        output(result);
        break;
    }
    case 6: { // exponent
      printf("Enter base number:\n");
      num1 = input();
      printf("Enter exponent number:\n");
      num2 = input();
      result = exponent(num1, num2);
      output(result);
      break;

    }
    case 7: { // mod 4
      printf("Enter base number:\n");
      num1 = input();
      int result = modulo(num1);
      printf("Result of ");
      printf("%d ", num1);
      printf("Mod 4 is: ");
      printf("%d", result);

      break;
    }
      default:
        printf("wrong input\n");
  }
    return 0;
}
int input()
{
    int number;
    scanf("%d", &number);
    return (number);
}
