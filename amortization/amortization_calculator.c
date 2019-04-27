/*
 * amortization_calculator.c
 *
 *  Created on: Jan 20, 2019
 *      Author: tommoody
 */
#include <stdio.h>
#include <math.h>
#include "amortization.h"
#include <stdlib.h>

/* payments [x][0] will be beginning principle
 * [x][1] will be interest payment
 * [x][2] will be principle payment
 *  */
double **payments;

void amortization(double initial_amount, int number_of_payments, double interest_rate){

	double monthly_payment;
	monthly_payment = calculate_monthly_payment(initial_amount, number_of_payments, interest_rate);
	double first_interest_payment;
	first_interest_payment = initial_amount * ((interest_rate/100)/12);
	printf("Payment:%f\tFirst Interest:%f\n",monthly_payment, first_interest_payment);

	double current_principle;
	current_principle = initial_amount;
	//This dynamically allocates the array based on the number of payments.
	payments = malloc(number_of_payments * sizeof(double *));

	for(int i = 0; i < number_of_payments; i++)
	{
		payments[i] = malloc(3 * sizeof(double));

	}

	for(int i = 0; i< number_of_payments; i++)
	{
		payments[i][0] = current_principle;
		payments[i][1] = current_principle * ((interest_rate/100)/12);
		payments[i][2] = monthly_payment - payments[i][1];
		current_principle = current_principle - payments[i][2];
	}


}

double calculate_monthly_payment(double initial_amount, int number_of_payments, double interest_rate){
	double monthly_payment;
	monthly_payment = 0.00;
	double monthly_rate;
	monthly_rate = (interest_rate/100)/12;
	double numerator;
	numerator = initial_amount*pow((1+monthly_rate),number_of_payments)*monthly_rate;
	double denominator;
	denominator = pow((1+monthly_rate),number_of_payments)-1;
	monthly_payment = numerator/denominator;

	return monthly_payment;
}

void print_amortization(int number_of_payments){

	for(int i = 0; i < number_of_payments;i++){
		printf("Loan Amount:%.2f\tInterest Payment:%.2f\tPriciple Payment:%.2f\n",payments[i][0], payments[i][1],payments[i][2]);
	}


}
