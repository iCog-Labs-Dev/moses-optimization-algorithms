#include <iostream>
#include <array>
#include <math.h>
#include <random>
#include "hill_climbing.h"

double calculate_cost(double x_val,double arr[], int arr_length){
    int data = 1;
    double total = 0;
    for(int i = 0; i < arr_length; i++){
        total+= arr[i]*(pow(x_val,i));
    }
    return total;
}
inline double decrease_x(double x){
    return x + 0.01;
}
inline double increase_x(double x){
    return x - 0.01;
}

double * calculate_hill_climbing(double result, double arr[],double arr_length){
    /*
    This is a hill climbing algorithm that evaluates improved state values
    based on a state function
    */
    double nbhr = increase_x(result);
    double nbhl = decrease_x(result);
    double cost_res = calculate_cost(result,arr,arr_length);
    double cost_nbhr = calculate_cost(nbhr,arr,arr_length);
    double cost_nbhl = calculate_cost(nbhl,arr,arr_length);
    static double fin_output[2];
    do{
        std::cout << "this is printed" << std::endl; //debugging
        if(cost_nbhr >= cost_nbhl){
            result = nbhr;
        }else{
            result = nbhl;
        }
        nbhr = increase_x(result);
        nbhl = decrease_x(result);
        cost_res = calculate_cost(result,arr,arr_length);
        cost_nbhr = calculate_cost(nbhr,arr,arr_length);
        cost_nbhl = calculate_cost(nbhl, arr,arr_length);

    }while(cost_nbhr < cost_res || cost_nbhl < cost_res);
    fin_output[0] = result;
    fin_output[1] = cost_res;
    return fin_output;
}

int main(){
   
    double inp_func[] = {1.5,2.3,4,1};
    double *x = calculate_hill_climbing(6,inp_func,sizeof(inp_func) / sizeof(inp_func[0]));
    std::cout << "The value is of x is: "<<x[0] << std::endl;
    std::cout << "The value of the output is:" << x[1] << std::endl;
}