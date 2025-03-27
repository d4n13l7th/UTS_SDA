#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h> //disini kami menggunakan bool untuk memudahkan eksekusi kode true/false

#define MAX 100 //maksimum stack dan array
#define OPERAND(ch) ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) //apakah ch merupakan operand?

//struktur datastack
typedef struct {
    int top;
    char *data[MAX];
} Stack;

void inisialisasi(Stack *s) {
    s->top = -1; //buat stack kosong
}

bool cek_penuh(Stack *s) {
    return (s->top == MAX - 1);
}

bool cek_kosong(Stack *s) {
    return (s->top == -1);
}

//operator yang mau difungsikan untuk konversi
void infikskepostfiks(char infix[], char postfix[]);
void infikskeprefiks(char infix[], char prefix[]);
void postfikskeinfiks(char postfix[], char infix[]);
void postfikskeprefiks(char postfix[], char prefix[]);
void prefikskeinfiks(char prefix[], char infix[]);
void prefikskepostfiks(char prefix[], char postfix[]);

//kinerja stack (kode dieksekusi dengan fungsi bool)
void push(Stack *s, char *value) {
    if (cek_penuh(s)) {
        printf("Stack sudah mencapai batas maksimum!\n");
        return;
    }
    s->data[++(s->top)] = value;
}

