#include <stdio.h>

int main() {
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
    int s[10], fno[10][20];  // Page sizes and frame numbers for processes

    printf("\nEnter the memory size: ");
    scanf("%d", &ms);

    printf("\nEnter the page size: ");
    scanf("%d", &ps);

    nop = ms / ps;  // Total number of pages available in memory
    printf("\nThe number of pages available in memory is: %d\n", nop);

    printf("\nEnter the number of processes: ");
    scanf("%d", &np);

    rempages = nop;  // Remaining pages to allocate

    for (i = 0; i < np; i++) {
        printf("\nEnter the number of pages required for p[%d]: ", i + 1);
        scanf("%d", &s[i]);

        if (s[i] > rempages) {
            printf("\nMemory is Full\n");
            break;
        }
        rempages -= s[i];

        printf("\nEnter page table for p[%d] (frame numbers):\n", i + 1);
        for (j = 0; j < s[i]; j++) {
            printf("Frame %d: ", j);
            scanf("%d", &fno[i][j]);
        }
    }

    printf("\nEnter Logical Address to find Physical Address\n");
    printf("Enter process number, page number, and offset: ");
    scanf("%d %d %d", &x, &y, &offset);

    if (x > np || x <= 0 || y >= s[x - 1] || offset >= ps) {
        printf("\nInvalid Process, Page Number, or Offset\n");
    } else {
        pa = fno[x - 1][y] * ps + offset;  // Calculate physical address
        printf("\nThe Physical Address is: %d\n", pa);
    }

    return 0;
}
