#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LOGIN_FILE "usr_logins.txt"

// Train structure
typedef struct Train {
    int train_no;
    char name[50];
    char src[30];
    char dest[30];
    int seats;
    struct Train *next;
} Train;

Train *head = NULL;

// Function prototypes
void menu1();
void signup();
int validatePassword(char *);
void signin();
void addTrain(int, char *, char *, char *, int);
void printTrains();
void reserveTicket();
void cancelTicket();
void menu2();

int main() 
{
    // Add some default trains 
    addTrain(12701, "Hussain Sagar Exp", "HYD", "MUM", 5);
    addTrain(12702, "Godavari Exp", "HYD", "VSKP", 5);
    addTrain(12703, "Charminar Exp", "HYD", "CHN", 5);
    menu1();
    return 0;
}

// MENU-1
void menu1() {
    int opt;
    printf("\n------------------MENU-1------------------\n");
    printf("1. Sign-Up\n2. Sign-In\nChoose: ");
    scanf("%d", &opt);

    if (opt == 1)
        signup();
    else if (opt == 2)
        signin();
    else {
        printf("Invalid Option!\n");
        menu1();
    }
}

// Sign-Up
void signup() {
    char user[30], pass[30];
    FILE *fp = fopen(LOGIN_FILE, "a+");

    printf("Enter Username: ");
    scanf("%s", user);

    // Username uniqueness check
    char u[30], p[30];
    rewind(fp);
    while (fscanf(fp, "%s %s", u, p) != EOF) {
        if (strcmp(u, user) == 0) {
            printf("Username already exists! Try again.\n");
            fclose(fp);
            signup();
            return;
        }
    }

    int attempts = 0;
    do {
        printf("Enter Password: ");
        scanf("%s", pass);

        if (!validatePassword(pass))
            printf("Weak Password! Must contain 8 chars, upper, lower, number, special!\n");

        else break;

        attempts++;
        if (attempts == 5) {
            printf("TIME OUT! Sign-Up again.\n");
            fclose(fp);
            signup();
            return;
        }
    } while (1);

    fprintf(fp, "%s %s\n", user, pass);
    printf("Sign-Up Successful! Now login.\n");
    fclose(fp);

    // Add some default trains
    //addTrain(12701, "Hussain Sagar Exp", "HYD", "MUM", 5);
    //addTrain(12702, "Godavari Exp", "HYD", "VSKP", 5);
    //addTrain(12703, "Charminar Exp", "HYD", "CHN", 5);

    signin();
}

// Password validation
int validatePassword(char *pass) {
    int len = strlen(pass);
    if (len < 8) return 0;

    int u = 0, l = 0, d = 0, s = 0;
    for (int i = 0; pass[i]; i++) {
        if (isupper(pass[i])) u = 1;
        else if (islower(pass[i])) l = 1;
        else if (isdigit(pass[i])) d = 1;
        else s = 1;
    }
    return u && l && d && s;
}

// Sign-In
void signin() {
    char user[30], pass[30], u[30], p[30];
    FILE *fp = fopen(LOGIN_FILE, "r");

    printf("Enter Username: ");
    scanf("%s", user);
    printf("Enter Password: ");
    scanf("%s", pass);

    int found = 0;
    while (fscanf(fp, "%s %s", u, p) != EOF) {
        if (strcmp(u, user) == 0 && strcmp(p, pass) == 0) {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (found) {
        printf("Login Successful!\n");
        menu2();
    } else {
        printf("Login Failed! 3 attempts only!\n");
        static int attempts = 1;
        if (attempts < 3) {
            attempts++;
            signin();
        } else {
            printf("Max attempts reached! Try after 5 mins.\n");
            exit(0);
        }
    }
}

// MENU-2
void menu2() {
    char opt;
    printf("\n------------------MENU-2------------------\n");
    printf("R. Reserve Ticket\nC. Cancel Ticket\nB. Train List\nQ. Quit\nChoose: ");
    scanf(" %c", &opt);

    switch (toupper(opt)) {
        case 'R': reserveTicket(); break;
        case 'C': cancelTicket(); break;
        case 'B': printTrains(); break;
        case 'Q': exit(0);
        default: printf("Invalid!\n"); menu2();
    }
}

// Add train to SLL
void addTrain(int no, char *name, char *s, char *d, int seats) {
    Train *new = malloc(sizeof(Train));
    new->train_no = no;
    strcpy(new->name, name);
    strcpy(new->src, s);
    strcpy(new->dest, d);
    new->seats = seats;
    new->next = head;
    head = new;
}

// Print trains
void printTrains() {
    printf("\nAvailable Trains:\n");
    Train *t = head;
    while (t) {
        printf("%d | %s | %s → %s | Seats: %d\n", 
            t->train_no, t->name, t->src, t->dest, t->seats);
        t = t->next;
    }
    menu2();
}

// Reserve ticket
void reserveTicket() {
    int tno, seats;
    printf("Enter Train Number: ");
    scanf("%d", &tno);
    printf("Enter No.of seats: ");
    scanf("%d", &seats);

    Train *t = head;
    while (t && t->train_no != tno)
        t = t->next;

    if (!t) {
        printf("Train Not Found!\n");
        menu2();
        return;
    }

    if (t->seats >= seats) {
        t->seats -= seats;
        printf("Booked %d seats Successfully!\n", seats);
    } else {
        printf("Only %d seats available! Cannot book %d seats!\n", t->seats, seats);
    }

    menu2();
}

// Cancel ticket
void cancelTicket() {
    int tno, seats;
    printf("Enter Train Number to cancel: ");
    scanf("%d", &tno);
    printf("Enter seats to cancel: ");
    scanf("%d", &seats);

    Train *t = head;
    while (t && t->train_no != tno)
        t = t->next;

    if (!t) {
        printf("Train Not Found!\n");
        menu2();
        return;
    }

    t->seats += seats;
    printf("%d seats Cancelled & Updated!\n", seats);
    menu2();
}

