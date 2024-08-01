/**
 * Question: Is there a way to get random number from a stream of integers?
 * Yes. We create a reserviour of size 1 (single element).
 * We iterate over the stream and for each element we have a probability of 1/i to replace the element in the reserviour.
 * This is because the probability of not replacing the element is (i-1)/i and the probability of replacing the element is 1/i.
 * So the probability of not replacing the element after i iterations is (i-1)/i * (i-2)/i-1 * ... * 1/2 = 1/i.
 *
 * Ref: https://www.youtube.com/watch?v=A1iwzSew5QY
 * Que: https://leetcode.com/problems/linked-list-random-node/
 */

#include <bits/stdc++.h>

using namespace std;

int findRandom(vector<int> arr)
{
    int reservoir, len = 0;

    reservoir = arr[0];
    len = 1;

    while (len < arr.size())
    {
        // probability of replacing charachter in reservoir is 1/len
        // Assuming rand() produces int upto infinity
        if (rand() % len == 0)
        {
            reservoir = arr[len];
        }
        len++;
    }

    return reservoir;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Radom num from inf list is " << findRandom(arr);
}
