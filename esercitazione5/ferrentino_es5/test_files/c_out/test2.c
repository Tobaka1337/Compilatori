#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <malloc.h> 
#include <math.h> 
#include <errno.h> 
#include <limits.h> 
#include <stdbool.h> 

char* concat_strings(char* string1, char* string2);
void read_int(int *num); 
void read_float(float *num); 
void read_bool(bool *b); 
void read_char(char *c); 
void read_string(char **string);
char* convert_int_to_string(int num); 
char* convert_real_to_string(float num); 
char* convert_char_to_string(char c); 
char* convert_bool_to_string(bool b); 
void mainFunction();
bool isInteger(float a);
void swap(float* a, float* b);
int Fibonacci(int n);


char* concat_strings(char* string1, char* string2){
    size_t len = strlen(string1) + strlen(string2);
    char * buffer = (char *)malloc(len + 1);
    buffer[0] = '\0';
    buffer = strncat(buffer, string1, strlen(string1));
    buffer = strncat(buffer, string2, strlen(string2));
    return buffer;
}

void read_int(int *num){
    long a; 
    char *buf = ""; 
    read_string(&buf); 
    errno = 0; 
    char *endptr; 
    a = strtol(buf, &endptr, 10); 
    if (errno == ERANGE){ 
        fprintf(stderr, "[!] Invalid Input\n"); 
        return; 
    } 
    if (endptr == buf){ 
        fprintf(stderr, "[!] Invalid Input\n"); 
        return; 
    } 
    if (*endptr && *endptr != '\n'){ 
        fprintf(stderr, "[!] Invalid Input\n"); 
        return; 
    } 
    if (a > INT_MAX || a < INT_MIN){ 
        fprintf(stderr, "[!] Invalid Input\n"); 
        return; 
    } 
    *num = (int) a; 
}

void read_float(float *num){ 
    float a; 
    char *buf = ""; 
    read_string(&buf); 
    errno = 0; 
    char *endptr; 
    a = strtof(buf, &endptr); 
    if (errno == ERANGE){ 
        fprintf(stderr, "[!] Invalid Input\n"); 
        return; 
    } 
    if (endptr == buf){ 
        fprintf(stderr, "[!] Invalid Input\n"); 
        return; 
    } 
    if (*endptr && *endptr != '\n'){ 
        fprintf(stderr, "[!] Invalid Input\n"); 
        return; 
    } 
    *num = (float) a; 
} 

void read_bool(bool *b){ 
    char *buf = ""; 
    read_string(&buf); 
    if(strcmp(buf, "true") == 0){ 
        *b = true; 
        return; 
    } 
    if(strcmp(buf, "false") == 0){ 
        *b = false; 
        return; 
    } 
    fprintf(stderr, "[!] Invalid Input\n");} 

void read_char(char *c){ 
    char *buf = ""; 
    read_string(&buf); 
    if(strlen(buf) != 1){ 
        fprintf(stderr, "[!] Invalid Input\n"); 
        return; 
    } 
    *c = buf[0]; 
} 

void read_string(char **string){ 
    int ch; 
    char buffer[4096]; 
    if (fgets(buffer, 4096, stdin) == NULL){ 
        fprintf(stderr, "[!] Invalid Input\n"); 
        return; 
    } 
    if(strstr(buffer, "\n") == NULL){ 
        while((ch = getchar()) != '\n' && ch != EOF); 
        buffer[4095] = '\0'; 
    } else { 
        buffer[strcspn(buffer, "\n")] = '\0'; 
    } 
    *string = strndup(buffer, strlen(buffer)); 
} 

char* convert_int_to_string(int num){ 
    char* str = (char *) malloc(sizeof(char) * 20); 
    snprintf(str, sizeof str, "%d", num); 
    return str; 
} 

char* convert_real_to_string(float num){ 
    char* str = (char *) malloc(sizeof(char) * 20); 
    snprintf(str, sizeof str, "%f", num); 
    return str; 
} 

char* convert_char_to_string(char c){ 
    char* str = (char *) malloc(sizeof(char) * 2); 
    str[0] = c; 
    str[1] = '\0'; 
    return str; 
} 

char* convert_bool_to_string(bool b){ 
    if(b) { 
        return "true"; 
    } else { 
        return "false"; 
    } 
} 

void main(){


mainFunction();
}

void mainFunction(){
int flag;

int option;

flag = 1;
option = 0;

while((flag==1)){

printf("%s", "Scegli l'operazione da eseguire:");
printf("\n");
printf("%s", "1. Somma di due numeri");
printf("\n");
printf("%s", "2. Moltiplicazione di due numeri utilizzando la somma");
printf("\n");
printf("%s", "3. Divisione intera fra due numeri positivi");
printf("\n");
printf("%s", "4. Elevamento a potenza");
printf("\n");
printf("%s", "5. Successione di Fibonacci");
printf("\n");
printf("%s", "Input: ");
read_int(&option);
while((option<1||option>5)){

printf("%s", "Seleziona una delle operazioni presenti nella lista: ");
read_int(&option);
}
if((option==1)){
float a;
float b;


printf("%s", "Inserisci il primo numero: ");
read_float(&a);
printf("%s", "Inserisci il secondo numero: ");
read_float(&b);
printf("%s", "Result: ");
printf("%f", a+b);
printf("\n");
}
if((option==2)){
float a;
float b;

float acc;

acc = 0.0;

printf("%s", "Inserisci il primo numero: ");
read_float(&a);
printf("%s", "Inserisci il secondo numero: ");
read_float(&b);
if((isInteger(a)
)){

swap(&a, &b);
}
if((b<0)){

a = (-a);
b = (-b);
}
while((b>0)){

acc = acc+a;
b = b-1;
}
printf("%s", "Result: ");
printf("%f", acc);
printf("\n");
}
if((option==3)){
int a;
int b;


printf("%s", "Inserisci il primo intero (positivo): ");
read_int(&a);
while((a<0)){

printf("%s", "Gli interi devono essere POSITIVI");
printf("\n");
printf("%s", "Inserisci il primo intero (positivo): ");
read_int(&a);
}
printf("%s", "Inserisci il secondo intero (positivo): ");
read_int(&b);
while((b<0)){

printf("%s", "Gli interi devono essere POSITIVI");
printf("\n");
printf("%s", "Inserisci il primo intero (positivo): ");
read_int(&a);
}
printf("%s", "Result: ");
printf("%d", a/b);
printf("\n");
}
if((option==4)){
float a;
float b;


printf("%s", "Inserisci il primo numero: ");
read_float(&a);
printf("%s", "Inserisci il secondo numero: ");
read_float(&b);
printf("%s", "Result: ");
printf("%f", (float)pow((double)a,(double)b));
printf("\n");
}
if((option==5)){
int n;


printf("%s", "Inserisci un numero: ");
read_int(&n);
printf("%s", "Result: ");
printf("%d", Fibonacci(n)
);
printf("\n");
}
printf("%s", "Vuoi continuare? si (1) no (0) ");
read_int(&flag);
while((flag!=0&&flag!=1)){

printf("%s", "Valore non accettato! Inserire 1 per continuare o 0 per terminare: ");
read_int(&flag);
}
}
}

bool isInteger(float a){

a = a*a;
while((a>=1)){

a = a-1;
}
return a==0;
}

void swap(float* a, float* b){
float tmp;

tmp = *a;

*a = *b;
*b = tmp;
}

int Fibonacci(int n){

if((n<1)){

return 0;
}
if((n==1)){

return 1;
}
return Fibonacci(n-1)
+Fibonacci(n-2)
;
}


