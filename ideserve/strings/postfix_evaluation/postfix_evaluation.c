#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int evaluate_post_fix(char *, int);

char **stack_ptr;
int stack_index = -1;

int main()
{
    int result, exp_len;
    char exp[] = "20 2 * 2 / 16 + 10 - 5 +";
    // initilization of stack
    stack_ptr = (char **) malloc(sizeof(char *) * 100);
    exp_len = strlen(exp);
    result = evaluate_post_fix(exp, exp_len);
    printf("Result = %d\n", result);
    return 0;
}

push(char *data)
{
    char *temp;
    temp = (char *) malloc(sizeof(char) * strlen(data));
    if(temp == NULL){
        printf("No Mem");
        return;
    }
    strcpy(temp, data);
    *(stack_ptr + (++stack_index)) = temp;
}

char *pop()
{
    char *data;
    data = *((stack_ptr) + (stack_index));
    stack_index--;
    return data;
}

int chk_for_operand_or_operator(char *data)
{
    // Return 0 for oprand and 1 for operator
    if(*data == '*' || *data == '+' || *data == '-' || *data == '/' || *data == '^'){
        return 1;
    }else{
        return 0;
    }
}

char *eval(char *data1, char *data2, char *str_data)
{
    int result;
    char *result_str;
    result_str = (char *) malloc(sizeof(char) * 16);
    memset(result_str, 0x00, 16);
    switch(*str_data){
        case '*':
            result = atoi(data1) * atoi(data2);
            break;
        case '/':
            result = atoi(data1) / atoi(data2);
            break;
        case '+':
            result = atoi(data1) + atoi(data2);
            break;
        case '-':
            result = atoi(data1) - atoi(data2);
            break;
        case '^':
            result = atoi(data1) ^ atoi(data2);
            break;
    }
    sprintf(result_str, "%d", result);
    return result_str;
}

int evaluate_post_fix(char *exp, int exp_len)
{
    int result = 0, i, ret_val;
    char *str_data, *data1, *data2, *temp_result;
    str_data = strtok(exp, " ");
    ret_val = chk_for_operand_or_operator(str_data);
    if(ret_val){
        //Oprator PoP two oprand and perform the operation
        //PoP the result to the stack
        data2 = pop();
        data1 = pop();
        temp_result = eval(data1, data2, str_data);
        push(temp_result);
    }else{
        // Operand PUSH it to the stack
        push(str_data);
    }
    while(str_data = strtok(NULL, " ")){
        ret_val = chk_for_operand_or_operator(str_data);
        if(ret_val){
            //Oprator PoP two oprand and perform the operation
            //PoP the result to the stack
            data2 = pop();
            data1 = pop();
            temp_result = eval(data1, data2, str_data);
            push(temp_result);
        }else{
            // Operand PUSH it to the stack
            push(str_data);
        }
    }
    // POP result from the stack and return it
    return atoi(pop());
}
