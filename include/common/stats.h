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
 * @file <Add stats.h> 
 * @brief <Add header for statistics program >
 *
 * <Add First assignment for embedded processing>
 *
 * @author <Add Patrick Fitzgerald>
 * @date <Add 2019/06/16 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
/* more details on functions provided in stats.c */
// @brief - takes input char array and produces sorted output, largest to smallest
// integer is the length of the array
unsigned char * sort_array(unsigned char *, int);


// @brief first element of sorted array is already largest
// char casts to int
int find_maximum(unsigned char *);


// @brief last element is smallest
// needs int input of length of the array, SIZE parameter
int find_minimum(unsigned char *, int);


// @brief add all the char elements of the array and produce int sum, divide by int number of elements
// float from dividing two integer-like types
float find_mean(unsigned char *, int);


// @brief integer add all the unique elements and divide integer by number of unique elements, float
// 
float find_median(unsigned char *, int);


// @brief print the elements of the char array with nice spacing, framing
// function needs the character array input and integer SIZE for how many members or elements
void print_array(unsigned char *, int);


// @brief print the output statistics in a nice format

void print_statistics(int, int, float, float);


/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */


#endif /* __STATS_H__ */
