#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void boot_anim() {
    for(int i = 0; i < 4; i++)
    {
        void boot_frame_1();
        sleep(2);
        system("clear");
        void boot_frame_2();
        sleep(2);
        system("clear");
        void boot_frame_3();
        sleep(2);
        system("clear");
    }
}


void boot_frame_1() {
    printf("\n");
    printf("\t\t\t\t>> >> >> >> >>\n");
    printf("\t\t\t\t >  >  >  >  >\n");
    printf("\t\t\t\t>  >  >  >  > \n");
}
void boot_frame_2() {
    printf("\n");
    printf("\t\t\t\t >  >  >  >  >\n");
    printf("\t\t\t\t >  >  >  >  >\n");
    printf("\t\t\t\t> >> >>  > >> \n");
}
void boot_frame_3() {
    printf("\n");
    printf("\t\t\t\t>  >  >  >  > \n");
    printf("\t\t\t\t>>  > >>  > >>\n");
    printf("\t\t\t\t>  >  >  >  > \n");
}
