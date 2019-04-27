/*
 * main.c
 *
 *  Created on: Jan 20, 2019
 *      Author: tommoody
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "amortization.h"

int main(int argc, char **argv){

	if(argc >1){

	double loan_amount;
	loan_amount = atof(argv[1]);
	int number_of_payments;
	number_of_payments = atof(argv[2]);
	double interest_rate;
	interest_rate = atof(argv[3]);

	amortization(loan_amount, number_of_payments,interest_rate);

	print_amortization(number_of_payments);
	}

}
