#include <stdio.h>
#include <stdlib.h>
#include "../include/conio2.h"
#include "../include/rlyres.h"

int main()
{
    int e, v, p;
    char *h;
    add_trains();
    int choice;
    while (1)
    {
        choice = enterchoice();
        if (choice == 9)
            exit(0);
        switch (choice)
        {
        case 1:
            view_trains();
            break;
        case 2:
            clrscr();
            Passenger *ptr = get_passenger_details();

            if (ptr != NULL)
            {
                e = book_ticket(*ptr);
                if (e == -1)
                {
                    clrscr();
                    textcolor(RED);
                    printf("Booking failed! Seats are Filled");
                }
            }
            getch();
            clrscr();
            break;
        case 3:
        qwe:
            e = accept_ticket_no();
            if (e == 0)
            {
                clrscr();
                break;
            }
            int x = check_ticket_no(e);
            if (x == -1)
            {
                textcolor(RED);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter Positive Ticket Number!!");
                getch();
                goto qwe;
            }
            if (x == 0)
            {
                textcolor(RED);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nTicket Not Present!!!");
                getch();
                goto qwe;
            }
            if (x == 1)
                view_ticket(e);
            getch();
            clrscr();
            break;
        case 4:
            h = accept_mob_no();
            if (h == NULL)
            {
                clrscr();
                break;
            }
            int *t;
            t = get_ticket_no(h);
            if (t != 0)
            {
                printf("\n\nTickets associated with this number are :-\n");
                for (int i = 0; *(t + i) != -1; i++)
                    printf("\n    Ticket Number - %d", *(t + i));
            }
            getch();
            clrscr();
            break;
        case 5:
            clrscr();
            view_all_bookings();
            getch();
            clrscr();
            break;
        case 6:
            clrscr();
            h = accept_train_no();
            view_bookings(&h);
            break;
        case 7:
            clrscr();
            e = accept_ticket_no();
            p = check_ticket_no(e);
            v = cancel_ticket(e);
            if (p == 0)
            {
                textcolor(RED);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nTicket Not Found!!!");
            }
            if (v == -1)
                printf("File Not Present!!!");
            if (v == 1)
            {
                gotoxy(1, 25);
                textcolor(RED);
                printf("Your Ticket Has Been Cancelled!!!");
            }
            getch();
            clrscr();
            break;
        case 8:
            clrscr();
            h = accept_train_no();
            p = check_train_no(h);
            if (p == 1)
            {
                cancel_train(h);
                textcolor(RED);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nTrain has been cancelled!!");
                getch();
            }
            if (p == 0)
            {
                textcolor(RED);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWrong Train Number");
                getch();
            }
            clrscr();
            break;
        default:
        {
            textcolor(LIGHTRED);
            printf("Wrong choice! Try Again");
            getch();
            clrscr();
        }
        }
    }
    return 0;
}
