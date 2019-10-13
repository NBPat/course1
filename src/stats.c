/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add stats.c> 
 * @brief <Add statistic program >
 *
 * <Add First assignment for embedded processing >
 *
 * @author <Add Patrick Fitzgerald>
 * @date <Add 2019-06-16 >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {
// original array will be overwritten by sorted array
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

  float median;  //sum of all elements/number int divided by int generates float
  float mean;    //sum of unique elements/quantity int/int generates float
  int maximum;   //1st element of sorted array.  char values from test[i] cast to int
  int minimum;   //last element of sorted array.  casts to int

  /* Statistics and Printing Functions Go Here, declarations */
  // print_array is used to show array before and after sorting
    
    printf("\nInput Array:\n");
    print_array(test, SIZE);
    sort_array(test, SIZE);
    printf("\nSorted Array:\n");
    print_array(test, SIZE);

  // generation of statistics
    maximum = find_maximum(test);
    minimum = find_minimum(test, SIZE);
    mean = find_mean(test, SIZE);
    median = find_median(test, SIZE);

  // printing of statistics
    print_statistics(maximum, minimum, mean, median);

}

/* Add other Implementation File Code Here */

// bubble sort.  Each value is compared its neighbour.  
// the lower of the two is placed further down the array
// the input array is input as unsigned character type
// the return is also an array of the same type
//
unsigned char * sort_array(unsigned char * local, int localSize) {
  for (int i = 0; i < localSize-1; i++) //for all members of the array
  {for (int j = 0; j < localSize -i -1; j++)
  if (local[j] < local[j+1])
	  {
	  int swap = local[j];
	  local[j] = local[j+1];
	  local[j+1] = swap;
	  }}return local;}


// in the sorted array, the maximum will be the first element

int find_maximum(unsigned char * local) {
	return local[0];
}

// in the sorted array, the minimum will be the last element
// the car casts to integer
int find_minimum(unsigned char * local, int localSize) {
  return local[localSize-1];
}

// the mean is the average, the total of all elements
// divided by the number of elements
float find_mean(unsigned char * local, int localSize) {
	int total = 0; 
	for (int i = 0; i <localSize ; i++) {
		total = total + local[i];}
	float mean = total/localSize;
	return mean;}


// the median is the sum of the unique elements of the array
// divided by the count of unique elements
float find_median(unsigned char * local, int localSize) {
	int total = 0; int count = 0;
	for (int i = 0; i < localSize ; i++) {
		if (local[i] > local[i+1]) {total = total + local[i]; count++;}
	}
	float median = total/count;
	return median;}

// print_array
void print_array(unsigned char * local, int localSize) {
for (int i = 0; i < localSize; i++) {printf("element %d:  %d\n", i, local[i]);}
}

// print_statistics
void print_statistics(int maxVal, int minVal, float meanVal, float medianVal) {
	printf("\nStatistics for array:\n");
	printf("Maximum:  %d  Minimum:  %d  Mean:  %6.2f  Median:  %6.2f  \n", maxVal, minVal, meanVal, medianVal);}


