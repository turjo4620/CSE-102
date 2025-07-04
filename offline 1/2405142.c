#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int level = 0;
    for (int i = 1; i <= n; i++)
    {
        int point = 0, sum = 0, altsum = 0, evensum = 0, oddsum = 0, a, prime = 0, tempsum = 0, palindrome = 0, harmonic = 0, balanced = 0;
        scanf("%d", &a);
        int m;
        for (int m = 1; m <= a; m++)
        {
            int b;
            scanf("%d", &b);
            sum = sum + b;
            if (m % 2 == 0)
            {
                altsum = altsum - b;
            }
            else
            {
                altsum = altsum + b;
            }
            if (m % 2 == 0)
            {
                evensum = evensum + b;
            }
            else
            {
                oddsum = oddsum + b;
            }
        }
        int count = 0;
        if (sum > 1)
        {
            for (int t = 2; t < sum; t++)
            {
                if (sum % t == 0)
                {
                    count++;
                    break;
                }
            }
            if (count == 0)
            {
                prime = 1;
                point = point + 5;
            }
        }
        int reverse = 0;
        tempsum = sum;
        while (tempsum != 0)
        {
            reverse = reverse * 10 + (tempsum % 10);
            tempsum = tempsum / 10;
        }
        if (reverse == sum)
        {
            palindrome = 1;
            point = point + 3;
        }
        if (altsum % 7 == 0)
        {
            harmonic = 1;
            point = point + 4;
        }
        if (oddsum == evensum)
        {
            balanced = 1;
            point = point + 2;
        }
        level = level + point;
        int checker = prime + palindrome + harmonic + balanced;
        if (checker == 4)
        {
            printf("Row %d: ULTRA - Energy Level %d", i, point);
        }
        else if (checker == 3)
        {
            printf("\nRow %d: HIGH - Energy Level %d", i, point);
        }
        else if (checker == 2)
        {
            printf("\nRow %d: MEDIUM - Energy Level %d", i, point);
        }
        else if (checker == 1)
        {
            printf("\nRow %d: LOW - Energy Level %d", i, point);
        }
        else
        {
            printf("\nRow %d: INACTIVE - Energy Level %d", i, point);
        }
    }
    printf("\nTotal Energy : %d", level);
    return 0;
}