char* pop(Stack *s) {
    if (cek_kosong(s)) {
        printf("Anda belum memasukkan data dalam stack!\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

char* peek(Stack *s) {
    if (cek_kosong(s)) {
        printf("Anda belum memasukkan data dalam stack!\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top];
}

//fungsi balik string untuk menjalankan operasi konversi antar fungsi
void balik_string(char str[]) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
} //jika inputnya operator

int prioritas(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
} //"+" dan "-" lebih diutamakan dari "*" dan "/"

//fungsi utama
int main() {
    int pilihan;
    char ekspresi[MAX], hasil[MAX];

    printf("\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
    printf("|SELAMAT DATANG DI KALKULATOR KONVERSI EKSPRESI ARITMATIKA!|\n");
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\n");

    while(1){
    printf("==========================\n");
    printf("| PILIH MENU KALKULATOR! |\n");
    printf("==========================\n");
    printf("|  1. Infix ke Postfix   |\n");
    printf("|  2. Postfix ke Infix   |\n");
    printf("|  3. Infix ke Prefix    |\n");
    printf("|  4. Prefix ke Infix    |\n");
    printf("|  5. Postfix ke Prefix  |\n");
    printf("|  6. Prefix ke Postfix  |\n");
    printf("|  7. Keluar             |\n");
    printf("==========================\n");
    printf("\nPilihan Anda:  ");
    scanf("%d", &pilihan);
    getchar(); // Buang '\n' agar tidak mengganggu fgets();
    
    switch (pilihan) {

        case 1:
        printf("\nMasukkan infiks: ");
        fgets(ekspresi, MAX, stdin);
        ekspresi[strcspn(ekspresi, "\n")] = 0;
        
        if (pilihan == 1) {
            infikskepostfiks(ekspresi, hasil);
            printf("\nPostfiksnya adalah: %s\n", hasil);
        }
        printf("Tekan enter untuk lanjut\n");
        scanf("%c", &pilihan);
        break;

        case 2:
        printf("\nMasukkan infiks: ");
        fgets(ekspresi, MAX, stdin);
        ekspresi[strcspn(ekspresi, "\n")] = 0;   

        if (pilihan == 2) {
            infikskeprefiks(ekspresi, hasil);
            printf("\nPrefiksnya adalah: %s\n", hasil);
        }
        printf("Tekan enter untuk lanjut\n");
        scanf("%c", &pilihan);
        break;

        case 3:
        printf("\nMasukkan postfiks: ");
        fgets(ekspresi, MAX, stdin);
        ekspresi[strcspn(ekspresi, "\n")] = 0;

        if (pilihan == 3) {
            postfikskeinfiks(ekspresi, hasil);
            printf("\nInfiksnya adalah: %s\n", hasil);
        }
        printf("Tekan enter untuk lanjut\n");
        scanf("%c", &pilihan);
        break;

        case 4:
        printf("\nMasukkan postfiks: ");
        fgets(ekspresi, MAX, stdin);
        ekspresi[strcspn(ekspresi, "\n")] = 0;

        if (pilihan == 4) {
            postfikskeprefiks(ekspresi, hasil);
            printf("\nPrefiksnya adalah: %s\n", hasil);
        }
        printf("Tekan enter untuk lanjut\n");
        scanf("%c", &pilihan);
        break;

        case 5:
        printf("Masukkan prefiks: ");
        fgets(ekspresi, MAX, stdin);
        ekspresi[strcspn(ekspresi, "\n")] = 0;

        if (pilihan == 5) {
            prefikskeinfiks(ekspresi, hasil);
            printf("\nInfiksnya adalah: %s\n", hasil);
        }
        printf("Tekan enter untuk lanjut\n");
        scanf("%c", &pilihan);
        break;

        case 6:
        printf("Masukkan prefiks: ");
        fgets(ekspresi, MAX, stdin);
        ekspresi[strcspn(ekspresi, "\n")] = 0;

        if (pilihan == 6) {
            prefikskepostfiks(ekspresi, hasil);
            printf("\nPostfiksnya adalah: %s\n", hasil);
        }
        printf("Ketik enter untuk lanjut\n");
        scanf("%c", &pilihan);
        break;

        case 7://keluar
         printf("\nTerimakasih sudah menggunakan kalkulator kami, semoga membantu :)\n ");
         return 0;

        default:
            printf("Pilihan tidak valid!\n");
            break;
    }
    
}
return 0;
}

void infikskepostfiks(char infix[], char postfix[]) {
    Stack s; 
    inisialisasi(&s); //mengosongkan stack sebelum digunakan
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (OPERAND(ch)) {
            //langsung masukkan ke postfiks jika input operand
            postfix[j++] = ch;
        } else if (ch ==' ') { //langsung skip jika spasi
            i++; 
            continue;
        } else if (ch == '(') { //karena '(' akan digunakan, push ke stack
            char *parenthesis = (char *)malloc(2 * sizeof(char));
            sprintf(parenthesis, "%c", ch);
            push(&s, parenthesis);
        } else if (ch == ')') {  //pop semua operator hingga menemukan '(' 
            while (!cek_kosong(&s) && strcmp(peek(&s), "(") != 0) {
                char *op = pop(&s);
                postfix[j++] = op[0]; //masukkan operator ke postfiks
                free(op); 
            }
            char *leftParenthesis = pop(&s); //pop '('1 dari stack
            free(leftParenthesis); 
        } else { //jika karakter adalah operator, pop operator dengan prioritas lebih tinggi atau sama dari stack
            while (!cek_kosong(&s) && prioritas(peek(&s)[0]) >= prioritas(ch)) {
                char *op = pop(&s);
                postfix[j++] = op[0]; //masukkan operator ke postfiks
                free(op); 
            }
            //push operator
            char *operator = (char *)malloc(2 * sizeof(char));
            sprintf(operator, "%c", ch);
            push(&s, operator);
        }
        i++; 
    }

    //pop semua sisa operator dari stack,lalu masukkan hasil dari pop push tadi ke postfiks
    while (!cek_kosong(&s)) {
        char *op = pop(&s);
        postfix[j++] = op[0]; 
        free(op); 
    }

    postfix[j] = '\0'; //tambahkan null terminator agar valid sebagai string C
}

void infikskeprefiks(char infix[], char prefix[]) {
    Stack s;
    inisialisasi(&s);
    char temp[MAX]; 
    balik_string(infix); //balik string infiks
    infikskepostfiks(infix, temp); //konversi infiks yang sudah dibalik ke postfiks
    balik_string(temp); //balik hasil postfiks menjadi prefiks
    strcpy(prefix, temp); //hasil akhir disalin ke variabel prefix
}

void postfikskeinfiks(char postfix[], char infix[]) {
    Stack s;
    inisialisasi(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i]; //loop berjalan selama belum mencapai akhir string postfiks

        if (OPERAND(ch)) { //jika karakter adalah operand push
            char *operand = (char *)malloc(2 * sizeof(char)); 
            sprintf(operand, "%c", ch); //buat string dari operand (karena stack menyimpan string, bukan char tunggal)
            push(&s, operand); //push operand ke stack
        } else if (ch ==' ') {
            continue;
        } else if (operator(ch)) { //jika karakter adalah operator
            //pop 2 operand dari stack, operand 2 terlebih dahulu karena stack LIFO - Last in First out
            char *op2 = pop(&s); //operand 2
            char *op1 = pop(&s); //operand 1
            char *newExpr = (char *)malloc((strlen(op1) + strlen(op2) + 4) * sizeof(char));
            sprintf(newExpr, "(%s%c%s)", op1, ch, op2); //menggabungkan operand dengan operator menjadi ekspresi infiks dalam format (operand1 operator operand2)
            push(&s, newExpr); //push hasil infiks kembali ke stack
            free(op1);
            free(op2); //membebaskan memori operand lama untuk menghemat memori
        }
    }
     //setelah eksekusi seluruh ekspresi, stack hanya berisi hasil akhir dalam bentuk infiks
    strcpy(infix, pop(&s)); //pindahkan hasil ke variabel infix
}

void postfikskeprefiks(char postfix[], char prefix[]) {
    Stack s;
    inisialisasi(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (OPERAND(ch)) {
            char *operand = (char *)malloc(2 * sizeof(char)); 
            sprintf(operand, "%c", ch)
            push(&s, operand); 
        } else if (ch ==' ') {
            continue;
        } else if (operator(ch)) {
            char *op2 = pop(&s); //2
            char *op1 = pop(&s); //1
            char *newExpr = (char *)malloc((strlen(op1) + strlen(op2) + 2) * sizeof(char)); //alokasi memori untuk prefiks baru
            sprintf(newExpr, "%c%s%s", ch, op1, op2); //gabungkan operator dengan operand dalam format prefiks (operator + operand1 + operand2)     
            push(&s, newExpr); //push hasil prefiks kembali ke stack
            free(op1);
            free(op2);
        }
    }
    strcpy(prefix, pop(&s)); //pindahkan hasil ke variabel prefiks
}

void prefikskeinfiks(char prefix[], char infix[]) {
    Stack s;
    inisialisasi(&s);

    int length = strlen(prefix); //menghitung panjang ekspresi prefix agar dapat diproses dari belakang

    for (int i = length - 1; i >= 0; i--) { //loop berjalan mundur, dari kanan ke kiri, karena ekspresi prefiks
        char ch = prefix[i];

        if (OPERAND(ch)) { 
            char *operand = (char *)malloc(2 * sizeof(char)); 
            sprintf(operand, "%c", ch); 
            push(&s, operand);
        } else if (ch ==' ') {
            continue;
        } else if (operator(ch)) {
            char *op1 = pop(&s);
            char *op2 = pop(&s);
            char *newExpr = (char *)malloc((strlen(op1) + strlen(op2) + 4) * sizeof(char));
            sprintf(newExpr, "(%s%c%s)", op1, ch, op2); //gabungkan operator dengan operand dalam format infiks        
            push(&s, newExpr); //push hasil ekspresi ke dalam stack
            free(op1);
            free(op2);
        }
    }
    strcpy(infix, pop(&s)); //pindahkan hasil ke variabel infiks
}

void prefikskepostfiks(char prefix[], char postfix[]) {
    Stack s;
    inisialisasi(&s);

    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (OPERAND(ch)) {
            char *operand = (char *)malloc(2 * sizeof(char));
            sprintf(operand, "%c", ch);
            push(&s, operand);
        } else if (ch ==' ') {
            continue;
        } else if (operator(ch)) {
            char *op1 = pop(&s);
            char *op2 = pop(&s);
            char *newExpr = (char *)malloc((strlen(op1) + strlen(op2) + 2) * sizeof(char));
            sprintf(newExpr, "%s%s%c", op1, op2, ch);
            push(&s, newExpr);
            free(op1);
            free(op2);
        }
    }
    strcpy(postfix, pop(&s)); //pindahkan hasil ke variabel postfiks
}
