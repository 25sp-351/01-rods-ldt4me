#include <stdio.h>
#include <stdlib.h>

// Piece struct
typedef struct {
    int length;
    int price;
} Piece;

Piece *ratios = NULL; // Fix the ratios array declaration

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Cutting the rod
int cut(int og_length, int cut_length, Piece *prices, int n) {
    if (cut_length == 0 || og_length == 0) {
        return 0;
    }
    if (prices[cut_length - 1].length > og_length) {
        return cut(og_length, cut_length - 1, prices, n);
    }
    return max(prices[cut_length - 1].price + cut(og_length - prices[cut_length - 1].length, cut_length, prices, n),
               cut(og_length, cut_length - 1, prices, n));
}

// Max ratio function
float ratio(Piece *ratios, int n) {
    float max_ratio = 0.0;
    for (int i = 0; i < n; i++) {
        float current_ratio = (float)ratios[i].price / ratios[i].length;
        if (current_ratio > max_ratio) {
            max_ratio = current_ratio;
        }
    }
    return max_ratio;
}

/*
1. find the prices of each length
    - create a struct that has the length and price
    - create an array of the struct
    - sort the array by price
2. figure out the most valuable way to cut (can be different lengths together that maximize value)
    - create function that compares lengths and prices
        - determine which has the best ratio of price to length
        - if the ratio is the same, choose the shorter length if you can have multiple of that length, otherwise choose the longer length
3. cut the rod
    - create a function that takes in the original length and the cut length
    - recursively cut the rod
        - if the original length is 0, return 0
        - if the length of the piece is greater than the original length, return the function with the cut length - 1
        - return the end price of the rod after being cut and the size of peices it was cut into.

i guess 2 and 3 could be one because i could have the function that cuts the rod also determine the best way. 
maybe it is just easier to read the former.
*/
