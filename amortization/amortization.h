/*
 * amortization.h
 *
 *  Created on: Jan 20, 2019
 *      Author: tommoody
 */

#ifndef AMORTIZATION_H_
#define AMORTIZATION_H_


void amortization(double initial_amount, int number_of_payments, double interest_rate);
void print_amortization();
double calculate_monthly_payment(double initial_amount, int number_of_payments, double interest_rate);



#endif /* AMORTIZATION_H_ */
